# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbahstou <mbahstou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/17 19:25:35 by mbahstou          #+#    #+#              #
#    Updated: 2020/02/17 19:25:35 by mbahstou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf_utils.c ft_printf.c 
OBJS = ${SRCS:.c=.o};
CC = gcc -c 
FLAGS = -Wall -Wextra -Werror
RM = rm - rf

all: ${NAME}

${NAME} : ${SRCS}

		${CC} ${FLAGS} ${SRCS}
		ar rc ${NAME} ${OBJS}
		ranlib ${NAME}
clean :
		${RM} ${OBJS}

re : clean all 

.PHONY : all clean