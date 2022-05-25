# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 23:26:03 by fmauguin          #+#    #+#              #
#    Updated: 2022/05/25 14:04:12 by fmauguin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_atoi.c		\
				ft_bzero.c		\
				ft_calloc.c		\
				ft_isalnum.c	\
				ft_isalpha.c 	\
				ft_isascii.c	\
				ft_isdigit.c	\
				ft_isprint.c	\
				ft_memchr.c		\
				ft_memcmp.c		\
				ft_memcpy.c		\
				ft_memmove.c 	\
				ft_memset.c		\
				ft_strchr.c		\
				ft_strrchr.c	\
				ft_strdup.c		\
				ft_strlcat.c	\
				ft_strlcpy.c	\
				ft_strlen.c		\
				ft_strncmp.c	\
				ft_strnstr.c	\
				ft_strrchr.c	\
				ft_tolower.c	\
				ft_toupper.c	\
				ft_substr.c		\
				ft_strjoin.c	\
				ft_strtrim.c	\
				ft_split.c		\
				ft_itoa.c		\
				ft_strmapi.c	\
				ft_striteri.c	\
				ft_putchar_fd.c	\
				ft_putstr_fd.c	\
				ft_putendl_fd.c	\
				ft_putnbr_fd.c	\
				ft_lstnew.c		\
				ft_lstsize.c	\
				ft_lstlast.c	\
				ft_lstadd_back.c	\
				ft_lstadd_front.c	\
				ft_lstdelone.c	\
				ft_lstclear.c	\
				ft_lstiter.c	\
				ft_lstmap.c		\

OBJS		= $(SRCS:.c=.o)
NAME		= libft1.a

CC			= cc
CFLAGS 		= -Wall -Werror -Wextra -I.

all:		${NAME}

${NAME}:	${OBJS}
			@ar rcs ${NAME} ${OBJS}
			@echo "Libft1.a created"

%.o: 		%.c
			@$(CC) -c $(CFLAGS) $< -o $@

clean:
			@rm -f ${OBJS}
			@echo "clean done"

fclean:		clean
			@rm -f ${NAME}
			@echo "fclean done"

re:			fclean all

bonus:			$(OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)