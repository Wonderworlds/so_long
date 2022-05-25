# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 18:25:33 by fmauguin          #+#    #+#              #
#    Updated: 2022/05/25 14:26:30 by fmauguin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_PATH	=	Srcs/
SRCS		=	Srcs/ft_printf.c Srcs/ft_utils.c Srcs/ft_getaddr.c Srcs/ft_lst_utils.c \
				Srcs/ft_print_struct.c Srcs/ft_struct_utils.c Srcs/ft_convert.c			\
				Srcs/ft_tohex.c
OBJS		=	$(SRCS:.c=.o)
INCLUDE		=	Include/
LIBFT_PATH	=	libft/
LIBFT		=	libft1.a
NAME		=	libft.a

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -I$(INCLUDE)

all: ${NAME}

${NAME}: % : message libft_build ${OBJS}
			@ar rcs $(NAME) $(OBJS)
			@echo "$(NAME) created"

%.o: 		%.c
			@$(CC) $(CFLAGS) -o $@ -c $<

libft_build: 
			@make -C $(LIBFT_PATH)
			@cp $(LIBFT_PATH)$(LIBFT) .
			@mv $(LIBFT) $(NAME)

clean:
			@make clean -C $(LIBFT_PATH)
			@rm -f $(OBJS)
			@echo "clean done"

fclean:		clean
			@make fclean -C $(LIBFT_PATH)
			@rm -f $(NAME)
			@echo "fclean done"
			
re:			fclean all

message: 
		@echo "Building $(NAME)"