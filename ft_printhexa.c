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
	ft_print_hex(num, count);
}

void	ft_print_p(va_list args, int *count)
{
	unsigned int	num;

	ft_printchar('0', count);
	ft_printchar('X', count);
	num = va_arg(args, unsigned int);
	ft_print_hex(num, count);
}

void	ft_print_hex(unsigned int n, int *count)
{
	if (n >= 16)
	{
		ft_print_hex(n / 16 , count);
		if (n % 16 > 9)
			ft_printchar(n % 16 + 48 + 39, count);
		else
			ft_printchar(n % 16 + 48 , count);
	}
	else 
	{
		if (n > 9)
			ft_printchar(n % 16 + 48 + 39 , count);
		else
			ft_printchar(n % 16 + 48 , count);
	}
}
