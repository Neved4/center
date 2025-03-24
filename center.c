#include <fcntl.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include <wchar.h>

int termwidth() {
	int tty_fd = open("/dev/tty", O_RDWR);
	if (tty_fd < 0) {
		perror("open");
		return -1;
	}

	struct winsize ws;
	if (ioctl(tty_fd, TIOCGWINSZ, &ws) < 0) {
		perror("ioctl");
		close(tty_fd);
		return -1;
	}

	close(tty_fd);
	return ws.ws_col;
}

void fmtline(char *buf, int term_width) {
	char *ptr = buf, *last = buf;
	int str_width = 0;
	mbstate_t mbs = {0};
	size_t len = strlen(buf);

	while (len > 0) {
		wchar_t wc;
		size_t adv = mbrtowc(&wc, ptr, len, &mbs);

		if (adv == (size_t)-1 || adv == (size_t)-2) {
			perror("mbrtowc");
			return;
		}

		int width = wcwidth(wc);
		if (width > 0)
			str_width += width;

		if (*ptr == '\n' || str_width >= term_width - 12) {
			for (int i = (term_width - str_width) / 2; i > 0; i--)
				putchar(' ');

			fwrite(last, 1, ptr - last + 1, stdout);
			if (*ptr != '\n')
				putchar('\n');

			last = ptr + adv;
			str_width = 0;
		}

		ptr += adv;
		len -= adv;
	}
}

int main(void) {
	if (setlocale(LC_ALL, "") == NULL) {
		perror("setlocale");
		return EXIT_FAILURE;
	}

	int term_width = termwidth();
	if (term_width < 0)
		return EXIT_FAILURE;

	char *buf = NULL;
	size_t siz = 0;
	ssize_t len;

	while ((len = getline(&buf, &siz, stdin)) > 0)
		fmtline(buf, term_width);

	free(buf);
	return EXIT_SUCCESS;
}
