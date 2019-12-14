NAME = libftprintf.a

SRCS = $(wildcard *.c)

GCC = gcc -Wall -Wextra -Werror

LIBFT = $(wildcard libft/*.c)

LIBFTOBJ = $(LIBFT:.c=.o)

$(NAME): $(SRCS) header.h
		 $(GCC) -c $(SRCS) $(LIBFT)
		 ar rc $(NAME) *.o
		 ranlib $(NAME)
all: $(NAME)

clean:
		rm -f *.o

fclean: clean
		rm -f $(NAME)

re: fclean all
