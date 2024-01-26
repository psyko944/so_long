NAME = so_long 
NAME_BONUS = so_long_bonus

SRCS = srcs/main.c \
	   srcs/get_map.c \
	   srcs/utils.c \
	   srcs/init.c \
	   srcs/draw_window.c \
	   srcs/hook.c \
	   srcs/move.c \
	   srcs_bonus/animations.c \
	   srcs/check_map.c \
	   srcs/swap_xpm.c \
	   srcs/algo.c
	   
# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
PURPLE= \033[38;2;255;105;180m
RESET= \033[0m

CC = cc

RM = rm -f
HEADER = so_long.h
MLX_DIR = minilibx
LIBFT_DIR = libft
PRINTF_DIR = ft_printf
MLX = $(MLX_DIR)/libmlx.a
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
MLXFLAGS = -L. -lXext -L. -lX11
CFLAGS = -Wall -Wextra -Werror -g3 -I.

OBJS = ${SRCS:.c=.o}
$(NAME): $(PRINTF) $(LIBFT) $(MLX) $(OBJS) 
		${CC} $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX) $(MLXFLAGS) -o $(NAME)

$(NAME_BONUS): $(PRINTF) $(LIBFT) $(MLX) $(OBJS) 
		${CC} $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX) $(MLXFLAGS) -o $(NAME_BONUS)

all:	$(NAME)
		@echo "$(GREEN)so_long compiled!$(DEF_COLOR)"

bonus: $(NAME_BONUS)

$(LIBFT):
				$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
				$(MAKE) -C $(PRINTF_DIR)
$(MLX):
				$(MAKE) -C $(MLX_DIR)
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"

clean:
	@$(MAKE) -C $(MLX_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(RM) ${OBJS}
	@echo "$(BLUE)so_long object files cleaned!$(DEF_COLOR)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@$(RM) $(NAME) $(NAME_BONUS)
	@echo "$(CYAN) have been deleted$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for so_long!$(DEF_COLOR)"

.PHONY: all clean fclean re minilibx libft printf bonus
