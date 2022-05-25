# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 14:10:06 by fmauguin          #+#    #+#              #
#    Updated: 2022/05/25 14:49:17 by fmauguin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_PATH	=	srcs/
SRCS_FILES	=	test.c
SRCS		=	$(addprefix $(SRCS_PATH), $(SRCS_FILES))
OBJS		=	$(SRCS:.c=.o)
INCLUDE		=	include/
LIBFT_PATH	=	libft/
LIBFT		=	libft.a
NAME		=	program

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -I$(INCLUDE)

all:		$(NAME)

$(NAME): 	message libft_build $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

libft_build: 
			@make -C $(LIBFT_PATH)
			@cp $(LIBFT_PATH)$(LIBFT) .
			@make fclean -C $(LIBFT_PATH)

clean:
			@rm -f $(OBJS)
			@echo "clean done"

fclean:		clean
			@rm -f $(NAME)
			@rm -f $(LIBFT)
			@echo "fclean done"

re:			fclean all

message: 
		@echo "Building $(NAME)"