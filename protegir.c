#include <stdio.h>
#include <unistd.h>

int	ft_putchar(char ch, int *ptr)
{
	*ptr = write(1, &ch, 1);
	return (*ptr);
}

int	ft_putstring(char *str, int *ptr)
{
	int	count;

	count = 0;
	while (*str)
	{
		ft_putchar(*str, ptr);
		printf("\n*ptr:%i", *ptr);
		str++;
		count++;
	}
	return (count);
}
int	main(void)
{
	char	c;
	char	*str;
	int	count;
	int	*ptr;

	c = 'a';
	*ptr = 1;
	str = "patata";
	count = 0;
	if (*ptr != -1)
	{
		count = ft_putstring(str, ptr);
		printf("\n*ptr:%i", *ptr);
	}
	printf("\ncount: %i", count);
	return (0);
}
