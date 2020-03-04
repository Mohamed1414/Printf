# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/18 17:57:37 by mbahstou          #+#    #+#              #
#    Updated: 2020/03/03 18:48:48 by mbahstou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_printf_utils.c ft_hexa.c ft_unsigned.c ft_int.c ft_hexamay.c ft_percentage.c \
		ft_conversions.c ft_char.c ft_printhings.c ft_printhingstwo.c ft_wiandpre.c ft_flags.c ft_istring.c \
		ft_prestring.c ft_impr.c ft_widstring.c ft_minusint.c ft_preint.c ft_zeroint.c ft_widint.c ft_prehex.c \
		ft_minushex.c ft_zerohex.c ft_gesthex.c ft_widpointer.c ft_minuspointer.c ft_pointer.c ft_print_utils2.c
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
all:	${NAME}
$(NAME):
	${CC} ${CFLAGS} -c ${SRCS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}
clean:
	${RM} ${OBJS}
fclean:	clean
	${RM} ${NAME}
re:		fclean all
.PHONY:	all clean fclean re