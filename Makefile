# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jochang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/24 20:15:02 by jochang           #+#    #+#              #
#    Updated: 2019/03/24 20:15:03 by jochang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = src/main.c \
	src/init_env.c \
	src/init_auto.c \
	src/ft_readline.c \
	src/count_qs.c \
	src/expand_semi.c \
	src/expand_dolla.c \
	src/expand_tilde.c \
	src/split_cmd.c \
	src/split_qs.c \
	src/check_rights.c \
	src/dispatch_cmd.c \
	src/dispatch_exec.c \
	src/dispatch_bin.c \
	src/dispatch_folder.c \
	src/ft_putnstr.c \
	src/ft_arrfree.c \
	src/ft_strcdup.c \

DIS = dis/d_cd.c \
	dis/d_echo.c \
	dis/d_env.c \
	dis/d_exit.c \
	dis/d_history.c \
	dis/d_setenv.c \
	dis/d_unsetenv.c \

INC = -I inc \
	-I libft/inc \

LFT = -L libft -lft \
	-lreadline \

CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all
all: $(NAME)

$(NAME):
	@make -C libft
	@echo "\033[32mmaking minishell...\033[0m"
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(DIS) $(INC) $(LFT)

.PHONY: clean
clean:
	@make -C libft clean

.PHONY: fclean
fclean:
	@make -C libft fclean
	@echo "\033[33mremoving executable...\033[0m"
	@/bin/rm -f $(NAME)

.PHONY: re
re: fclean all
