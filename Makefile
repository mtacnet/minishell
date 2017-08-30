# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/01 11:47:50 by mtacnet           #+#    #+#              #
#    Updated: 2017/08/30 12:34:45 by mtacnet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -I.

RM			= rm -rf

LIBFT		= -L./libft -lft

SRCS		= cmd.c core.c error.c init_list.c list.c main.c param.c tab.c \
			process_builtins.c process_builtins2.c process_flag.c utils.c \
			utils2.c utils_cd.c utils_cd2.c error2.c

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
