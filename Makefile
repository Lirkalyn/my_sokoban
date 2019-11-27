##
## EPITECH PROJECT, 2019
## Day_10
## File description:
## makefile
##
.PHONY : clean fclean re

SRC	=	my_sokoban.c \
		my_str_to_word_array.c \
		finder_and_moves.c \
		finder_and_more.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(SRC) -lncurses

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean $(NAME)
