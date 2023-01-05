#include "ft_printf.h"

int	checkitem(char c, char *items)
{
	while (*items)
	{
		if (*items == c)
			return 1;
		items++;
	}
	return (0);
}

void	divider(char item, va_list args, int *count)
{
	if (item == 'c')
		ft_print_c(args, count);
	else if (item == 's')
		ft_print_s(args, count);
	else if (item == 'u')
		ft_print_u(args, count);
	else if (item == 'x')
		ft_print_x(args, count);
	else if (item == 'X')
		ft_print_X(args, count);
	else if (item == 'i' || item == 'd')
		ft_print_i(args, count);
	else if (item == 'p')
		ft_print_p(args, count);
	else if (item == '%')
		ft_printchar('%', count);
}

int	logicaprintf(char const *s, va_list args)
{
	char	*items;
	int		count;

	items = "cspxXidu%";
	count = 0;
	while (*s)
	{
		if (*s != '%')
			ft_printchar(*s, &count);
		else
		{
			s++;
			if (checkitem(*s, items) == 1)
				divider(*s, args, &count);
			else 
				return (0);
		}
		s++;
	}
	return (count);
}

int	ft_printf(char const *s, ...)
{
	int		count;
	va_list	args;

	va_start(args, s);
	count = logicaprintf(s, args);
	printf("count %i", count);
	va_end(args);
	return (count);
}

int	main(void)
{
	int	count;
	int	count_printf;
	int	number;
	int	*number_ptr;
	unsigned int	ptr;

	number = 125;
	number_ptr = &number;
	ptr = (unsigned int)&number;
	count = ft_printf("la %c,%s,%i,%p,%u,%u,%X,%x,%% patata\n", 'a', "pa", -2147483647, number_ptr, -1, 429465796, -200, ptr);
	count_printf = printf("ala %c,%s,%i,%p,%u,%u,%X,%x,%% patata\n", 'a', "pa", -2147483647, number_ptr, -1, 429465796,-200, ptr);
	printf("el count_meu es de: %i\n", count);
	printf("el count_printf es de: %i\n", count_printf);
	return (0);
}
