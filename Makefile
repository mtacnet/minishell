# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/01 11:47:50 by mtacnet           #+#    #+#              #
#    Updated: 2017/08/16 11:52:20 by nbouchin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -I. -g

RM			= rm -rf

LIBFT		= -L./libft -lft

SRCS		= *.c

OBJS		= $(SRCS:.c=.o)

LIBFT_PATH	= ./libft

GREEN		= "\033[32m"

all: $(NAME)

$(NAME):$(OBJS)
		@make -C $(LIBFT_PATH)
		@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
		@echo $(GREEN)"Compilation done !"

%.o: %.c
		@gcc -o $@ -c $< $(CFLAGS)

clean:
		@$(RM) $(OBJS)
		@make -C $(LIBFT_PATH) clean
		@echo "clean OK"

fclean: clean
		@$(RM) $(NAME)
		@make -C $(LIBFT_PATH) fclean
		@echo "fclean OK"

re: fclean all

.PHONY: all clean fclean re
