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

NAME	= libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
INCLUDE	= include
SRC_DIR	= src/
OBJ_DIR	= obj/
RM		= rm -f
AR		= ar rcs

#############
## SOURCES ##
#############

SRC_FILES =		ft_is/ft_isalnum \
				ft_is/ft_isalpha \
				ft_is/ft_isascii \
				ft_is/ft_isdigit \
				ft_is/ft_isprint \
				ft_mem/ft_memchr \
				ft_mem/ft_memcmp \
				ft_mem/ft_memcpy \
				ft_mem/ft_memmove \
				ft_mem/ft_memset \
				ft_put/ft_putchar_fd \
				ft_put/ft_putendl_fd \
				ft_put/ft_putnbr_fd \
				ft_put/ft_putstr_fd \
				ft_str/ft_strchr \
				ft_str/ft_strdup \
				ft_str/ft_striteri \
				ft_str/ft_strjoin \
				ft_str/ft_strlcat \
				ft_str/ft_strlcpy \
				ft_str/ft_strlen \
				ft_str/ft_strmapi \
				ft_str/ft_strncmp \
				ft_str/ft_strnstr \
				ft_str/ft_strrchr \
				ft_str/ft_strtrim \
				ft_str/ft_substr \
				ft_to/ft_atoi \
				ft_to/ft_itoa \
				ft_to/ft_tolower \
				ft_to/ft_toupper \
				ft_bzero \
				ft_calloc \
				ft_split

SRC		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF	= .cache_exists

###########
## BONUS ##
###########

BONUS_FILES =	ft_lst/ft_lstadd_back_bonus \
				ft_lst/ft_lstadd_front_bonus \
				ft_lst/ft_lstclear_bonus \
				ft_lst/ft_lstdelone_bonus \
				ft_lst/ft_lstiter_bonus \
				ft_lst/ft_lstlast_bonus \
				ft_lst/ft_lstmap_bonus \
				ft_lst/ft_lstnew_bonus \
				ft_lst/ft_lstsize_bonus

BONUS_SRC	= $(addprefix $(SRC_DIR), $(addsuffix .c, $(BONUS_FILES)))
BONUS_OBJ	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(BONUS_FILES)))

#############
## RECIPES ##
#############

all: $(NAME)

$(NAME): $(OBJF) $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@echo "$(YELLOW)Compiling $<$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(addprefix $(OBJ_DIR), $(dir $(SRC_FILES)))
	@mkdir -p $(addprefix $(OBJ_DIR), $(dir $(BONUS_FILES)))
	@touch $(OBJF)
	@echo "$(GREEN)Object directory created!$(DEF_COLOR)"

bonus: all $(OBJ) $(BONUS_OBJ)
	@$(AR) $(NAME) $(BONUS_OBJ)
	@echo "$(GREEN)$(NAME) compiled with bonus!$(DEF_COLOR)"

clean: 
	@$(RM) $(OBJ) $(BONUS_OBJ) $(OBJF)
	@$(RM) -r $(OBJ_DIR)
	@echo "$(RED)Objects removed!$(DEF_COLOR)"

fclean: clean 
	@$(RM) $(NAME)
	@echo "$(RED)$(NAME) removed!$(DEF_COLOR)"

re: fclean all
	
.PHONY: all bonus clean fclean re
