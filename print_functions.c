#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_char - prints a char
 * @args: the char to be printed
 *
 * Return: On success, the number of characters printed
 *         On error, -1 is returned, and errno is set appropriately.
 */
int print_char(va_list *args)
{
	char c = va_arg(*args, int);

	putchar(c);

	return (1);
}

/**
 * print_string - prints a string
 * @args: the string to be printed
 *
 * Return: On success, the number of characters printed
 *         On error, -1 is returned, and errno is set appropriately.
 */
int print_string(va_list *args)
{
	int len = 0, count = 0;
	char *s = va_arg(*args, char *);

	while (s[len] != '\0')
	{
		putchar(s[len]);
		len += 1;
		count += 1;
	}

	return (count);
}

/**
 * print_percent - prints a percent
 * @args: unused
 *
 * Return: On success, the number of characters printed
 *         On error, -1 is returned, and errno is set appropriately.
 */
int print_percent(va_list *args)
{
	(void)args;

	putchar('%');

	return (1);
}

