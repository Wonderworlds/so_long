# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 14:10:06 by fmauguin          #+#    #+#              #
#    Updated: 2022/05/26 17:04:59 by fmauguin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_PATH	=	srcs/
SRCS_FILES	=	test.c color_handler.c key_event.c mouse_event.c tex_handler.c
SRCS		=	$(addprefix $(SRCS_PATH), $(SRCS_FILES))
OBJS		=	$(SRCS:%.c=%.o)
NOBJS		=	$(SRCS:%.c=%.o)
INCLUDE		=	includes/
LIBFT_PATH	=	libft/
MLX_PATH	=	minilibx-linux/
LIBFT		=	libft.a
LINK		=	-L$(MLX_PATH) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -L$(LIBFT_PATH) -lft 
NAME		=	so_long

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -I$(INCLUDE) -I/usr/include -Imlx_linux -O3
NOFLAGS		=	-I$(INCLUDE) -I/usr/include -Imlx_linux -O3

all:		$(NAME)

$(NAME): 	message libft_build $(OBJS)
			$(CC) $(NOFLAGS) $(OBJS) $(LINK)-o $(NAME) 

%.o: %.c
			$(CC) $(NOFLAGS) -c $< -o $@

libft_build: 
			@make -C $(LIBFT_PATH)

clean:
			@rm -f $(OBJS)
			@make clean -C $(LIBFT_PATH)
			@echo "clean done"

fclean:		clean
			@rm -f $(NAME)
			@make fclean -C $(LIBFT_PATH)
			@echo "fclean done"

re:			fclean all

message: 
		@echo "Building $(NAME)"
