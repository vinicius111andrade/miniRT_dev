# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 15:55:21 by vde-melo          #+#    #+#              #
#    Updated: 2020/11/05 21:46:20 by vde-melo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= test_libvectors

SRCS		= test_main.c test_operations_0.c test_operations_1.c \
				test_operations_2.c

OBJS		= ${SRCS:.c=.o}

PATH_LIB	= ../../my_libs/vectors/

LIBS		= $(PATH_LIB)libvectors.a -lm

CC			= gcc

RM			= rm -rf

CFLAGS		= -Wall -Wextra -Werror

${NAME}:	${OBJS}
			make -C $(PATH_LIB)
			${CC} ${CFLAGS} $(OBJS) $(LIBS) -o ${NAME}

all:		${NAME}

clean:
			make clean -C $(PATH_LIB)
			${RM} ${OBJS}

fclean:		clean
			make fclean -C $(PATH_LIB)
			${RM} ${NAME}

re:			fclean all

PHONY:		all clean fclean re