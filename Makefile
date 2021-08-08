CC		=	gcc

NAME	=	runner

CFLAGS	+=	-I./include -W -Wall -Werror -Wextra

LIBS	+=	-lSDL2 -lSDL2_image

SRC		=	src/main.c	\
			src/draw.c	\
			src/input.c	\

OBJ		=	$(SRC:%.c=%.o)

RM		=	rm -f *.o core

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			$(CC) $(OBJ) $(LIBS) $(CFLAGS) -o $(NAME) 

clean	:
			rm -f $(OBJ)

fclean	:		clean
			rm -f $(NAME)

re		:	fclean all lib

.PHONY	:	all src lib clean fclean re
