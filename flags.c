#include "main.h"

/**
 * print_signed_flag - prints signed number with + or space flags
 * @n: number to print
 * @plus_flag: plus flag
 * @space_flag: space flag
 * @buffer: buffer array
 * @index: current buffer index
 * @count: printed chars count
 */
void print_signed_flag(long int n, int plus_flag, int space_flag,
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

/**
 * print_hash_octal - prints octal with # flag
 * @n: number to print
 * @hash_flag: hash flag
 * @buffer: buffer array
 * @index: current buffer index
 * @count: printed chars count
 */
void print_hash_octal(unsigned int n, int hash_flag, char buffer[],
	int *index, int *count)
{
	if (hash_flag && n != 0)
		add_to_buffer(buffer, index, '0', count);
	print_octal_buffer(n, buffer, index, count);
}

/**
 * print_hash_hex - prints hexadecimal with # flag
 * @n: number to print
 * @hash_flag: hash flag
 * @uppercase: 1 for uppercase, 0 for lowercase
 * @buffer: buffer array
 * @index: current buffer index
 * @count: printed chars count
 */
void print_hash_hex(unsigned int n, int hash_flag, int uppercase,
	char buffer[], int *index, int *count)
{
	if (hash_flag && n != 0)
	{
		add_to_buffer(buffer, index, '0', count);
		if (uppercase)
			add_to_buffer(buffer, index, 'X', count);
		else
			add_to_buffer(buffer, index, 'x', count);
	}
	print_hex_buffer(n, uppercase, buffer, index, count);
}
