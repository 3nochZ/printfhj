#include "main.h"
#include <stdarg.h>

/**
 * _printf - prints a string
 * @format: a pointer
 * Return: 0 if successfull
 */

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c': {
						  int c = va_arg(args, int);
						  _putchar(c);
						  count++;
						  break;
					  }
				
				case 's': {
						  const char *s = va_arg(args, const char *);
						  while (*s != '\0')
						  {
							  _putchar(*s);
							  s++;
							  count++;
						  }

						  break;
					  }
					  
				case '%': {
						  _putchar('%');
						  count++;
						  break;
					  }
			}
		}
		
		else
		{
			_putchar(*format);
			count++;
		}

		format++;
	}

	va_end(args);
	return(count);
}
