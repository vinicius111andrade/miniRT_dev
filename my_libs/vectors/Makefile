# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/28 15:16:40 by vde-melo          #+#    #+#              #
#    Updated: 2020/10/28 17:19:53 by vde-melo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libvectors.a

SRCS	= vector_operations_0.c vector_operations_1.c vector_operations_2.c

OBJS	= ${SRCS:.c=.o}

CC		= gcc

RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS} ${BOBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re