#include "main.h"

/**
 * print_special_string - prints a string with non printable chars as hex
 * @str: string to print
 * @buffer: buffer array
 * @index: current buffer index
 * @count: printed chars count
 */
void print_special_string(char *str, char buffer[], int *index, int *count)
{
	int i = 0;
	unsigned char c;
	char *hex = "0123456789ABCDEF";

	while (str[i])
	{
		c = str[i];
		if ((c > 0 && c < 32) || c >= 127)
		{
			add_to_buffer(buffer, index, '\\', count);
			add_to_buffer(buffer, index, 'x', count);
			add_to_buffer(buffer, index, hex[c / 16], count);
			add_to_buffer(buffer, index, hex[c % 16], count);
		}
		else
		{
			add_to_buffer(buffer, index, c, count);
		}
		i++;
	}
}
