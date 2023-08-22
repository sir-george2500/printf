#include "main.h"

/**
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char * const format, ...)
{
    convert_match m[] = {
        {"%X", printf_HEX},
       {"%c", printf_char},
       {"%x", printf_hex},
       {"%b", printf_bin},

    };

    va_list args;
    int i = 0, len = 0;

    va_start(args, format);
    if (format == NULL)
        return (-1);

    while (format[i] != '\0')
    {
        if (format[i] == '%' && format[i + 1] != '\0')
        {
            int j = 0;
            while (j < (int)(sizeof(m) / sizeof(m[0])))
            {
                if (m[j].id[0] == '%' && m[j].id[1] == format[i + 1])
                {
                    len += m[j].f(args);
                    i += 2;
                    break;
                }
                j++;
            }
        }
        else
        {
            _putchar(format[i]);
            len++;
            i++;
        }
    }
    va_end(args);
    return (len);
}
