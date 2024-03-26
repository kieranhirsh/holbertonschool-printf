#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - prints the string to the command line
 * @format: character string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	int count = 0;

	if (format[0] == '\0')
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c': /* to print %c */
					{
						char c = va_arg(args, int);

						putchar(c);
						count++;
						break;
					}
				case 's': /* to print %s */
					{
						char *s = va_arg(args, char *);

						while (*s)
						{
							putchar(*s);
							s++;
							count++;
						}
						break;
					}
				case 'i': /* to print %i */
				case 'd': /* to print %d */
					{
						int d = va_arg(args, int);

						if (d < 0)
						{
							putchar('-');
							d = d * (-1);
						}

						while (d != 0)
						{
							putchar(d % 10 + '0');
							d = d / 10;
							count++;
						}
						break;
					}
				case '%': /* to print %% */
					{
						putchar('%');
						count++;
						break;
					}
				default: /* for unrecognised format specifiers */
					{
						putchar('%');
						putchar(format[i]);
						count += 2;
						break;
					}
			}
		}
		else
		{
			putchar(format[i]);
			count++;
		}
		i++;
	}

	va_end(args);
	return (count);
}
