############
## COLORS ##
############

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

###############
## VARIABLES ##
###############

NAME	=	examples
CC		=	gcc
IFLAGS	=	-I../include -Iinclude -I/usr/include -Imlx
LFLAGS	=	-L../libs -lmlx -lmlx_Linux -lft -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
FFLAGS	=	-fsanitize=address
WFLAGS	=	-Wall -Wextra -Werror -g3
CFLAGS	=	$(WFLAGS)
CFLAGS	+=	$(IFLAGS)
#CFLAGS	+=	$(FFLAGS)
SRC_DIR	=	src/
BLD_DIR	=	build/

#############
## SOURCES ##
#############

SRC_FILES	=	display \
				examples \
				map \
				flood_fill
SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			=	$(addprefix $(BLD_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJF		=	.cache_exists

#############
## RECIPES ##
#############

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LFLAGS)

$(BLD_DIR)%.o:	$(SRC_DIR)%.c | $(OBJF)
	echo "$(YELLOW)Compiling: $<$(DEF_COLOR)"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
	mkdir -p $(BLD_DIR)
	mkdir -p $(addprefix $(BLD_DIR), $(dir $(SRC_FILES)))
	touch $(OBJF)
	echo "$(GREEN)Object directory created!$(DEF_COLOR)"

clean:
	rm -rf $(BLD_DIR) $(OBJF)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re