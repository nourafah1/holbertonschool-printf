#include "main.h"

/**
 * print_reverse_buffer - prints a string in reverse
 * @str: the string to reverse
 * @buffer: output buffer
 * @index: buffer index
 * @count: character count
 */
void print_reverse_buffer(char *str, char buffer[], int *index, int *count)
{
	int len = 0;
	int i;

	if (str == NULL)
		str = "(null)";
	while (str[len])
		len++;
	for (i = len - 1; i >= 0; i--)
		add_to_buffer(buffer, index, str[i], count);
}
