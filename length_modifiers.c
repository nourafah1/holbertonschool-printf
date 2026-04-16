#include "main.h"

/**
 * print_unsigned_long_buffer - prints unsigned long integer using buffer
 * @n: number to print
 * @buffer: buffer array
 * @index: current buffer index
 * @count: printed chars count
 */
void print_unsigned_long_buffer(unsigned long int n, char buffer[],
	int *index, int *count)
{
	if (n / 10)
		print_unsigned_long_buffer(n / 10, buffer, index, count);
	add_to_buffer(buffer, index, (n % 10) + '0', count);
}

/**
 * print_octal_long_buffer - prints unsigned long integer in octal
 * @n: number to print
 * @buffer: buffer array
 * @index: current buffer index
 * @count: printed chars count
 */
void print_octal_long_buffer(unsigned long int n, char buffer[],
	int *index, int *count)
{
	if (n / 8)
		print_octal_long_buffer(n / 8, buffer, index, count);
	add_to_buffer(buffer, index, (n % 8) + '0', count);
}

/**
 * print_hex_long_buffer - prints unsigned long integer in hexadecimal
 * @n: number to print
 * @uppercase: 1 for uppercase, 0 for lowercase
 * @buffer: buffer array
 * @index: current buffer index
 * @count: printed chars count
 */
void print_hex_long_buffer(unsigned long int n, int uppercase, char buffer[],
	int *index, int *count)
{
	char digit;

	if (n / 16)
		print_hex_long_buffer(n / 16, uppercase, buffer, index, count);
	if ((n % 16) < 10)
		digit = (n % 16) + '0';
	else if (uppercase)
		digit = (n % 16) - 10 + 'A';
	else
		digit = (n % 16) - 10 + 'a';
	add_to_buffer(buffer, index, digit, count);
}

/**
 * print_signed_modifier - prints signed number with optional flags
 * @n: number to print
 * @plus_flag: plus flag
 * @space_flag: space flag
 * @buffer: buffer array
 * @index: current buffer index
 * @count: printed chars count
 */
void print_signed_modifier(long int n, int plus_flag, int space_flag,
	char buffer[], int *index, int *count)
{
	if (n >= 0)
	{
		if (plus_flag)
			add_to_buffer(buffer, index, '+', count);
		else if (space_flag)
			add_to_buffer(buffer, index, ' ', count);
	}
	print_number_buffer(n, buffer, index, count);
}
