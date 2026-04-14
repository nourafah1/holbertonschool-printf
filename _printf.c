#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_number - prints an integer
 * @n: the number to print
 * Return: number of characters printed
 */
int print_number(long int n)
{
int count = 0;
char digit;
long int temp;

if (n < 0)
{
write(1, "-", 1);
count++;
n = -n;
}
if (n >= 10)
count += print_number(n / 10);
temp = n % 10;
digit = temp + '0';
write(1, &digit, 1);
count++;
return (count);
}

/**
 * _printf - prints formatted output
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
int i = 0, count = 0, j;
char *str, c;
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
va_end(args);
return (-1);
}
if (format[i] == 'c')
{
c = va_arg(args, int);
write(1, &c, 1);
count++;
}
else if (format[i] == 's')
{
str = va_arg(args, char *);
if (str == NULL)
str = "(null)";
j = 0;
while (str[j])
{
write(1, &str[j], 1);
j++;
count++;
}
}
else if (format[i] == '%')
{
write(1, "%", 1);
count++;
}
else if (format[i] == 'd' || format[i] == 'i')
{
int num = va_arg(args, int);
count += print_number((long int)num);
}
else
{
write(1, "%", 1);
write(1, &format[i], 1);
count += 2;
}
}
else
{
write(1, &format[i], 1);
count++;
}
i++;
}
va_end(args);
return (count);
}
