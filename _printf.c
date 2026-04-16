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
	int plus_flag, space_flag, hash_flag;
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
			plus_flag = 0;
			space_flag = 0;
			hash_flag = 0;
			i++;

			while (format[i] == '+' || format[i] == ' ' || format[i] == '#')
			{
				if (format[i] == '+')
					plus_flag = 1;
				else if (format[i] == ' ')
					space_flag = 1;
				else if (format[i] == '#')
					hash_flag = 1;
				i++;
			}

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
			else if (format[i] == 'S')
			{
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				print_special_string(str, buffer, &buf_index, &count);
			}
			else if (format[i] == '%')
			{
				add_to_buffer(buffer, &buf_index, '%', &count);
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				print_signed_flag((long int)va_arg(args, int), plus_flag,
					space_flag, buffer, &buf_index, &count);
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
				print_hash_octal(va_arg(args, unsigned int), hash_flag,
					buffer, &buf_index, &count);
			}
			else if (format[i] == 'x')
			{
				print_hash_hex(va_arg(args, unsigned int), hash_flag, 0,
					buffer, &buf_index, &count);
			}
			else if (format[i] == 'X')
			{
				print_hash_hex(va_arg(args, unsigned int), hash_flag, 1,
					buffer, &buf_index, &count);
			}
			else if (format[i] == 'p')
			{
				print_pointer_buffer(va_arg(args, void *),
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
