[![C](https://img.shields.io/badge/ISO_C17-A8B9CC?logo=c&logoColor=fff)][C17]
[![IEEE](https://img.shields.io/badge/POSIX.1&#8209;2024-00629B?logo=ieee&logoColor=fff)][POSIX.1-2024]
[![Homebrew](https://img.shields.io/badge/Homebrew-tap-2AAB47?logo=homebrew&logoColor=959DA5&labelColor=2B3137)](https://github.com/Neved4/homebrew-tap/blob/main/Formula/center.rb)

# center - Centers text from stdin! 🛠️

###### Originally by [Lizzy Fleckenstein][LizzyFleckenstein03/center] 🤍

[`center`] reads input from `stdin`, calculates the width of each line
(considering multibyte characters), and center-aligns the text within the
terminal window.

### Highlights

- **Terminal size detection**: Adjusts text to fit the terminal width.
- **Multibyte support**: Handles Unicode characters correctly.
- **Text centering**: Prints each line centered within the terminal.
- **Error handling**: Graceful handling of system call failures.

## Getting Started

### Prerequisites

If you are building [`center`], you'll need:

- A C compiler that supports [C99] or later.

### Installing

If you have [Homebrew] installed, just run:

```sh
brew install Neved4/homebrew-tap/center
```

### Implementation

[`center`] operates as follows:

1. Opens `/dev/tty` to get the terminal width.
2. Reads input line-by-line.
3. Calculates character width (supporting multibyte characters).
4. Prints each line centered in the terminal.

### Examples

Below is an example of how the [`center`] command works in practice:

```console
$ echo 'Hello World!' | center
                                  Hello World!
```

## Compatibility

Runs on _**Linux**_, _**macOS**_ and _**\*BSD**_ systems on [`x86_64`] and
[`arm64`], and compiles with [`zig`], [`clang`], [`gcc`], [`tcc`] and any other
compiler that supports [C99] or later.

## Standards

[`center`] is compatible with [POSIX.1-2024][][^1] as well as the [C23][][^2] standard.

## See Also

For further reference and related tools, check out the following:

- [LizzyFleckenstein03/center]

## License

[`center`] is licensed under the terms of the [GPLv3 License].

See the [LICENSE](LICENSE) file for details.

[`arm64`]: https://en.wikipedia.org/wiki/AArch64
[`center`]: https://github.com/Neved4/center
[`clang`]: https://clang.llvm.org/
[`gcc`]: https://gcc.gnu.org/
[`tcc`]: https://bellard.org/tcc/
[`x86_64`]: https://en.wikipedia.org/wiki/X86-64
[`zig`]: https://ziglang.org/
[C99]: https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf
[C17]: https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2310.pdf
[C23]: https://www.open-std.org/jtc1/sc22/wg14/www/docs/n3220.pdf
[GPLv3 License]: https://www.gnu.org/licenses/gpl-3.0.en.html
[Homebrew]: https://brew.sh/
[LizzyFleckenstein03/center]: https://github.com/LizzyFleckenstein03/center/blob/master/center.c
[POSIX.1-2024]: https://pubs.opengroup.org/onlinepubs/9799919799/

[^1]: _IEEE Std 1003.1-2024: Standard for Information Technology
    — Portable Operating System Interface (POSIX®)_, \
    ISO/IEC DIS 9945. URL: https://pubs.opengroup.org/onlinepubs/9799919799/
[^2]: _ISO/IEC 9899: Standard for Information Technology
    — Programming languages — C_, ISO/IEC 9899:2023. \
    URL: https://www.open-std.org/jtc1/sc22/wg14/www/docs/n3096.pdf
