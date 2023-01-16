#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char ch, int *j)
{
	*j = write(1, &ch, 1);
	return (*j);
}

int	ft_putstring(char *s, int *j)
{
	int	count;

	count = 0;
	while (*s)
	{
		ft_putchar(*s, j);
		count++;
		s++;
	}
	return (count);
}

int	ft_putinteger(int number, int count, int *j)
{
	if (number == -2147483648)
	{
		*j = write(1, "-2147483648", 11);
	}
	else
	{
		if (number < 0)
		{
			ft_putchar('-', j);
			number *= -1;
			count++;
		}
		if (number > 9)
			count = ft_putinteger(number / 10, count, j);
		count++;
		number = number % 10 + 48;
		ft_putchar(number, j);
	}
	return (count);
}

int	ft_puthexa(unsigned int number,char c, int count, int *j)
{
	unsigned int	var;

	var = 16;
	if (c == 'u')
		var = 10;
	if (number >= var)
		count = ft_puthexa(number / var, c, count, j);	
	number %= var;
	if (number >= 10 && number <= 15)
	{
		if (c == 'x' || c == 'p')
			number += 39;
		else
			number += 7;	
	}
	number += 48;
	count++;
	ft_putchar(number, j);
	return (count);
}

int	ft_putaddress(unsigned long int number, int count, int *j)
{
	if (count == 0)
	{
		ft_putchar('0', j);
		ft_putchar('x', j);
		count += 2;
	}
	if (number >= 16)
		count = ft_putaddress(number / 16, count, j);
	number %= 16;
	if (number >= 10 && number <= 15)
			number += 39;
	number += 48;
	count++;
	ft_putchar(number, j);
	return (count);
}

int	ft_printf(char const *s, ...)
{
	int	count;
	va_list	args;
	int	*j;
	int	value;

	value = 1;
	j = &value;
	count = 0;
	va_start(args, s);
	while (*s && *j != -1)
	{
		if (*s != '%')
			count += ft_putchar(*s, j);
		if (*s	==  '%')
		{
			s++;
			if (*s == 'c')
				count += ft_putchar(va_arg(args, int), j);
			else if (*s == '%')
				count += ft_putchar('%', j);
			else if (*s == 's')
				count += (ft_putstring(va_arg(args, char*), j));
			else if (*s == 'd' || *s == 'i')
				count += ft_putinteger(va_arg(args, int), 0, j);
			else if (*s == 'x' || *s == 'X' || *s == 'u')
				count += ft_puthexa(va_arg(args, unsigned int), *s, 0, j);
			else if (*s == 'p')
				count += ft_putaddress(va_arg(args, unsigned long int), 0, j);
		}
	if (*j == -1)
		return (-1);
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
	count = ft_printf("abc%c,%s,%i,%p,%u,%u,%x,%X,%%\n", 'a',"patata", -2147483647, ptr, -1, 429546796, -200, -200);
	printf("count = %i\n", count);	
	count2 = printf("abc%c,%s,%i,%p,%u,%u,%x,%X,%%\n", 'a', "patata", -2147483647, ptr, -1, 429546796, -200, -200);

	printf("count2 = %i\n", count2);
	return (0);
}
