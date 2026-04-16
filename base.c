#include "main.h"

/**
 * print_octal_buffer - prints an unsigned int in octal using buffer
 * @n: number to print
 * @buffer: buffer array
 * @index: current buffer index
 * @count: printed chars count
 */
void print_octal_buffer(unsigned int n, char buffer[], int *index, int *count)
{
	if (n / 8)
		print_octal_buffer(n / 8, buffer, index, count);

	add_to_buffer(buffer, index, (n % 8) + '0', count);
}

/**
 * print_hex_buffer - prints an unsigned int in hexadecimal using buffer
 * @n: number to print
 * @uppercase: 1 for uppercase, 0 for lowercase
 * @buffer: buffer array
 * @index: current buffer index
 * @count: printed chars count
 */
void print_hex_buffer(unsigned int n, int uppercase, char buffer[],
	int *index, int *count)
{
	char digit;

	if (n / 16)
		print_hex_buffer(n / 16, uppercase, buffer, index, count);

	if ((n % 16) < 10)
		digit = (n % 16) + '0';
	else if (uppercase)
		digit = (n % 16) - 10 + 'A';
	else
		digit = (n % 16) - 10 + 'a';

	add_to_buffer(buffer, index, digit, count);
}
