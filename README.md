# _printf Project

## Description
This project is a custom implementation of the printf function in C as part of the Holberton School curriculum. It handles formatted output and supports basic conversion specifiers.flags, field width, precision,
and length modifiers.This project is a custom implementation of the `printf` function in C
as part of the Holberton School curriculum. It replicates the behavior
of the standard `printf` function by handling formatted output with
various conversion specifiers, flags, field width, precision, and
length modifiers. The function writes output to stdout using a local
buffer for efficiency.



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
##Example 
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




