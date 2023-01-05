#include "ft_printf.h"

void	ft_print_num(unsigned int n, unsigned int tipus, int *count)
{
	if (n >= tipus)
	{
		ft_print_num(n / tipus, tipus , count);
		if (tipus == 16 && n % tipus > 9)
			ft_printchar(n %= tipus + 48 + 7, count);
		else
			ft_printchar(n %= tipus + 48 , count);
	}
	else
	{
		if (tipus == 16)
		{
			if (n > 9)
				ft_printchar(n %= tipus + 48 + 7, count);
			else
				ft_printchar(n %= tipus + 48 , count);
		}
		else
			ft_printchar(n %= tipus + 48 , count);
	}
}

void	ft_print_integer(int num, int *count)
{
	if(num < 0)
	{
		num *= -1;
		ft_printchar('-', count);
	}
	if (num >= 10)
	{
		ft_print_integer(num / 10, count);
		ft_printchar((num %= 10 + 48), count);
	}
	else
		ft_printchar ((num %= 10 + 48), count);
}

void	ft_print_i(va_list args, int *count)
{
	char	*str;
	int		num;

	num = va_arg(args, int);
	if (num == -2147483648)
	{
		str = "-2147483648";
		ft_print_n(str, count);
	}
	ft_print_integer(num, count);
}

void	ft_print_u(va_list args, int *count)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	ft_print_num(num, 10, count);
}

void	ft_print_n(char *num, int *count)
{
	while (*num)
	{
		ft_printchar(*num, count);
		num++;
	}
}
