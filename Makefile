NAME = libftprintf.a

sources = ft_printf.c

sources_o = ft_pritnf.o

CC = cc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(sources_o)
	ar -crs $(NAME) $(sources_o)

functions_o: $(sources)
	$(CC) -c -o $(sources)

clean:
	rm -f $(sources_o)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all, clean, fclean, re
