# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/03 14:44:53 by whamoumi          #+#    #+#              #
#    Updated: 2021/03/09 16:46:27 by whamoumi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS		=	ft_printf.c flags_width.c give_converter.c \
				give_converter_utils.c give_converter_utils2.c \
				parsing_flags.c precision_flags.c \
				precision_flags_utils.c precision_flags_utils2.c \
			    ft_printf_utils.c	


OBJS		=	${SRCS:.c=.o}

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -I./includes

RM			=	rm -f

all:			${NAME}

$(NAME):		${OBJS}
				ar rcs ${NAME} ${OBJS}

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all
