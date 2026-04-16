#include "main.h"

/**
 * print_pointer_rec - prints pointer value in hexadecimal
 * @n: number to print
 * @buffer: buffer array
 * @index: current buffer index
 * @count: printed chars count
 */
static void print_pointer_rec(unsigned long int n, char buffer[],
	int *index, int *count)
{
	char *hex = "0123456789abcdef";

	if (n / 16)
		print_pointer_rec(n / 16, buffer, index, count);

	add_to_buffer(buffer, index, hex[n % 16], count);
}

/**
 * print_pointer_buffer - prints a pointer address
 * @ptr: pointer to print
 * @buffer: buffer array
 * @index: current buffer index
 * @count: printed chars count
 */
void print_pointer_buffer(void *ptr, char buffer[], int *index, int *count)
{
	unsigned long int addr;

	if (ptr == NULL)
	{
		print_string_buffer("(nil)", buffer, index, count);
		return;
	}

	addr = (unsigned long int)ptr;
	add_to_buffer(buffer, index, '0', count);
	add_to_buffer(buffer, index, 'x', count);
	print_pointer_rec(addr, buffer, index, count);
}
