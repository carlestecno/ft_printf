#include <unistd.h>
#include <stdio.h>

int	ft_printchar(char c)
{
	int	j;

	j = 1;
	j = write(1, &c, 1);
	return (j);
}

int	main(void)
{
	int	(*var)(char);
	char	str;

	str = 'a';
	var = &ft_printchar;
	if (var(str) == 1)
		write(1, "error", 5);
	else
		write(1, "ok", 2);
	return (0);
}
	
