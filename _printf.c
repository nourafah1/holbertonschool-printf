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
	int width, j, precision;
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
			width = 0;
			precision = -1;
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
			if (format[i] == '*')
			{
				width = va_arg(args, int);
				i++;
			}
			else
			{
				while (format[i] >= '0' && format[i] <= '9')
				{
					width = width * 10 + (format[i] - '0');
					i++;
				}
			}
			if (format[i] == '.')
			{
				i++;
				if (format[i] == '*')
				{
					precision = va_arg(args, int);
					i++;
				}
				else
				{
					precision = 0;
					while (format[i] >= '0' && format[i] <= '9')
					{
						precision = precision * 10 + (format[i] - '0');
						i++;
					}
				}
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
				for (j = 1; j < width; j++)
					add_to_buffer(buffer, &buf_index, ' ', &count);
				c = va_arg(args, int);
				add_to_buffer(buffer, &buf_index, c, &count);
			}
			else if (format[i] == 's')
			{
				int len = 0;
				int print_len;

				str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				while (str[len])
					len++;
				if (precision >= 0 && precision < len)
					print_len = precision;
				else
					print_len = len;
				for (j = print_len; j < width; j++)
					add_to_buffer(buffer, &buf_index, ' ', &count);
				for (j = 0; j < print_len; j++)
					add_to_buffer(buffer, &buf_index, str[j], &count);
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
				for (j = 1; j < width; j++)
					add_to_buffer(buffer, &buf_index, ' ', &count);
				add_to_buffer(buffer, &buf_index, '%', &count);
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				long int num;
				int len = 0;
				int zero_pad = 0;
				long int tmp;

				if (long_mod)
					num = va_arg(args, long int);
				else if (short_mod)
					num = (short int)va_arg(args, int);
				else
					num = (long int)va_arg(args, int);
				tmp = (num < 0) ? -num : num;
				if (tmp == 0 && precision == 0)
				{
					for (j = 0; j < width; j++)
						add_to_buffer(buffer, &buf_index, ' ', &count);
				}
				else
				{
					if (tmp == 0)
						len = 1;
					else
					{
						long int t = tmp;

						while (t > 0)
						{
							len++;
							t /= 10;
						}
					}
					if (num < 0)
						len++;
					else if (plus_flag || space_flag)
						len++;
					if (precision > len - (num < 0 ? 1 : (plus_flag || space_flag ? 1 : 0)))
						zero_pad = precision - (len - (num < 0 ? 1 : (plus_flag || space_flag ? 1 : 0)));
					for (j = len + zero_pad; j < width; j++)
						add_to_buffer(buffer, &buf_index, ' ', &count);
					if (num < 0)
						add_to_buffer(buffer, &buf_index, '-', &count);
					else if (plus_flag)
						add_to_buffer(buffer, &buf_index, '+', &count);
					else if (space_flag)
						add_to_buffer(buffer, &buf_index, ' ', &count);
					for (j = 0; j < zero_pad; j++)
						add_to_buffer(buffer, &buf_index, '0', &count);
					print_number_buffer(tmp, buffer, &buf_index, &count);
				}
			}
			else if (format[i] == 'b')
				print_binary_buffer(va_arg(args, unsigned int),
					buffer, &buf_index, &count);
			else if (format[i] == 'u')
			{
				unsigned long int unum;
				int ulen = 0;
				int uzero_pad = 0;
				unsigned long int utmp;

				if (long_mod)
					unum = va_arg(args, unsigned long int);
				else if (short_mod)
					unum = (unsigned short int)va_arg(args, unsigned int);
				else
					unum = va_arg(args, unsigned int);
				if (unum == 0 && precision == 0)
				{
					for (j = 0; j < width; j++)
						add_to_buffer(buffer, &buf_index, ' ', &count);
				}
				else
				{
					utmp = unum;
					if (utmp == 0)
						ulen = 1;
					else
						while (utmp > 0)
						{
							ulen++;
							utmp /= 10;
						}
					if (precision > ulen)
						uzero_pad = precision - ulen;
					for (j = ulen + uzero_pad; j < width; j++)
						add_to_buffer(buffer, &buf_index, ' ', &count);
					for (j = 0; j < uzero_pad; j++)
						add_to_buffer(buffer, &buf_index, '0', &count);
					if (long_mod)
						print_unsigned_long_buffer(unum,
							buffer, &buf_index, &count);
					else if (short_mod)
						print_unsigned_buffer((unsigned short int)unum,
							buffer, &buf_index, &count);
					else
						print_unsigned_buffer((unsigned int)unum,
							buffer, &buf_index, &count);
				}
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
