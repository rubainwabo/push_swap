# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/22 14:40:24 by rkamegne          #+#    #+#              #
#    Updated: 2019/06/19 10:12:12 by rkamegne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : fclean, clean, all, re

EXEC1 = checker
EXEC2 = push_swap
EXEC3 = visual

SRC_CHECKER = srcs/checker/checker.c\
			  srcs/common/check_arg.c\
			  srcs/common/check_arg2.c\
			  srcs/common/utils2.c\
			  srcs/ins/apply_ops.c\
			  srcs/ins/push_stack.c\
			  srcs/ins/rev_rotate_stack.c\
			  srcs/ins/rotate_stack.c\
			  srcs/ins/swap_stack.c\

SRC_PUSH_SWAP = srcs/push_swap/push_swap.c\
				srcs/push_swap/sort.c\
				srcs/push_swap/sort_tiny_lists.c\
				srcs/push_swap/sort_small.c\
				srcs/push_swap/sort_b.c\
				srcs/push_swap/find_median.c\
				srcs/push_swap/utils.c\
				srcs/push_swap/utils_next.c\
				srcs/common/check_arg.c\
				srcs/common/check_arg2.c\
				srcs/common/utils2.c\
				srcs/ins/apply_ops.c\
				srcs/ins/push_stack.c\
				srcs/ins/rev_rotate_stack.c\
				srcs/ins/rotate_stack.c\
				srcs/ins/swap_stack.c\
				
SRC_VISUALIZER = srcs/visualizer/visualizer.c\
				srcs/visualizer/draw_graphics.c\
				srcs/visualizer/util_visu.c\
				srcs/visualizer/get_color.c\
				srcs/visualizer/draw_line.c\
				srcs/visualizer/event_handling.c\
			    srcs/common/check_arg.c\
				srcs/common/check_arg2.c\
				srcs/common/utils2.c\
				srcs/ins/apply_ops.c\
				srcs/ins/push_stack.c\
				srcs/ins/rev_rotate_stack.c\
				srcs/ins/rotate_stack.c\
				srcs/ins/swap_stack.c\

OBJ_CHECKER = $(SRC_CHECKER:.c=.o)
OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)
OBJ_VISUALIZER = $(SRC_VISUALIZER:.c=.o)

LIB = -L srcs/visualizer/minilibx_macos/ -lmlx -L libft -lft

FRAMEWORKS = -framework OpenGL -framework Appkit

CC = gcc

INC = push_swap.h

CFLAGS = -Wall -Wextra -Werror

all: lib $(EXEC1) $(EXEC2) $(EXEC3)

lib:
	@make -C libft/
	@make -C srcs/visualizer/minilibx_macos/
$(EXEC1): $(OBJ_CHECKER) $(INC)
	@$(CC) $(CFLAGS) -o $@ $(OBJ_CHECKER) -L libft/ -lft
$(EXEC2): $(OBJ_PUSH_SWAP) $(INC)
	@$(CC) $(CFLAGS) -o $@ $(OBJ_PUSH_SWAP) -L libft/ -lft
$(EXEC3): $(OBJ_VISUALIZER) $(INC)
	@$(CC) $(CFLAGS) -Ofast -o $@ $(OBJ_VISUALIZER) $(LIB) $(FRAMEWORKS)
	@echo "\n\033[1;32m---------->[EXECUTABLES CREATED]<----------- \033[0m\n"

clean:
	@make -C libft/ clean
	@make -C srcs/visualizer/minilibx_macos/ clean
	@/bin/rm -f $(OBJ_PUSH_SWAP)
	@/bin/rm -f $(OBJ_CHECKER)
	@/bin/rm -f $(OBJ_VISUALIZER)
	@echo "\n\033[1;31m---------->[.o DELETED]<----------- \033[0m\n"
fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(EXEC1)
	@/bin/rm -f $(EXEC2)
	@/bin/rm -f $(EXEC3)
	@echo "\n\033[1;31m-------->[EXECUTABLES DELETED]<-------- \033[0m\n"

re: fclean all
