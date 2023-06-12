##
## PALINDROME PROJECT, 2022
## makefile
## File description:
## makefile
##

SRC	=	src/main.c 										\
		src/convert_base.c 								\
		src/find_first_palindrome.c						\
		src/error_handling.c							\
		src/lib/my_revstr.c								\
		src/lib/my_int_to_str.c							\
		src/lib/is_number.c								\
		src/is_a_palindrome.c							\

CC ?= gcc

OBJ	=	$(SRC:.c=.o)

RM = rm -f

CPPFLAGS += -iquote./includes

CFLAGS += -Wall -Wextra -g3

NAME	=	palindrome

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CPPLAGS) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	 fclean all

.PHONY = all clean fclean re
