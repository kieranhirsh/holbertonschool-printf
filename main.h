#ifndef PRINTF
#define PRINTF

#include <stdarg.h>

/**
 * struct operations - ties a data type to a corresponding function
 * @tpye: the data type
 * @func: the function
 *
 * Description: this struct stores a char with the corresponding function
 *              that prints an argument of the specified data type
 */
typedef struct operations
{
	char type;
	int (*func)(va_list *args);
} op;

int _printf(const char *format, ...);
int print_char(va_list *args);
int print_int(va_list *args);
int print_string(va_list *args);
int print_percent(va_list *args);

#endif
