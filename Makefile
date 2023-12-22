# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 16:03:34 by lnicolof          #+#    #+#              #
#    Updated: 2023/12/13 18:36:54 by lnicolof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = ft_parse.c \
	ft_printchar.c \
	ft_printdeci.c \
	ft_printf.c \
	ft_printhexalow.c \
	ft_printhexaupp.c \
	ft_printstr.c \
	ft_printint.c \
	ft_printunsignedeci.c \
	ft_ptrisnull.c \
	ft_putchar.c \
	
ARRC = ar rc
COMPIL = cc

FLAGS = -Wall -Wextra -Werror

OBJS = ${FILES:.c=.o}

%.o: %.c
		${COMPIL} ${FLAGS} -c $< -o $@
		
${NAME} : ${OBJS}
		${ARRC} ${NAME} ${OBJS}
		
all : ${NAME}

clean :
		rm -f ${OBJS}

fclean :
		rm -f ${NAME}
		rm -f ${OBJS}
		
re : fclean all

.PHONY : all clean fclean re