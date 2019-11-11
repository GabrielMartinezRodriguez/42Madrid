NAME = libft.a
SRCS =	$(wildcard *.c)
OBJ =  $(wildcard *.o)
CC = gcc
CFLAGS +=-Wextra -Werror -Wall -I./
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -c $(SRCS)
	ar -rcs libft.a $(OBJ)
	ranlib ${NAME}
all: $(NAME)
clean:
	rm -f ${OBJ}
fclean:	clean
		rm -f ${NAME}
re:	fclean all
.PHONY: all fclean clean re
