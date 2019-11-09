NAME = libft.a
SRCS =	$(wildcard *.c)
OBJ =  $(wildcard *.o)
CC = gcc
CFLAGS +=-Wextra -Werror -Wall -I./
$(NAME): 	
	$(CC) $(FLAG) -c *.c 
	ar -rcs libft.a *.o
	ranlib ${NAME}
all: $(NAME)
clean:
	rm -f ${OBJ}
fclean:	clean
		rm -f ${NAME}
re:	fclean all
.PHONY: all fclean clean re