# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/07 17:23:51 by vde-melo          #+#    #+#              #
#    Updated: 2020/10/09 15:43:04 by vde-melo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	miniRT_with_test

F_TESTS		=	./tests

F_MYMATH	=	./mymath

F_MINIRT	=	./miniRT

SRCS_TESTS	=	${F_TESTS}/test_makefile_tests.c

SRCS_MYMATH	=	${F_MYMATH}/test_makefile_mymath.c

SRCS_MINIRT	=	${F_MINIRT}/minirt.c

SRCS_ALL	=	${SRCS_TESTS} ${SRCS_MINIRT}

OBJS_TESTS	=	test_makefile_tests.o

OBJS_MYMATH	=	test_makefile_mymath.o

OBJS_MINIRT	=	minirt.o

OBJS_ALL	=	${OBJS_TESTS} ${OBJS_MINIRT}

MYMATH_LIB	=	libmymath.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

INCLUDES = ${F_TESTS} ${F_MYMATH} ${F_MINIRT}

all: ${MYMATH_LIB} ${NAME}

${MYMATH_LIB}: ${SRCS_MYMATH} ${F_MYMATH}/mymath.h
	${CC} ${FLAGS} -I ${F_MYMATH} -c ${SRCS_MYMATH}
	ar rcs ${MYMATH_LIB} ${OBJS_MYMATH}

${NAME}: ${OBJS_ALL}
	${CC} ${OBJS_ALL} ${MYMATH_LIB} -o ${NAME}

${OBJS_ALL}: ${SRCS_ALL}  ${F_TESTS}/tests.h ${F_MINIRT}/minirt.h
	${CC} ${FLAGS} -c ${SRCS_ALL} -I ${INCLUDES}

clean:
	rm -rf *.o

fclean: clean
	rm -rf ${MYMATH_LIB}
	rm -rf ${NAME}

re: fclean all