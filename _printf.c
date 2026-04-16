#include "main.h"
#include <stdarg.h>

/**
 * _printf - prints formatted output using a local buffer
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	char *str, c;
	char buffer[1024];
	int buf_index = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;

			if (format[i] == '\0')
			{
				flush_buffer(buffer, &buf_index);
				va_end(args);
				return (-1);
			}

			if (format[i] == 'c')
			{
				c = va_arg(args, int);
				add_to_buffer(buffer, &buf_index, c, &count);
			}
			else if (format[i] == 's')
			{
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				print_string_buffer(str, buffer, &buf_index, &count);
			}
			else if (format[i] == '%')
			{
				add_to_buffer(buffer, &buf_index, '%', &count);
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				print_number_buffer((long int)va_arg(args, int),
					buffer, &buf_index, &count);
			}
			else if (format[i] == 'b')
			{
				print_binary_buffer(va_arg(args, unsigned int),
					buffer, &buf_index, &count);
			}
			else if (format[i] == 'u')
			{
				print_unsigned_buffer(va_arg(args, unsigned int),
					buffer, &buf_index, &count);
			}
			else if (format[i] == 'o')
			{
				print_octal_buffer(va_arg(args, unsigned int),
					buffer, &buf_index, &count);
			}
			else if (format[i] == 'x')
			{
				print_hex_buffer(va_arg(args, unsigned int), 0,
					buffer, &buf_index, &count);
			}
			else if (format[i] == 'X')
			{
				print_hex_buffer(va_arg(args, unsigned int), 1,
					buffer, &buf_index, &count);
			}
			else
			{
				add_to_buffer(buffer, &buf_index, '%', &count);
				add_to_buffer(buffer, &buf_index, format[i], &count);
			}
		}
		else
		{
			add_to_buffer(buffer, &buf_index, format[i], &count);
		}
		i++;
	}

	flush_buffer(buffer, &buf_index);
	va_end(args);

	return (count);
}
