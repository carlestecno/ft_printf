#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>

void	ft_atoi(int number)
{
	if (number == -2147463648)
		write(1, "-2147463648", 11);
	else
	{
		if (number < 0)
		{
			write(1, "-", 1);
			number *= -1;
		}
		if (number > 9)
			ft_atoi(number / 10);
		number %= 10;
		number += 48;
		write(1, &number, 1);
	}
}

int	count_atoi(int number)
{
	int count;

	count = 0;
	if (number == -2147483648)
		return (11);
	if (number < 0)
	{
		number *= -1;
		count++;
	}
	while (number > 9)
	{
		number /= 10;
		count++;
	}
	count++;
	return (count);
}

void	ft_address_hexa(uintptr_t number, char c)
{
	if (c == 'u')
	{
		if (number > 9)
			ft_address_hexa(number / 10, c);
		number = number % 10 + 48;
		write(1, &number, 1);
	}
	else
	{
		if (number > 15)
			ft_address_hexa(number / 16, c);
		number %= 16;
		if (number >= 10 && number <= 15)
		{
			if (c == 'X')
				number += 7;
			else
				number += 39;
		}
		number += 48;
		write(1, &number, 1);
	}	
}
int	count_ft(uintptr_t number, char c)
{
	int			count;
	uintptr_t	var;

	if (c == 'p')
	{
		count = 2;
		var = 16;
	}
	else if (c == 'x' || c == 'X' || c == 'u')
	{
		count = 0;
		if (c == 'u')
			var = 10;
		else
			var = 16;
	}
	while (number > var)
	{
		number /= var;
		count++;
	}
	count++;
	return (count);
}

int	ft_putstring(char *s)
{
	int	count;
	int	w;

	count = 0;
	while (*s)
	{
		w = write(1, s, 1);
		if (w != 1)
			return (-1);
		s++;
		count++;
	}
	return (count);
}
int	ft_putchar(int c)
{
	int	w;
	
	w = write (1, &c ,1);
	return (1);
}

int	ft_printf(char const *s, ...)
{
	int			ch;
	char		*str;
	va_list		ptr;
	int			count;
	uintptr_t	ptr_u;

	count = 0;
	va_start(ptr, s);
	while (*s)
	{
		if (*s != '%')
			count += ft_putchar(*s);
		if (*s == '%')
		{
			s++;
			if (*s == 'c')
			{
				ch = va_arg(ptr, int);
				count += ft_putchar(ch);
			}
			if (*s == 's')
			{
				str = va_arg(ptr, char*);
				count += (ft_putstring(str));
			}
			if (*s == 'd' || *s == 'i')
			{
				ch = va_arg(ptr, int);
				ft_atoi(ch);
				count += count_atoi(ch);
			}
			if (*s == 'p' || *s == 'u' || *s == 'X' || *s == 'x')
			{
				if (*s == 'p')
					write(1, "0x", 2);
				ptr_u = va_arg(ptr, uintptr_t);
				ft_address_hexa((uintptr_t) ptr_u, *s);
				count += count_ft((uintptr_t) ptr_u, *s);
			}
			if (*s == '%')
			{
				count += ft_putchar(*s);
			}
		}
	s++;
	}
	va_end(ptr);
	return (count);
	}

int	main(void)
{
	int	count;
	int	count_printf;
	int	number;
	int	*number_ptr;
	uintptr_t	ptr;

	number = 125;
	number_ptr = &number;
	ptr =(uintptr_t) &number;
	count = ft_printf("la %c,%s,%i,%p,%u,%u,%X,%x,%% patata\n", 'a', "pa", -2147483647, number_ptr, -1, 429465796, -200, ptr);
	count_printf = printf("la %c,%s,%i,%p,%u,%u,%X,%x,%% patata\n", 'a', "pa", -2147483647, number_ptr, -1, 429465796,-200, ptr);
	printf("el count_meu es de: %i\n", count);
	printf("el count_printf es de: %i\n", count_printf);
	return (0);
}
