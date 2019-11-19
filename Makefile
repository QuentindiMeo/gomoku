##
## PERSONAL PROJECT, 2019
## gomoku
## File description:
## Makefile
##

SRC	=	src/help.c		\
		src/error.c		\
		src/detectors3.c	\
		src/detectors2.c	\
		src/detectors.c		\
		src/game_loop.c		\
		src/swap2_rule.c	\
		src/setup2.c		\
		src/setup.c		\
		src/malloc_free.c	\
		src/main_gomoku.c	\

OBJ	=	$(SRC:.c=.o)

HEADER_PATH     =       include/

CC	=	@gcc

LIB     =       include/libmy.a

CFLAGS	=	-I $(HEADER_PATH) -Wall -Werror -Wextra --pedantic

NAME	=	gomoku

.PHONY: clean fclean re gomoku

all: $(NAME)

$(NAME): $(OBJ)
	@echo Compiling \'$(NAME)\'
	$(CC) -o $(NAME) $(OBJ) $(LIB)
	@echo \'$(NAME)\' compiled successfully

clean:
	@rm -rf $(OBJ)
	@echo Cleaned .o for \'$(NAME)\'

fclean:	clean
	@rm -rf $(NAME)
	@echo Cleaned \'$(NAME)\'

re: fclean all
