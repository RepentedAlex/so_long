
CC	=	gcc

NAME	=	so_long

all:	submodules $(NAME)

submodules:
	make -C

$(NAME):