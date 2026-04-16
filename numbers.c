#include "main.h"

/**
 * print_number_buffer - prints an integer using buffer
 * @n: number to print
 * @buffer: buffer array
 * @index: current buffer index
 * @count: printed chars count
 */
void print_number_buffer(long int n, char buffer[], int *index, int *count)
{
	if (n < 0)
	{
		add_to_buffer(buffer, index, '-', count);
		n = -n;
	}
	if (n >= 10)
		print_number_buffer(n / 10, buffer, index, count);

	add_to_buffer(buffer, index, (n % 10) + '0', count);
}

/**
 * print_binary_buffer - prints an unsigned int in binary using buffer
 * @n: number to print
 * @buffer: buffer array
 * @index: current buffer index
 * @count: printed chars count
 */
void print_binary_buffer(unsigned int n, char buffer[], int *index, int *count)
{
	if (n / 2)
		print_binary_buffer(n / 2, buffer, index, count);

	add_to_buffer(buffer, index, (n % 2) + '0', count);
}

/**
 * print_unsigned_buffer - prints an unsigned int using buffer
 * @n: number to print
 * @buffer: buffer array
 * @index: current buffer index
 * @count: printed chars count
 */
void print_unsigned_buffer(unsigned int n, char buffer[],
	int *index, int *count)
{
	if (n / 10)
		print_unsigned_buffer(n / 10, buffer, index, count);

	add_to_buffer(buffer, index, (n % 10) + '0', count);
}
