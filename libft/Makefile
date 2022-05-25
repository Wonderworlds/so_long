# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 18:25:33 by fmauguin          #+#    #+#              #
#    Updated: 2022/05/25 16:52:57 by fmauguin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_PATH	=	Srcs/
SRCS_FILES	=	ft_atoi.c ft_bzero.c ft_calloc.c ft_convert.c ft_getaddr.c \
				ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
				ft_isprint.c ft_itoa.c ft_lst_utils.c ft_lstadd_back.c \
				ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
				ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_memchr.c \
				ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_printf.c \
				ft_print_struct.c ft_putchar_fd.c ft_putendl_fd.c ft_split.c \
				ft_putnbr_fd.c ft_putstr_fd.c ft_strchr.c ft_strdup.c \
				ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
				ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
				ft_strrchr.c ft_strtrim.c ft_struct_utils.c ft_substr.c \
				ft_tohex.c ft_tolower.c ft_toupper.c ft_utils.c
SRCS		=	$(addprefix $(SRCS_PATH), $(SRCS_FILES))
OBJS		=	$(SRCS:.c=.o)
INCLUDE		=	Include/
LIBFT_PATH	=	libft/
NAME		=	libft.a

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -I$(INCLUDE)

all: ${NAME}

${NAME}: % : message ${OBJS}
			@ar rcs $(NAME) $(OBJS)
			@echo "$(NAME) created"

%.o: 		%.c
			@$(CC) $(CFLAGS) -o $@ -c $<


clean:
			@rm -f $(OBJS)
			@echo "clean done"

fclean:		clean
			@rm -f $(NAME)
			@echo "fclean done"
			
re:			fclean all

message: 
		@echo "Building $(NAME)"