#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - prints formatted output
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    int i = 0, count = 0;
    va_list args;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;

            if (format[i] == 'c')
            {
                char c = va_arg(args, int);
                write(1, &c, 1);
                count++;
            }
            else if (format[i] == 's')
            {
                char *str = va_arg(args, char *);
                int j = 0;

                if (str == NULL)
                    str = "(null)";

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
