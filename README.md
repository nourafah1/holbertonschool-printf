# _printf Project

## Description
This project is a custom implementation of the printf function in C as part of the Holberton School curriculum. It handles formatted output and supports basic conversion specifiers.flags, field width, precision,
and length modifiers.This project is a custom implementation of the `printf` function in C
as part of the Holberton School curriculum. It replicates the behavior
of the standard `printf` function by handling formatted output with
various conversion specifiers, flags, field width, precision, and
length modifiers. The function writes output to stdout using a local
buffer for efficiency.## Description

This project is a custom implementation of the `printf` function in C
as part of the Holberton School curriculum. The goal is to deeply
understand how formatted output works in C by building it from scratch
without using the standard library `printf` or `sprintf`.

The function `_printf` works similarly to the original `printf` in C.
It takes a format string and a variable number of arguments, then
produces output to stdout based on the format string. The format string
can contain regular characters, which are printed as-is, and conversion
specifiers that start with `%`, which tell the function how to format
and print each argument.

### What makes this project special

### What makes this project special

Unlike the standard `printf`, this implementation uses a local buffer
of 1024 bytes to store characters before writing them to stdout. This
approach reduces the number of `write` system calls, which makes the
function more efficient. The buffer is flushed automatically when it
becomes full or when the format string ends.

This project goes beyond a basic implementation by supporting a wide
range of features that mirror the real `printf` behavior, including:

* **Custom buffer system**: Instead of calling `write` for every single
  character, we store characters in a 1024-byte buffer and flush it
  all at once. This significantly reduces the number of system calls
  and improves performance, especially when printing large amounts of text.

* **Full flag support**: We implemented all major flags including `+`,
  `-`, `0`, `#`, and space. Each flag changes the output format in a
  specific way, and multiple flags can be combined together in a single
  specifier like `%-+10d`.

* **Field width and precision**: The function correctly handles field
  width and precision for all supported specifiers. Width controls the
  minimum number of characters printed, and precision controls the
  minimum digits for integers or maximum characters for strings.

* **Dynamic width and precision with `*`**: Instead of hardcoding the
  width or precision in the format string, the user can pass them as
  arguments using `%*d` or `%.*d`. The function reads these values
  from the argument list at runtime.

* **Length modifiers**: The function handles both `l` for long integers
  and `h` for short integers across all numeric specifiers. This allows
  correct printing of values like `LONG_MIN`, `LONG_MAX`, `SHRT_MIN`,
  `SHRT_MAX`, `ULONG_MAX`, and `USHRT_MAX`.

* **Edge case handling**: Special attention was given to tricky cases
  such as printing `LONG_MIN` (which cannot simply be negated in a
  `long int`), printing `%.0d` with zero (which should print nothing),
  null string pointers (printed as `(null)`), and the interaction
  between `0` flag and precision (precision overrides the `0` flag).

* **Custom specifiers**: Beyond the standard specifiers, we added three
  custom ones: `%b` for binary output, `%r` for reversed strings, and
  `%R` for ROT13 encoded strings. These demonstrate how the specifier
  system can be extended.

* **Betty compliant code**: All code was written following the Betty
  coding style used at Holberton School. This means clean formatting,
  proper commenting, limited function length, and no more than 5
  functions per file.

* **Team collaboration**: This project was built as a two-person team
  using Git and GitHub for version control. Both members contributed
  to the implementation, testing, and documentation of the project.
Unlike the standard `printf`, this implementation uses a local buffer
of 1024 bytes to store characters before writing them to stdout. This
approach reduces the number of `write` system calls, which makes the
function more efficient. The buffer is flushed automatically when it
becomes full or when the format string ends.

### What we learned

By building this project, we gained a deep understanding of:

* How variadic functions work in C using `va_list`, `va_start`,
  `va_arg`, `va_copy`, and `va_end`
* How to parse a format string character by character
* How flags, field width, precision, and length modifiers interact
  with each other
* How to handle edge cases like `LONG_MIN`, null pointers,
  zero precision, and special characters
* How to write clean, readable, and Betty-compliant C code
* How to collaborate as a team using Git and GitHub

### Background

The `printf` function is one of the most used functions in C. It was
originally written by Dennis Ritchie and Brian Kernighan as part of
the Unix operating system. Understanding how it works internally is
an important step in becoming a strong systems programmer.

This project was completed as part of the low-level programming
curriculum at Holberton School, where students are challenged to
implement core C library functions from scratch to build a strong
foundation in systems programming.



## Requirements
- GCC compiler
- Ubuntu 20.04
- Allowed functions: write, malloc, free, etc.
* GCC compiler
* Ubuntu 20.04
* Allowed functions: `write`, `malloc`, `free`, `va_start`, `va_end`, `va_arg`
* GCC compiler
* Ubuntu 20.04 LTS
* Allowed functions: `write`, `malloc`, `free`, `va_start`, `va_end`, `va_arg`, `va_copy`
* All files compiled with: `-Wall -Wextra -Werror -pedantic -std=gnu89`
* No use of standard library `printf` or `sprintf`
* 
### General
* Allowed editors: `vi`, `vim`, `emacs`
* All files compiled on Ubuntu 20.04 LTS
* Compiled with: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`
* All files must end with a new line
* No more than 5 functions per file
* Code must follow Betty style
* Global variables are not allowed

### Header File
* All prototypes must be in `main.h`
* Header file must be include guarded

### Functions
* No use of standard library `printf` or `sprintf`
* Allowed functions and system calls:
  * `write` (unistd.h)
  * `malloc` (stdlib.h)
  * `free` (stdlib.h)
  * `va_start` (stdarg.h)
  * `va_end` (stdarg.h)
  * `va_arg` (stdarg.h)
  * `va_copy` (stdarg.h)

### Betty Style
* All code must pass Betty linter
* Run Betty check:

```bash
betty _printf.c main.h
```

### GitHub
* One project repository per group
* No cloning or forking of another student's repository
* Each team member must commit and push regularly

### Memory
* No memory leaks allowed
* All dynamically allocated memory must be freed
* Check with valgrind:

```bash
valgrind --leak-check=full ./printf
```


## Installation
Clone the repository:

```bash
git clone https://github.com/nourafah1/holbertonschool-printf.git
cd holbertonschool-printf
```

Compile all files:

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o printf
```


Clone the repository:

```bash
git clone https://github.com/nourafah1/holbertonschool-printf.git
cd holbertonschool-printf Clone the repository:

```bash
git clone https://github.com/nourafah1/holbertonschool-printf.git
cd holbertonschool-printf
```

## Prototype

```c
int _printf(const char *format, ...);
```

The function returns the total number of characters printed,
or `-1` if the format string is NULL.

```c
int _printf(const char *format, ...);

```## How It Works

When `_printf` is called with a format string, it reads the string
character by character. When it finds a `%`, it starts parsing:

1. Reads optional **flags** (`+`, `-`, `0`, `#`, ` `)
2. Reads optional **field width** (number or `*`)
3. Reads optional **precision** (`.number` or `.*`)
4. Reads optional **length modifier** (`l` or `h`)
5. Reads the **conversion specifier** (`d`, `s`, `c`, etc.)
6. Prints the result with the correct formatting

Output is stored in a local buffer of 1024 bytes and flushed
to stdout when full or when the format string ends.

## Supported Conversion Specifiers
| Specifier | Description | Example |
|-----------|-------------|---------|
| `%c` | Prints a single character | `_printf("%c", 'A')` → `A` |
| `%s` | Prints a string | `_printf("%s", "Hi")` → `Hi` |
| `%d` / `%i` | Prints a signed decimal integer | `_printf("%d", 42)` → `42` |
| `%u` | Prints an unsigned integer | `_printf("%u", 42)` → `42` |
| `%o` | Prints a number in octal | `_printf("%o", 8)` → `10` |
| `%x` | Prints a number in lowercase hex | `_printf("%x", 255)` → `ff` |
| `%X` | Prints a number in uppercase hex | `_printf("%X", 255)` → `FF` |
| `%p` | Prints a pointer address | `_printf("%p", ptr)` → `0x...` |
| `%b` | Prints a number in binary *(custom)* | `_printf("%b", 5)` → `101` |
| `%S` | Prints string, non-printable as `\xHH` *(custom)* | `_printf("%S", "A\n")` → `A\x0A` |
| `%r` | Prints a string in reverse *(custom)* | `_printf("%r", "Hello")` → `olleH` |
| `%R` | Prints a string in ROT13 *(custom)* | `_printf("%R", "Hello")` → `Uryyb` |
| `%%` | Prints a literal `%` | `_printf("%%")` → `%` |


| Specifier | Description |
|-----------|-------------|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%d` / `%i` | Prints a signed integer |
| `%u` | Prints an unsigned integer |
| `%o` | Prints a number in octal |
| `%x` / `%X` | Prints a number in hexadecimal (lower/upper) |
| `%p` | Prints a pointer address |
| `%b` | Prints a number in binary (custom) |
| `%S` | Prints a string with non-printable chars as `\xHH` (custom) |
| `%r` | Prints a string in reverse (custom) |
| `%R` | Prints a string encoded in ROT13 (custom) |
| `%%` | Prints a literal `%` |

## Supported Flags

| Flag | Description | Example |
|------|-------------|---------|
| `+` | Forces `+` sign before positive numbers | `_printf("%+d", 42)` → `+42` |
| ` ` | Adds a space before positive numbers | `_printf("% d", 42)` → ` 42` |
| `#` | Adds `0` for octal, `0x`/`0X` for hex | `_printf("%#x", 255)` → `0xff` |
| `0` | Pads with zeros instead of spaces | `_printf("%06d", 42)` → `000042` |
| `-` | Left-aligns the output | `_printf("%-6d", 42)` → `42    ` |
| Flag | Description |
|------|-------------|
| `+` | Forces sign for positive numbers |
| ` ` | Adds space before positive numbers |
| `#` | Adds `0` prefix for octal, `0x`/`0X` for hex |
| `0` | Pads with zeros instead of spaces |
| `-` | Left-aligns the output |


## Supported Length Modifiers

| Modifier | Description | Example |
|----------|-------------|---------|
| `l` | Long integer | `_printf("%ld", LONG_MAX)` → `9223372036854775807` |
| `h` | Short integer | `_printf("%hd", 32767)` → `32767` |
| Modifier | Description |
|----------|-------------|
| `l` | Long (`long int` / `unsigned long int`) |
| `h` | Short (`short int` / `unsigned short int`) |

## Field Width and Precision

- **Field width**: minimum number of characters to print, padded with spaces or zeros.
- **Precision**: for integers adds leading zeros, for strings limits length.
- Both support `*` to read width/precision from arguments.

## Field Width and Precision

| Feature | Description | Example |
|---------|-------------|---------|
| Width `%6d` | Minimum characters, right-aligned | `_printf("%6d", 42)` → `    42` |
| Width `%-6d` | Minimum characters, left-aligned | `_printf("%-6d", 42)` → `42    ` |
| Width `%*d` | Width from argument | `_printf("%*d", 6, 42)` → `    42` |
| Precision `%.5d` | Minimum digits for integers | `_printf("%.5d", 42)` → `00042` |
| Precision `%.5s` | Maximum characters for strings | `_printf("%.5s", "Hello World")` → `Hello` |
| Precision `%.*d` | Precision from argument | `_printf("%.*d", 5, 42)` → `00042` |
```
##Example ## Examples

```c
/* Basic specifiers */
_printf("Hello %s!\n", "World");
// Output: Hello World!

_printf("Char: %c\n", 'A');
// Output: Char: A

_printf("Number: %d\n", 42);
// Output: Number: 42

_printf("Negative: %d\n", -42);
// Output: Negative: -42

_printf("Zero: %d\n", 0);
// Output: Zero: 0

/* Unsigned, Octal, Hex */
_printf("Unsigned: %u\n", 12345);
// Output: Unsigned: 12345

_printf("Octal: %o\n", 8);
// Output: Octal: 10

_printf("Hex lower: %x\n", 255);
// Output: Hex lower: ff

_printf("Hex upper: %X\n", 255);
// Output: Hex upper: FF

_printf("Binary: %b\n", 10);
// Output: Binary: 1010

/* Flags */
_printf("%+d and %+d\n", 42, -42);
// Output: +42 and -42

_printf("% d and % d\n", 42, -42);
// Output:  42 and -42

_printf("%#o\n", 8);
// Output: 010

_printf("%#x\n", 255);
// Output: 0xff

_printf("%#X\n", 255);
// Output: 0XFF

/* Zero flag */
_printf("%06d\n", 42);
// Output: 000042

_printf("%06d\n", -42);
// Output: -00042

_printf("%06x\n", 255);
// Output: 0000ff

/* Minus flag - left align */
_printf("%-10s|\n", "Hi");
// Output: Hi        |

_printf("%-6d|\n", 42);
// Output: 42    |

_printf("%-6d|\n", -42);
// Output: -42   |

/* Field width */
_printf("%6d\n", 42);
// Output:     42

_printf("%10s\n", "Hello");
// Output:      Hello

_printf("%6c\n", 'A');
// Output:      A

/* Precision */
_printf("%.5d\n", 42);
// Output: 00042

_printf("%.5d\n", 0);
// Output: 00000

_printf("%.0d\n", 0);
// Output: (empty)

_printf("%.5s\n", "Hello World");
// Output: Hello

_printf("%.3s\n", "Hi");
// Output: Hi

/* Width and precision combined */
_printf("%10.5d\n", 42);
// Output:      00042

_printf("%-10.5d|\n", 42);
// Output: 00042     |

_printf("%10.5s\n", "Hello World");
// Output:      Hello

/* Star width and precision */
_printf("%*d\n", 6, 42);
// Output:     42

_printf("%.*d\n", 5, 42);
// Output: 00042

_printf("%*.*s\n", 10, 5, "Hello World");
// Output:      Hello

/* Length modifiers */
_printf("%ld\n", 9223372036854775807L);
// Output: 9223372036854775807

_printf("%ld\n", -9223372036854775808L);
// Output: -9223372036854775808

_printf("%lu\n", 18446744073709551615UL);
// Output: 18446744073709551615

_printf("%hd\n", 32767);
// Output: 32767

_printf("%hu\n", 65535);
// Output: 65535

/* Custom specifiers */
_printf("%r\n", "Hello");
// Output: olleH

_printf("%r\n", "Hello World");
// Output: dlroW olleH

_printf("%R\n", "Hello");
// Output: Uryyb

_printf("%R\n", "ABC xyz");
// Output: NOP klm

_printf("%S\n", "Hello\nWorld");
// Output: Hello\x0AWorld

/* Percent sign */
_printf("100%%\n");
// Output: 100%

/* Multiple specifiers in one line */
_printf("%s is %d years old\n", "Shahad", 20);
// Output: Shahad is 20 years old

_printf("%d + %d = %d\n", 10, 20, 30);
// Output: 10 + 20 = 30

_printf("Hex: %#010x\n", 255);
// Output: Hex: 0x000000ff
```

```c
_printf("Hello %s!\n", "World");
// Output: Hello World!

_printf("Number: %d\n", 42);
// Output: Number: 42

_printf("%06d\n", 42);
// Output: 000042

_printf("%-10s|\n", "Hi");
// Output: Hi        |

_printf("%.5d\n", 42);
// Output: 00042

_printf("%+d and %+d\n", 42, -42);
// Output: +42 and -42

_printf("%#x\n", 255);
// Output: 0xff

_printf("%r\n", "Hello");
// Output: olleH

_printf("%R\n", "Hello");
// Output: Uryyb

_printf("%ld\n", LONG_MIN);
// Output: -9223372036854775808
```

```c
_printf("Hello %s\n", "World");
_printf("Number: %d\n", 42);

```c
_printf("%d", 42);           // 42
_printf("%06d", 42);         // 000042
_printf("%-6d", 42);         // 42
_printf("%.5d", 42);         // 00042
_printf("%6s", "Hi");        //     Hi
_printf("%r", "Hello");      // olleH
_printf("%R", "Hello");      // Uryyb
_printf("%ld", LONG_MIN);    // -9223372036854775808

```
## Files

| File | Description |
|------|-------------|
| `_printf.c` | Main function handling format parsing |
| `main.h` | Header file with all prototypes |
| `print_rot13.c` | ROT13 custom specifier |
| `print_reverse.c` | Reverse string custom specifier |
| File | Description |
|------|-------------|
| `_printf.c` | Main function — handles all format string parsing and output |
| `main.h` | Header file containing all function prototypes |
| `print_rot13.c` | Handles `%R` custom specifier — ROT13 encoding |
| `print_reverse.c` | Handles `%r` custom specifier — reverse string |




```

## Testing
## Testing

### Compile

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o printf
```

### Basic Test

Create a test file:

```bash
nano main_test.c
```

Paste this:

```c
#include "main.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int len1, len2;

    /* Basic specifiers */
    len1 = _printf("Hello %s!\n", "World");
    len2 = printf("Hello %s!\n", "World");
    _printf("_printf: %d | printf: %d\n\n", len1, len2);

    /* Characters */
    len1 = _printf("Char: %c\n", 'A');
    len2 = printf("Char: %c\n", 'A');
    _printf("_printf: %d | printf: %d\n\n", len1, len2);

    /* Integers */
    len1 = _printf("Positive: %d\n", 42);
    len2 = printf("Positive: %d\n", 42);
    _printf("_printf: %d | printf: %d\n\n", len1, len2);

    len1 = _printf("Negative: %d\n", -42);
    len2 = printf("Negative: %d\n", -42);
    _printf("_printf: %d | printf: %d\n\n", len1, len2);

    len1 = _printf("Zero: %d\n", 0);
    len2 = printf("Zero: %d\n", 0);
    _printf("_printf: %d | printf: %d\n\n", len1, len2);

    /* Flags */
    len1 = _printf("Plus flag: %+d\n", 42);
    len2 = printf("Plus flag: %+d\n", 42);
    _printf("_printf: %d | printf: %d\n\n", len1, len2);

    len1 = _printf("Zero flag: %06d\n", 42);
    len2 = printf("Zero flag: %06d\n", 42);
    _printf("_printf: %d | printf: %d\n\n", len1, len2);

    len1 = _printf("Minus flag: %-6d|\n", 42);
    len2 = printf("Minus flag: %-6d|\n", 42);
    _printf("_printf: %d | printf: %d\n\n", len1, len2);

    len1 = _printf("Hash flag: %#x\n", 255);
    len2 = printf("Hash flag: %#x\n", 255);
    _printf("_printf: %d | printf: %d\n\n", len1, len2);

    /* Precision */
    len1 = _printf("Precision int: %.5d\n", 42);
    len2 = printf("Precision int: %.5d\n", 42);
    _printf("_printf: %d | printf: %d\n\n", len1, len2);

    len1 = _printf("Precision str: %.5s\n", "Hello World");
    len2 = printf("Precision str: %.5s\n", "Hello World");
    _printf("_printf: %d | printf: %d\n\n", len1, len2);

    len1 = _printf("Zero precision: %.0d\n", 0);
    len2 = printf("Zero precision: %.0d\n", 0);
    _printf("_printf: %d | printf: %d\n\n", len1, len2);

    /* Width */
    len1 = _printf("Width: %6d\n", 42);
    len2 = printf("Width: %6d\n", 42);
    _printf("_printf: %d | printf: %d\n\n", len1, len2);

    len1 = _printf("Width str: %10s\n", "Hello");
    len2 = printf("Width str: %10s\n", "Hello");
    _printf("_printf: %d | printf: %d\n\n", len1, len2);

    /* Star width and precision */
    len1 = _printf("Star width: %*d\n", 6, 42);
    len2 = printf("Star width: %*d\n", 6, 42);
    _printf("_printf: %d | printf: %d\n\n", len1, len2);

    len1 = _printf("Star precision: %.*d\n", 5, 42);
    len2 = printf("Star precision: %.*d\n", 5, 42);
    _printf("_printf: %d | printf: %d\n\n", len1, len2);

    /* Length modifiers */
    len1 = _printf("Long max: %ld\n", LONG_MAX);
    len2 = printf("Long max: %ld\n", LONG_MAX);
    _printf("_printf: %d | printf: %d\n\n", len1, len2);

    len1 = _printf("Long min: %ld\n", LONG_MIN);
    len2 = printf("Long min: %ld\n", LONG_MIN);
    _printf("_printf: %d | printf: %d\n\n", len1, len2);

    len1 = _printf("Short: %hd\n", SHRT_MAX);
    len2 = printf("Short: %hd\n", SHRT_MAX);
    _printf("_printf: %d | printf: %d\n\n", len1, len2);

    /* Custom specifiers */
    _printf("Reverse: %r\n", "Hello World");
    _printf("ROT13: %R\n", "Hello World");
    _printf("Binary: %b\n", 42);

    /* Percent sign */
    len1 = _printf("Percent: 100%%\n");
    len2 = printf("Percent: 100%%\n");
    _printf("_printf: %d | printf: %d\n\n", len1, len2);

    /* NULL string */
    len1 = _printf("Null string: %s\n", (char *)NULL);
    len2 = printf("Null string: %s\n", (char *)NULL);
    _printf("_printf: %d | printf: %d\n\n", len1, len2);

    return (0);
}
```

Compile and run:

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c main_test.c -o test
./test
```

### Check Memory Leaks

```bash
valgrind --leak-check=full ./test
```

### Check Betty Style

```bash
betty _printf.c main.h
```

### Expected Output Example
/* Basic specifiers */
len1 = _printf("Hello %s!\n", "World");
len2 = printf("Hello %s!\n", "World");
_printf("_printf: %d | printf: %d\n\n", len1, len2);


Compile and run:

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o printf
./printf
```

```bash
./printf

```

Authors
Shahad Alharbi 
Noura Alosaimi




