#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * print_char - prints a char
 * @args: the char to be printed
 *
 * Return: On success, the number of characters printed
 */
int print_char(va_list *args)
{
	char c = va_arg(*args, int);

	putchar(c);

	return (1);
}

/**
 * print_int - prints an int
 * @args: the int to be printed
 *
 * Return: On success, the number of characters printed
 */
int print_int(va_list *args)
{
	char *buffer;
	int count = 0, mult = 1, i = 0;
	int d = va_arg(*args, int);

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
		return (0);

	if (d < 0)
	{
		putchar('-');
		mult = -1;
		count += 1;
	}

	while (d != 0)
	{
		buffer[i] = ((d % 10) * mult) + 48;
		d = d / 10;
		i += 1;
	}

	while (i > 0)
	{
		putchar(buffer[i - 1]);
		count += 1;
		i -= 1;
	}

	free(buffer);

	return (count);
}

/**
 * print_string - prints a string
 * @args: the string to be printed
 *
 * Return: On success, the number of characters printed
 *         On error, -1
 */
int print_string(va_list *args)
{
	int len = 0;
	char *s = va_arg(*args, char *);

	if (s)
	{
		while (s[len] != '\0')
		{
			putchar(s[len]);
			len += 1;
		}
		return (len - 1);
	}
	else if (!s)
	{
		printf("(null)");
		return (6);
	}
	else
	{
		printf("s both exists and doesn't exist");
		return (-1);
	}

}

/**
 * print_percent - prints a percent
 * @args: unused
 *
 * Return: On success, the number of characters printed
 */
int print_percent(va_list *args)
{
	(void)args;

	putchar('%');

	return (1);
}

