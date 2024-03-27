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
	op ops[] = {
		{'c', print_char},
		{'d', print_int},
		{'i', print_int},
		{'s', print_string},
		{'%', print_percent},
		{'\0', NULL}
	};
	va_list args;
	int i = 0, j;
	int count = 0, is_args = 0;

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i += 1;
			j = 0;

			while ((ops[j].type != format[i]) && (ops[j].type != '\0'))
				j += 1;

			if (ops[j].func == NULL)
			{
				putchar('%');
				putchar(format[i]);
				count += 2;
			}
			else
			{
				if (is_args == 0)
				{
					va_start(args, format);
					is_args = 1;
				}
				count += ops[j].func(&args);
			}
		}
		else
		{
			putchar(format[i]);
			count += 1;
		}

		i += 1;
	}

	if (is_args)
		va_end(args);

	return (count);
}
