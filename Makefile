# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/16 17:37:37 by yyaniv            #+#    #+#              #
#    Updated: 2025/09/07 11:46:42 by yyaniv           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cub3D

CC				= cc
OBJDIR 			= ./bin
INCLUDE_DIR 	= ./header
INCLUDE_FILE	= $(INCLUDE_DIR)/cub3D.h
SRC				:= ./get_next_line/get_next_line.c \
./get_next_line/get_next_line_utils.c \
./srcs/utils.c \
./srcs/main.c \
./srcs/ft_init.c \
./srcs/ft_init_tuxture.c \
./srcs/ft_check.c \
./srcs/free_exit_error.c \
./srcs/parsing/pars_utils.c \
./srcs/parsing/pars_player.c \
./srcs/parsing/ft_parsing.c \
./srcs/parsing/find_grid.c \
./srcs/parsing/check_textures.c \
./srcs/parsing/check_map.c \
./srcs/parsing/check_grid.c \
./srcs/parsing/check_colors.c \
./srcs/execution/ft_update_sprite_animation.c \
./srcs/execution/ft_texture_params_init.c \
./srcs/execution/ft_move_camera.c \
./srcs/execution/ft_mouse_handler.c \
./srcs/execution/ft_mlx_pixel_put.c \
./srcs/execution/ft_mini_map.c \
./srcs/execution/ft_keypress_handler.c \
./srcs/execution/ft_initialisation_textures.c \
./srcs/execution/ft_initialisation_main_texture.c \
./srcs/execution/ft_init_sprite_frames.c \
./srcs/execution/ft_init_drawing_params.c \
./srcs/execution/ft_get_tetxure_color.c \
./srcs/execution/ft_draw.c \
./srcs/execution/ft_draw_line_of_texture.c \
./srcs/execution/ft_digital_differential_analyzer.c \
./srcs/execution/ft_destroy_handler.c \
./srcs/execution/ft_compute_wall_projection.c \
./srcs/execution/ft_clear_window.c \
./srcs/execution/ft_calculate_start_step.c \
./srcs/execution/ft_calculate_distance_to_wall.c \
./srcs/execution/ft_movement.c

OBJS			:= $(patsubst %.c,$(OBJDIR)/%.o,$(SRC))

HEADERS 		= -I$(INCLUDE_DIR) -I./libft
LIBFT			= ./libft/libft.a

DEBUG			= -g3
CFLAGS			= -Wall -Wextra -Werror -o3

RM				= @rm

MLX_DIR			= ./mlx
MLX_LIB			= $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS		= -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

all: $(MLX_LIB) $(NAME)

$(OBJDIR)/%.o: ./%.c $(INCLUDE_FILE)
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(NAME): $(LIBFT)  $(OBJDIR) $(OBJS)
		$(CC)  $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(MLX_FLAGS)
	@echo "$(GREEN)$(BOLD)[ ★ SUCCESS ★ ]$(BOLD_R)$(RESET): Type './cub3d ' to execute."

mlx:
		@mkdir mlx;
		git clone https://github.com/42Paris/minilibx-linux.git mlx;

$(MLX_LIB):
		@make -C $(MLX_DIR)

$(LIBFT):
	@make -C ./libft bonus --no-print-directory -s
		
$(OBJDIR):
	@mkdir $@

clean:
	$(RM) -rf $(OBJDIR)
	@make -C ./libft clean --no-print-directory

fclean: clean
	$(RM) -f $(NAME)
	@make -C ./libft fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re mlx

BOLD	= \e[1m
BOLD_R	= \e[0m

GREEN	= \033[0;32m
RESET	= \033[0m
