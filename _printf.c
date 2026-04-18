#include "main.h"
#include <stdarg.h>

/**
 * get_uint_len - returns digit count in given base
 * @n: the number
 * @base: the base
 * Return: digit count
 */
static int get_uint_len(unsigned long int n, int base)
{
	int len = 0;

	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n /= base;
	}
	return (len);
}

/**
 * _printf - prints formatted output using a local buffer
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	int plus_flag, space_flag, hash_flag, zero_flag, minus_flag;
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
			zero_flag = 0;
			minus_flag = 0;
			long_mod = 0;
			short_mod = 0;
			width = 0;
			precision = -1;
			i++;
			while (format[i] == '+' || format[i] == ' ' ||
				format[i] == '#' || format[i] == '0' ||
				format[i] == '-')
			{
				if (format[i] == '+')
					plus_flag = 1;
				else if (format[i] == ' ')
					space_flag = 1;
				else if (format[i] == '#')
					hash_flag = 1;
				else if (format[i] == '0')
					zero_flag = 1;
				else if (format[i] == '-')
					minus_flag = 1;
				i++;
			}
			if (minus_flag)
				zero_flag = 0;
			if (format[i] == '*')
			{
				width = va_arg(args, int);
				i++;
			}
			else
			{
				while (format[i] >= '1' && format[i] <= '9')
				{
					width = width * 10 + (format[i] - '0');
					i++;
				}
			}
			if (format[i] == '.')
			{
				i++;
				zero_flag = 0;
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
				c = va_arg(args, int);
				if (minus_flag)
				{
					add_to_buffer(buffer, &buf_index, c, &count);
					for (j = 1; j < width; j++)
						add_to_buffer(buffer, &buf_index, ' ', &count);
				}
				else
				{
					for (j = 1; j < width; j++)
						add_to_buffer(buffer, &buf_index, ' ', &count);
					add_to_buffer(buffer, &buf_index, c, &count);
				}
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
				if (minus_flag)
				{
					for (j = 0; j < print_len; j++)
						add_to_buffer(buffer, &buf_index, str[j], &count);
					for (j = print_len; j < width; j++)
						add_to_buffer(buffer, &buf_index, ' ', &count);
				}
				else
				{
					for (j = print_len; j < width; j++)
						add_to_buffer(buffer, &buf_index, ' ', &count);
					for (j = 0; j < print_len; j++)
						add_to_buffer(buffer, &buf_index, str[j], &count);
				}
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
				if (minus_flag)
				{
					add_to_buffer(buffer, &buf_index, '%', &count);
					for (j = 1; j < width; j++)
						add_to_buffer(buffer, &buf_index, ' ', &count);
				}
				else
				{
					for (j = 1; j < width; j++)
						add_to_buffer(buffer, &buf_index, ' ', &count);
					add_to_buffer(buffer, &buf_index, '%', &count);
				}
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				long int num;
				int digits = 0;
				int zero_pad = 0;
				int pad_total;
				long int tmp;

				if (long_mod)
					num = va_arg(args, long int);
				else if (short_mod)
					num = (short int)va_arg(args, int);
				else
					num = (long int)va_arg(args, int);
				tmp = (num < 0) ? -num : num;
				if (num == 0 && precision == 0)
				{
					for (j = 0; j < width; j++)
						add_to_buffer(buffer, &buf_index, ' ', &count);
				}
				else
				{
					if (tmp == 0)
						digits = 1;
					else
					{
						long int t = tmp;

						while (t > 0)
						{
							digits++;
							t /= 10;
						}
					}
					if (precision > digits)
						zero_pad = precision - digits;
					pad_total = digits + zero_pad;
					if (num < 0 || plus_flag || space_flag)
						pad_total++;
					if (minus_flag)
					{
						if (num < 0)
							add_to_buffer(buffer, &buf_index, '-', &count);
						else if (plus_flag)
							add_to_buffer(buffer, &buf_index, '+', &count);
						else if (space_flag)
							add_to_buffer(buffer, &buf_index, ' ', &count);
						for (j = 0; j < zero_pad; j++)
							add_to_buffer(buffer, &buf_index, '0', &count);
						print_number_buffer(tmp, buffer, &buf_index, &count);
						for (j = pad_total; j < width; j++)
							add_to_buffer(buffer, &buf_index, ' ', &count);
					}
					else if (zero_flag && precision == -1)
					{
						if (num < 0)
							add_to_buffer(buffer, &buf_index, '-', &count);
						else if (plus_flag)
							add_to_buffer(buffer, &buf_index, '+', &count);
						else if (space_flag)
							add_to_buffer(buffer, &buf_index, ' ', &count);
						for (j = pad_total; j < width; j++)
							add_to_buffer(buffer, &buf_index, '0', &count);
						for (j = 0; j < zero_pad; j++)
							add_to_buffer(buffer, &buf_index, '0', &count);
						print_number_buffer(tmp, buffer, &buf_index, &count);
					}
					else
					{
						for (j = pad_total; j < width; j++)
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
			}
			else if (format[i] == 'b')
				print_binary_buffer(va_arg(args, unsigned int),
					buffer, &buf_index, &count);
			else if (format[i] == 'u')
			{
				unsigned long int unum;
				int udigits = 0;
				int uzero_pad = 0;
				int upad_total;

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
					udigits = get_uint_len(unum, 10);
					if (precision > udigits)
						uzero_pad = precision - udigits;
					upad_total = udigits + uzero_pad;
					if (minus_flag)
					{
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
						for (j = upad_total; j < width; j++)
							add_to_buffer(buffer, &buf_index, ' ', &count);
					}
					else
					{
						char upad_char = zero_flag ? '0' : ' ';

						for (j = upad_total; j < width; j++)
							add_to_buffer(buffer, &buf_index, upad_char, &count);
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
			}
			else if (format[i] == 'o')
			{
				unsigned long int onum;
				int odigits = 0;
				int ozero_pad = 0;
				int opad_total;

				if (long_mod)
					onum = va_arg(args, unsigned long int);
				else if (short_mod)
					onum = (unsigned short int)va_arg(args, unsigned int);
				else
					onum = va_arg(args, unsigned int);
				if (onum == 0 && precision == 0)
				{
					for (j = 0; j < width; j++)
						add_to_buffer(buffer, &buf_index, ' ', &count);
				}
				else
				{
					odigits = get_uint_len(onum, 8);
					if (precision > odigits)
						ozero_pad = precision - odigits;
					if (hash_flag && onum != 0)
						ozero_pad++;
					opad_total = odigits + ozero_pad;
					if (minus_flag)
					{
						for (j = 0; j < ozero_pad; j++)
							add_to_buffer(buffer, &buf_index, '0', &count);
						if (long_mod)
							print_octal_long_buffer(onum,
								buffer, &buf_index, &count);
						else if (short_mod)
							print_octal_buffer((unsigned short int)onum,
								buffer, &buf_index, &count);
						else
							print_octal_buffer((unsigned int)onum,
								buffer, &buf_index, &count);
						for (j = opad_total; j < width; j++)
							add_to_buffer(buffer, &buf_index, ' ', &count);
					}
					else
					{
						char opad_char = zero_flag ? '0' : ' ';

						for (j = opad_total; j < width; j++)
							add_to_buffer(buffer, &buf_index, opad_char, &count);
						for (j = 0; j < ozero_pad; j++)
							add_to_buffer(buffer, &buf_index, '0', &count);
						if (long_mod)
							print_octal_long_buffer(onum,
								buffer, &buf_index, &count);
						else if (short_mod)
							print_octal_buffer((unsigned short int)onum,
								buffer, &buf_index, &count);
						else
							print_octal_buffer((unsigned int)onum,
								buffer, &buf_index, &count);
					}
				}
			}
			else if (format[i] == 'x' || format[i] == 'X')
			{
				unsigned long int xnum;
				int xdigits = 0;
				int xzero_pad = 0;
				int xpad_total;
				int uppercase = (format[i] == 'X');

				if (long_mod)
					xnum = va_arg(args, unsigned long int);
				else if (short_mod)
					xnum = (unsigned short int)va_arg(args, unsigned int);
				else
					xnum = va_arg(args, unsigned int);
				if (xnum == 0 && precision == 0)
				{
					for (j = 0; j < width; j++)
						add_to_buffer(buffer, &buf_index, ' ', &count);
				}
				else
				{
					xdigits = get_uint_len(xnum, 16);
					if (precision > xdigits)
						xzero_pad = precision - xdigits;
					xpad_total = xdigits + xzero_pad;
					if (hash_flag && xnum != 0)
						xpad_total += 2;
					if (minus_flag)
					{
						if (hash_flag && xnum != 0)
						{
							add_to_buffer(buffer, &buf_index, '0', &count);
							add_to_buffer(buffer, &buf_index,
								uppercase ? 'X' : 'x', &count);
						}
						for (j = 0; j < xzero_pad; j++)
							add_to_buffer(buffer, &buf_index, '0', &count);
						if (long_mod)
							print_hex_long_buffer(xnum, uppercase,
								buffer, &buf_index, &count);
						else if (short_mod)
							print_hash_hex((unsigned short int)xnum,
								0, uppercase, buffer, &buf_index, &count);
						else
							print_hash_hex((unsigned int)xnum,
								0, uppercase, buffer, &buf_index, &count);
						for (j = xpad_total; j < width; j++)
							add_to_buffer(buffer, &buf_index, ' ', &count);
					}
					else
					{
						char xpad_char = zero_flag ? '0' : ' ';

						if (zero_flag && precision == -1)
						{
							if (hash_flag && xnum != 0)
							{
								add_to_buffer(buffer, &buf_index, '0', &count);
								add_to_buffer(buffer, &buf_index,
									uppercase ? 'X' : 'x', &count);
							}
							for (j = xpad_total; j < width; j++)
								add_to_buffer(buffer, &buf_index, '0', &count);
						}
						else
						{
							for (j = xpad_total; j < width; j++)
								add_to_buffer(buffer, &buf_index, xpad_char, &count);
							if (hash_flag && xnum != 0)
							{
								add_to_buffer(buffer, &buf_index, '0', &count);
								add_to_buffer(buffer, &buf_index,
									uppercase ? 'X' : 'x', &count);
							}
						}
						for (j = 0; j < xzero_pad; j++)
							add_to_buffer(buffer, &buf_index, '0', &count);
						if (long_mod)
							print_hex_long_buffer(xnum, uppercase,
								buffer, &buf_index, &count);
						else if (short_mod)
							print_hash_hex((unsigned short int)xnum,
								0, uppercase, buffer, &buf_index, &count);
						else
							print_hash_hex((unsigned int)xnum,
								0, uppercase, buffer, &buf_index, &count);
					}
				}
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
