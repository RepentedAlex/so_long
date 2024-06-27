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

NAME	=	so_long
CC		=	gcc
IFLAGS	=	-Iinclude -I./extras/Libft/include -I./extras/minilibx-linux
LFLAGS	=	-L./libs -lft -lmlx -lmlx_Linux -L/usr/lib -I./extras/minilibx-linux/mlx_linux -lXext -lX11 -lm -lz
FFLAGS	=	-fsanitize=address
WFLAGS	=	-Wall -Wextra -Werror -g3
CFLAGS	=	$(WFLAGS) $(IFLAGS)
#CFLAGS	+=	$(FFLAGS)
SRC_DIR	=	src/
BLD_DIR	=	build/
LIBFT	=	extras/Libft

#############
## SOURCES ##
#############

SRC_FILES	=	so_long \
				display \
				display2 \
				initialisation \
				inputs_handler \
				flood_fill \
				map_utils \
				map_utils2 \
				map_utils3 \
				map_utils4 \
				movement \
				movement2 \
				movement3 \
				textures \
				textures2
SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			=	$(addprefix $(BLD_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJF		=	.cache_exists

#############
## RECIPES ##
#############

all:	$(NAME)

$(NAME):	$(OBJ)
	@echo "$(BLUE)Linking $<$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LFLAGS)
	@echo "$(GREEN)$< linked !$(DEF_COLOR)"

$(BLD_DIR)%.o:	$(SRC_DIR)%.c | $(OBJF)
	@echo "$(BLUE)Compiling: $<$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
	@mkdir -p $(BLD_DIR)
	@mkdir -p $(addprefix $(BLD_DIR), $(dir $(SRC_FILES)))
	@touch $(OBJF)
	@echo "$(BLUE)Object directory created!$(DEF_COLOR)"

clean:
	@rm -rf $(BLD_DIR) $(OBJF)
	@echo "$(MAGENTA)Build files cleaned!$(DEF_COLOR)"

fclean:	clean
	@rm -f $(NAME)
	@echo "$(MAGENTA)$(NAME) cleaned!$(DEF_COLOR)"

re:	fclean all

.PHONY:	all clean fclean re