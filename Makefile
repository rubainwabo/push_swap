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

NAME = exec
CHECKER = checker
SOLVER = push_swap
FILES_CHECkER = checker/
SRC_CHECKER = $(addsuffix .c, $(FILES_CHECkER))
OBJ_CHECKER = $(addsuffix .o, $(FILES_CHECkER))
FILES_SOLVER = solver/
SRC_SOLVER = $(addsuffix .c, $(FILES_SOLVER))
OBJ_SOLVER = $(addsuffix .o, $(FILES_SOLVER))
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(CHECKER) $(SOLVER)
	@make -C libft/

$(CHECKER): $(OBJ_CHECKER)
	@$(CC) $(CFLAGS) -o $(NAME) -c $(SRC_CHECKER)
	@mv $(NAME) $(CHECKER)
$(CHECKER): $(OBJ_SOLVER)
	@$(CC) $(CFLAGS) -o $(NAME) -c $(SRC_SOLVER)
	@mv $(NAME) $(SOLVER)
clean:
	@make -C libft/ clean
	@/bin/rm -f $(OBJ_CHECKER)
	@/bin/rm -f $(OBJ_SOLVER)

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(CHECKER)
	@/bin/rm -f $(SOLVER)

re: fclean all

.PHONY : fclean clean all re
