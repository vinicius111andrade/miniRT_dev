# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-melo <vde-melo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/07 17:23:51 by vde-melo          #+#    #+#              #
#    Updated: 2021/03/01 22:16:13 by vde-melo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#name all source files including .h
#get tests out of the srcs folder and out of the SUBDIRS list

NAME			= minirt_dev

DIR_SRCS		= ./srcs
DIR_OBJS		= ./objs
DIR_INCLUDES	= ./includes
SUBDIRS			= colors tuples msgs scene tests parser rendering \
					raytracing main

SUBDIRS_SRCS	= $(foreach dir, $(SUBDIRS), $(addprefix $(DIR_SRCS)/, $(dir)))
SUBDIRS_OBJS	= $(foreach dir, $(SUBDIRS), $(addprefix $(DIR_OBJS)/, $(dir)))

SRCS			= $(foreach dir, $(SUBDIRS_SRCS), $(wildcard $(dir)/*.c))
OBJS			= $(subst $(DIR_SRCS), $(DIR_OBJS), $(SRCS:.c=.o))

LIBFT_DIR		= ./libs/libft
LIBFT			= $(LIBFT_DIR)/libft.a
MLX_DIR			= ./libs/minilibx-linux
MLX				= $(MLX_DIR)/libmlx_Linux.a

SUBDIRS_LIBS	= $(LIBFT_DIR) $(MLX_DIR)

FLAGS_LIBS		= -L ${LIBFT_DIR} -lft -lm -L$(DIR_INCLUDES)
FLAGS_MLX		= -L ${MLX_DIR} -lmlx_Linux -lXext -lX11
INCLUDES		= -I $(DIR_INCLUDES) -I $(LIBFT_DIR)/includes/

CC				= clang
FLAGS_CC		= -Wall -Wextra -Werror -g3 -fsanitize=address

NORM			= ~/.norminette/norminette.rb


all:			$(NAME)

$(DIR_OBJS)/%.o:	$(DIR_SRCS)/%.c
		@mkdir -p $(DIR_OBJS) $(SUBDIRS_OBJS)
		@$(CC) $(FLAGS_CC) $(INCLUDES) -c $< -o $@

$(NAME):	$(OBJS) $(LIBFT) $(MLX)
		@$(CC) $(FLAGS_CC) -o $(NAME) $(OBJS) $(FLAGS_MLX) $(FLAGS_LIBS)


$(MLX):
		$(MAKE) -C $(MLX_DIR)

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)

clean:
		$(MAKE) -C $(LIBFT_DIR) clean
		$(RM) -rf $(DIR_OBJS)

fclean:	clean
		$(MAKE) -C $(MLX_DIR) clean
		$(MAKE) -C $(LIBFT_DIR) fclean
		$(RM) $(NAME)

re:		fclean all

fcleanLIBFT:
		$(MAKE) -C $(LIBFT_DIR) fclean

fcleanRT:
		$(RM) -rf $(DIR_OBJS)
		$(RM) $(NAME)

test:	all
		./$(NAME)

normLIBFT:
		@$(NORM) $(LIBFT_DIR)

normRT:
		@$(NORM) $(SRCS) ./includes
