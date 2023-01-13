#include "ft_printf.h"

int	checkwrite(int w)
{
	if (w != 1)
		return (-1);
	return (1);
}

void	ft_printchar(char c, int *count)
{
	int	w;

	w = write(1, &c, 1);
	checkwrite(c);
	(*count)++;
}

void	ft_print_s(va_list args, int *count)
{
	char	*ch;

	ch = va_arg(args, char*);
	while (*ch)
	{
		ft_printchar(*ch, count);
		ch++;
	}
}

void	ft_print_c(va_list args, int *count)
{
	char	ch;

	ch = va_arg(args, int);
	ft_printchar(ch, count);
}
