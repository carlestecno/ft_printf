#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>


int	ft_put_char(int ch, int *count)
{
	write(1, &ch, 1);
	return (1);
}

int	ft_putchar(char ch)
{
	write(1, &ch, 1);
	return (1);
}
	
int	ft_printf(char const *s, ...)
{
	int	*count;
	va_list	args;

	va_start(args, s);
	while (*s)
	{
		if (*s != '%')
			count += ft_putchar(*s);
		if (*s	==  '%')
		{
			s++;
			if (*s == 'c' || *s == '%')
				count += ft_put_char(va_arg(args, int), count);
		}
	s++;
	va_end(args);
	return (*count);
	}
}

int	maint(void)
{
	int	count;
	int	count2;
	

	count = ft_printf("abc%c", 'a');
	printf("count = %i", count);	
}
