# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/07 17:23:51 by vde-melo          #+#    #+#              #
#    Updated: 2020/11/20 20:00:40 by vde-melo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	miniRT_with_test

INCLUDES	= ./srcs
SRCS_DIR	= ./srcs
OBJS_DIR	= ./objs
MLX_DIR		= ./libs/minilibx-linux
VECTORS_DIR	= ./libs/vectors
LIBFT_DIR	= ./libs/libft

SRCS		= ${SRCS_DIR}/minirt.c
OBJS		= $(patsubst ${SRCS_DIR}/%.c, ${OBJS_DIR}/%.o, ${SRCS})

CC			=	clang

C_FLAGS		=	-c						\
				-Wall					\
				-Wextra					\
				-Werror					\
				-I${MLX_DIR}			\
				-I${VECTORS_DIR}		\
				-I${LIBFT_DIR}/includes	\
				-I${INCLUDES}

L_FLAGS		=	-L${MLX_DIR}			\
				-lm						\
				-lmlx_Linux				\
				-lXext					\
				-lX11


all: $(NAME)

$(NAME): ${OBJS}
	$(CC) $^ $(L_FLAGS) -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c ${MLX} ${LIBFT} ${VECTORS}
	mkdir -p $(OBJS_DIR)
	$(CC) $(C_FLAGS) $< -o $@

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(VECTOR):
	$(MAKE) -C $(VECTORS_DIR)

clean:
			rm -rf ${OBJS}
			make clean -C ${LIBFT_DIR}
			make clean -C ${VECTORS_DIR}

fclean:		clean
			rm -f ${NAME}
			make fclean -C ${LIBFT_DIR}
			make fclean -C ${VECTORS_DIR}

re:			fclean all

PHONY:		all clean fclean re