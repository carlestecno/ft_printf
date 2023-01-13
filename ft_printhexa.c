#include "ft_printf.h"

void	ft_print_x(va_list args, int *count)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	ft_print_hex(num, count);
}

void	ft_print_X(va_list args, int *count)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	ft_print_HEXA(num, count);
}

void	ft_print_p(va_list args, int *count)
{
	unsigned long int	num;

	ft_printchar('0', count);
	ft_printchar('X', count);
	num = va_arg(args, unsigned long int);
	ft_print_hexap(num, count);
}

void	ft_print_hexap(unsigned long int n, int *count)
{
	if (n >= 16)
	{
		ft_print_hexap(n / 16 , count);
		if (n % 16 > 9)
			ft_printchar(((n % 16) + 48 + 39), count);
		else
			ft_printchar(((n % 16) + 48 ), count);
	}
	else 
	{
		if (n > 9)
			ft_printchar(((n % 10) + 48 + 49), count);
		else
			ft_printchar(((n % 10) + 48) , count);
	}
}

void	ft_print_hex(unsigned int n, int *count)
{
	if (n >= 16)
	{
		ft_print_hex(n / 16 , count);
		if (n % 16 > 9)
			ft_printchar(((n % 16) + 48 + 39), count);
		else
			ft_printchar(((n % 16) + 48 ), count);
	}
	else 
	{
		if (n > 9)
			ft_printchar(((n % 10) + 48 + 49), count);
		else
			ft_printchar(((n % 10) + 48) , count);
	}
}

void	ft_print_HEXA(unsigned int n, int *count)
{
	if (n >= 16)
	{
		ft_print_HEXA(n / 16 , count);
		if (n % 16 > 9)
			ft_printchar(((n % 16) + 48 + 7), count);
		else
			ft_printchar(((n % 16) + 48 ), count);
	}
	else 
	{
		if (n > 9)
			ft_printchar(((n % 10) + 48 + 17), count);
		else
			ft_printchar(((n % 10) + 48) , count);
	}
}
