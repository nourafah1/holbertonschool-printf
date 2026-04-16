#include "main.h"

/**
 * flush_buffer - writes buffer content to stdout
 * @buffer: buffer array
 * @index: current buffer index
 */
void flush_buffer(char buffer[], int *index)
{
	if (*index > 0)
	{
		write(1, buffer, *index);
		*index = 0;
	}
}

/**
 * add_to_buffer - adds a character to buffer
 * @buffer: buffer array
 * @index: current buffer index
 * @c: character to add
 * @count: printed chars count
 */
void add_to_buffer(char buffer[], int *index, char c, int *count)
{
	buffer[*index] = c;
	(*index)++;
	(*count)++;

	if (*index == 1024)
		flush_buffer(buffer, index);
}

/**
 * print_string_buffer - adds a string to buffer
 * @str: string to print
 * @buffer: buffer array
 * @index: current buffer index
 * @count: printed chars count
 */
void print_string_buffer(char *str, char buffer[], int *index, int *count)
{
	int i = 0;

	while (str[i])
	{
		add_to_buffer(buffer, index, str[i], count);
		i++;
	}
}
