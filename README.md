# _printf Project

## Description
This project is a custom implementation of the printf function in C as part of the Holberton School curriculum. It handles formatted output and supports basic conversion specifiers.flags, field width, precision,
and length modifiers.


## Requirements
- GCC compiler
- Ubuntu 20.04
- Allowed functions: write, malloc, free, etc.
* GCC compiler
* Ubuntu 20.04
* Allowed functions: `write`, `malloc`, `free`, `va_start`, `va_end`, `va_arg`


## Installation
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
## Supported Conversion Specifiers

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

| Flag | Description |
|------|-------------|
| `+` | Forces sign for positive numbers |
| ` ` | Adds space before positive numbers |
| `#` | Adds `0` prefix for octal, `0x`/`0X` for hex |
| `0` | Pads with zeros instead of spaces |
| `-` | Left-aligns the output |

## Supported Length Modifiers

| Modifier | Description |
|----------|-------------|
| `l` | Long (`long int` / `unsigned long int`) |
| `h` | Short (`short int` / `unsigned short int`) |

## Field Width and Precision

- **Field width**: minimum number of characters to print, padded with spaces or zeros.
- **Precision**: for integers adds leading zeros, for strings limits length.
- Both support `*` to read width/precision from arguments.

```
##Example 
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


```

## Testing
```bash
./printf

```

Authors
Shahad Alharbi 
Noura Alosaimi




