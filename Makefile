NAME = fdf
LIBPATH = ./libft
LIBNAME = -lft
SRCS_DIR = ./srcs
IDIR = ./includes
MINILIB_PATH = ./minilibx_macos
OBJS_DIR = objs
CC = gcc
CFLAGS = -Wall -Wextra -Werror
_SRCS = ft_fdf.c \
		ft_fdf_init.c \
		ft_fdf_init_img.c \
		ft_fdf_map.c \
		ft_fdf_utils.c \
		ft_mouse_hook.c \
		ft_keyboard_hook.c \
		ft_zoom.c \
		ft_fdf_rotation.c \
		ft_fdf_init_color.c \
		ft_fdf_color.c \
		ft_fdf_draw.c \
		ft_fdf_isometric.c \
		ft_fdf_menu.c
SRCS = $(addprefix $(SRCS_DIR)/, $(_SRCS))
_OBJS = $(_SRCS:%.c=%.o)
OBJS = $(addprefix $(OBJS_DIR)/, $(_OBJS))

BLACK = \033[0;30m
GREEN = \033[0;32m
RED = \033[0;31m
BLINK = \033[5m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBPATH)
	@$(CC) $(OBJS) -o $(NAME) $(CFLAGS) -L$(LIBPATH) $(LIBNAME) -L$(MINILIB_PATH) -lmlx -framework OpenGL -framework AppKit
	@echo "\n$(NAME): $(GREEN)$(NAME) was created"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p objs
	@echo "$(GREEN).$(RESET)\c"
	@$(CC) -c -o $@ $< $(CFLAGS) -I$(IDIR) -I$(LIBPATH) -I$(MINILIB_PATH)
	

clean:
	@rm -f $(OBJS)
	@make -C $(LIBPATH) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBPATH) fclean
	
re: fclean all

.PHONY: all clean fclean re
