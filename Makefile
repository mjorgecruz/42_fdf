# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masoares <masoares@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 14:10:23 by masoares          #+#    #+#              #
#    Updated: 2023/12/07 16:01:22 by masoares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g 

LIBFLAGS = -lXext -lX11 -lm -lz -O3

SRCS = fdf.c fdf_utils.c handlers.c image_creator.c \
	render.c map_converter.c errors.c freeing.c \
	mathings.c bresenham.c controls.c controls_2.c

BONUS_SRCS =

NAME = fdf

LIBFT = ./libft/libft.a

MLX = ./minilibx-linux/libmlx.a

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(LIBFT) $(LIBFLAGS) -o $(NAME) 
$(MLX):
	make -C ./minilibx-linux

$(LIBFT):
	make -C ./libft

fclean: clean
	rm -f fdf
	rm -f fdf_bonus
	make fclean -C ./libft

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)
	make clean -C ./libft
	make clean -C ./minilibx-linux

re: fclean all

.PHONY: all fclean clean re