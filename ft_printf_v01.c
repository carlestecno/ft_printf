#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char ch)
{
	write(1, &ch, 1);
	return (1);
}

int	ft_putstring(char *s)
{
	int	count;

	count = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		write(1, s, 1);
		count++;
		s++;
	}
	return (count);
}

int	ft_putinteger(int number, int count)
{
	if (number == -2147483648)
	{
		write(1, "-2147483648", 1);
		return (11);
	}
	else
	{
		if (number < 0)
		{
			write(1, "-", 1);
			number *= -1;
			count ++;
		}
		if (number > 9)
			count = ft_putinteger(number / 10, count);
		count++;
		number = number % 10 + 48;
		write(1, &number ,1);
	}
	return (count);
}

int	ft_putadress(unsigned int number,char c, int count)
{
	int	var;

	var = 16;
	if (c == 'p')
	{
		if (count == 0)
		{
			write(1, "0x", 2);
			count += 2;
		}
	}
	if (c == 'u')
		var = 10;
	if (number > var)
		count = ft_putadress(number / var, c, count);	
	number %= var;
	if (number >= 10 && number <= 15)
		if (c == 'x' || c == 'p')
			number += 39;
		else
			number += 7;	
	number += 48;
	count++;
	write(1, &number, 1);
	return (count);
}

	
int	ft_printf(char const *s, ...)
{
	int	count;
	va_list	args;

	count = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s != '%')
			count += ft_putchar(*s);
		if (*s	==  '%')
		{
			s++;
			if (*s == 'c' || *s == '%')
				count += ft_putchar(va_arg(args, int));
			if (*s == 's')
				count += ft_putstring(va_arg(args, char *));
			if (*s == 'd' || *s == 'i')
				count += ft_putinteger(va_arg(args, int), 0);
			if (*s == 'p' || *s == 'x' || *s == 'X' || *s == 'u')
				count += ft_putadress(va_arg(args, unsigned int), *s, 0);
		}
	s++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	int	count;
	int	count2;
	int	number;
	int	*ptr;

	number = 125;
	ptr = &number;
	count = ft_printf("abc%c,%s,%i,%p,%u,%u,%x,%X,%%\n", 'a', "string", -12563, ptr, -1, 429546796, -200, -200);
	printf("count = %i\n", count);	
	count2 = printf("abc%c,%s,%i,%p,%u,%u,%X,%x,%%\n", 'a', "string", -12563, ptr, -1, 429546796, -200, -200);

	printf("count2 = %i\n", count2);
	return (0);
}
