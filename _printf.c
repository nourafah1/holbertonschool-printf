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
	int long_mod, short_mod;
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
			long_mod = 0;
			short_mod = 0;
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
			if (format[i] == 'l')
			{
				long_mod = 1;
				i++;
			}
			else if (format[i] == 'h')
			{
				short_mod = 1;
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
				add_to_buffer(buffer, &buf_index, '%', &count);
			else if (format[i] == 'd' || format[i] == 'i')
			{
				if (long_mod)
					print_signed_modifier(va_arg(args, long int), plus_flag,
						space_flag, buffer, &buf_index, &count);
				else if (short_mod)
					print_signed_modifier((short int)va_arg(args, int),
						plus_flag, space_flag, buffer, &buf_index, &count);
				else
					print_signed_modifier((long int)va_arg(args, int),
						plus_flag, space_flag, buffer, &buf_index, &count);
			}
			else if (format[i] == 'b')
				print_binary_buffer(va_arg(args, unsigned int),
					buffer, &buf_index, &count);
			else if (format[i] == 'u')
			{
				if (long_mod)
					print_unsigned_long_buffer(va_arg(args, unsigned long int),
						buffer, &buf_index, &count);
				else if (short_mod)
					print_unsigned_buffer((unsigned short int)
						va_arg(args, unsigned int), buffer, &buf_index, &count);
				else
					print_unsigned_buffer(va_arg(args, unsigned int),
						buffer, &buf_index, &count);
			}
			else if (format[i] == 'o')
			{
				if (long_mod)
				{
					unsigned long int n = va_arg(args, unsigned long int);

					if (hash_flag && n != 0)
						add_to_buffer(buffer, &buf_index, '0', &count);
					print_octal_long_buffer(n, buffer, &buf_index, &count);
				}
				else if (short_mod)
					print_hash_octal((unsigned short int)
						va_arg(args, unsigned int), hash_flag,
						buffer, &buf_index, &count);
				else
					print_hash_octal(va_arg(args, unsigned int), hash_flag,
						buffer, &buf_index, &count);
			}
			else if (format[i] == 'x')
			{
				if (long_mod)
				{
					unsigned long int n = va_arg(args, unsigned long int);

					if (hash_flag && n != 0)
					{
						add_to_buffer(buffer, &buf_index, '0', &count);
						add_to_buffer(buffer, &buf_index, 'x', &count);
					}
					print_hex_long_buffer(n, 0, buffer, &buf_index, &count);
				}
				else if (short_mod)
					print_hash_hex((unsigned short int)
						va_arg(args, unsigned int), hash_flag, 0,
						buffer, &buf_index, &count);
				else
					print_hash_hex(va_arg(args, unsigned int), hash_flag, 0,
						buffer, &buf_index, &count);
			}
			else if (format[i] == 'X')
			{
				if (long_mod)
				{
					unsigned long int n = va_arg(args, unsigned long int);

					if (hash_flag && n != 0)
					{
						add_to_buffer(buffer, &buf_index, '0', &count);
						add_to_buffer(buffer, &buf_index, 'X', &count);
					}
					print_hex_long_buffer(n, 1, buffer, &buf_index, &count);
				}
				else if (short_mod)
					print_hash_hex((unsigned short int)
						va_arg(args, unsigned int), hash_flag, 1,
						buffer, &buf_index, &count);
				else
					print_hash_hex(va_arg(args, unsigned int), hash_flag, 1,
						buffer, &buf_index, &count);
			}
			else if (format[i] == 'p')
				print_pointer_buffer(va_arg(args, void *),
					buffer, &buf_index, &count);
			else
			{
				add_to_buffer(buffer, &buf_index, '%', &count);
				add_to_buffer(buffer, &buf_index, format[i], &count);
			}
		}
		else
			add_to_buffer(buffer, &buf_index, format[i], &count);
		i++;
	}
	flush_buffer(buffer, &buf_index);
	va_end(args);
	return (count);
}
