# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 15:55:21 by vde-melo          #+#    #+#              #
#    Updated: 2020/10/29 16:20:37 by vde-melo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= test_libvectors

SRCS		= 

OBJS		= ${SRCS:.c=.o}

PATH_LIB	= ../../my_libs/vectors/

CC			= gcc

RM			= rm -rf

CFLAGS		= -Wall -Wextra -Werror

LINK_LIBS	= 

${NAME}:	${OBJS}
			make -C $(PATH_LIB)libvector
			${CC} ${CFLAGS} $(OBJS) $(LINK_LIBS) -o ${NAME}

all:		${NAME}

clean:
			make clean -C $(PATH_LIB)libvector
			${RM} ${OBJS}

fclean:		clean
			make fclean -C $(PATH_LIB)libvector
			${RM} ${NAME}

re:			fclean all

PHONY:		all clean fclean re