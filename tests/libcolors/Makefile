# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/27 16:33:03 by vde-melo          #+#    #+#              #
#    Updated: 2020/11/27 16:35:44 by vde-melo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= test_libvectors

SRCS		= main_test_colors.c

OBJS		= ${SRCS:.c=.o}

PATH_LIB	= ../../libs/colors/

LIBS		= $(PATH_LIB)libcolors.a -lm

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