# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkamegne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/22 14:40:24 by rkamegne          #+#    #+#              #
#    Updated: 2019/05/22 14:41:06 by rkamegne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = checker.c check_instructions.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = push_swap.h

all: checker push_swap

checker: $(OBJ) $(INC)
	@make -C libft/
	@$(CC) $(CFLAGS) -o checker $(SRC) -L libft/ -lft
push_swap: $(OBJ) $(INC)
	@$(CC) $(CFLAGS) -o push_swap $(SRC) -L libft/ -lft

clean:
	@make -C libft/ clean
	@/bin/rm -f $(OBJ)
fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f checker
	@/bin/rm -f push_swap

re: fclean all

.PHONY : fclean clean all re
