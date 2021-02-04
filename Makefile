# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/07 17:23:51 by vde-melo          #+#    #+#              #
#    Updated: 2020/11/20 20:28:41 by vde-melo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	miniRT_with_test

DIR_SRCS	= ./srcs
DIR_OBJS	= ./objs
DIRS		= main colors tuples
SRCS_DIRS	= $(foreach dir, $(DIRS), $(addprefix $(DIR_SRCS)/, $(dir)))
OBJS_DIRS	= $(foreach dir, $(DIRS), $(addprefix $(DIR_OBJS)/, $(dir)))
SRCS		= $(foreach dir, $(SRCS_DIRS), $(wildcard $(dir)/*.c))
OBJS		= $(subst $(DIR_SRCS), $(DIR_OBJS), $(SRCS:.c=.o))

LIBFT_DIR	= ./libs/libft/
LIBFT		= $(LIBFT_DIR)libft.a

MLX_DIR		= ./libs/minilibx-linux
MLX			= $(MLX_DIR)/libmlx_Linux.a

LIBS_DIRS	= $(LIBFT_DIR) $(MLX_DIR)
LIBS_FLAGS	= -L ${LIBFT_DIR} -lft -lm
MLX_FLAGS	= -L${MLX_DIR} -lmlx_Linux -lXext -lX11
INCLUDES	= -I includes -I $(LIBFT_DIR)/includes/

CC			= clang
CC_FLAGS	= -Wall -Wextra -Werror -g3 -fsanitize=address

NORM		= ~/.norminette/norminette.rb

all:		$(NAME)

$(DIR_OBJS)/%.o :	$(DIR_SRCS)/%.c
			@mkdir -p $(DIR_OBJS) $(OBJS_DIRS)
			@$(CC) $(CC_FLAGS) $(INCLUDES) -c $< -o $@

$(NAME):	$(OBJS) $(LIBFT) $(MLX)
			@$(CC) $(CC_FLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIB_FLAGS)


$(MLX):
			$(MAKE) -C $(MLX_DIR)

$(LIBFT):
			$(MAKE) -C $(LIBFT_DIR)

clean:
			$(MAKE) -C $(LIBFT_DIR) clean
			$(RM) -rf $(DIR_OBJS)

fclean:		clean
			$(MAKE) -C $(MLX_DIR) clean
			$(MAKE) -C $(LIBFT_DIR) fclean
			$(RM) $(NAME)

re:			fclean all

fcleanLIBFT:
			$(MAKE) -C $(LIBFT_DIR) fclean

fcleanRT:
			$(RM) -rf $(DIR_OBJS)
			$(RM) $(NAME)

test:		all
			./$(NAME)

normLIBFT:
			@$(NORM) $(LIBFT_DIR)

normRT:
			@$(NORM) $(SRCS) ./includes
