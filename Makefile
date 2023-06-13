##
## PALINDROME PROJECT, 2022
## makefile
## File description:
## makefile
##

CC ?= gcc

SRC	=	src/main.c 										\
		src/convert_base.c 								\
		src/find_first_palindrome.c						\
		src/palindromic_correspondances.c				\
		src/error_handling.c							\
		src/lib/my_revstr.c								\
		src/lib/convert_binary_decimal.c				\
		src/lib/my_int_to_str.c							\
		src/lib/is_number.c								\
		src/is_palindrome.c								\

UTSRC = src/main.c										\
		src/convert_base.c 								\
		src/find_first_palindrome.c						\
		src/palindromic_correspondances.c				\
		src/error_handling.c							\
		src/lib/my_revstr.c								\
		src/lib/convert_binary_decimal.c				\
		src/lib/my_int_to_str.c							\
		src/lib/is_number.c								\
		src/is_palindrome.c								\

UTDIR = src/test/unit_test.c

OBJ	=	$(SRC:.c=.o)

RM = rm -f

CPPFLAGS += -iquote./includes

CFLAGS += -Wall -Wextra -g3

NAME	=	palindrome

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CPPLAGS) $(CFLAGS)

tests_run:
	$(CC) $(UTSRC) $(UTDIR) $(CPPFLAGS) --coverage -lcriterion -o unit_tests
	./unit_tests

tests_clean:
		$(RM) unit_tests*

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	 fclean all

.PHONY = all clean fclean re
