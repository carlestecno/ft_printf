#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int		checkitem(char c, char *items);
void	divider(char item, va_list args, int *count);
int		logicaprintf(char const *s, va_list args);
int		ft_printf(char const *s, ...);
void	ft_print_x(va_list args, int *count);
void	ft_print_X(va_list args, int *count);
void	ft_print_p(va_list args, int *count);
void	ft_print_hex(unsigned int n, int *count);
void	ft_print_HEXA(unsigned int n, int *count);
void	ft_print_hexap(unsigned long int n, int *count);
void	ft_print_num(unsigned int n, unsigned int tipus, int *count);
void	ft_print_integer(int num, int *count);
void	ft_print_i(va_list args, int *count);
void	ft_print_u(va_list args, int *count);
int		checkwrite(int w);
void	ft_printchar(char c, int *count);
void	ft_print_s(va_list args, int *count);
void	ft_print_c(va_list args, int *count);
void	ft_print_n(char *num, int *count);

#endif
