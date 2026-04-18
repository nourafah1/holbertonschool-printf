#include "main.h"

/**
 * print_rot13_buffer - prints string encoded in rot13
 * @str: the string
 * @buffer: output buffer
 * @index: buffer index
 * @count: character count
 */
void print_rot13_buffer(char *str, char buffer[], int *index, int *count)
{
	int i;
	char c;
	char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		int j = 0;
		int found = 0;

		while (upper[j])
		{
			if (str[i] == upper[j])
			{
				c = rot13[j];
				found = 1;
				break;
			}
			j++;
		}
		if (!found)
			c = str[i];
		add_to_buffer(buffer, index, c, count);
	}
}
