/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:13:04 by rkamegne          #+#    #+#             */
/*   Updated: 2019/06/19 14:52:55 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# define SWAP_A	"sa\n"
# define SWAP_B	"sb\n"
# define PUSH_A	"pa\n"
# define PUSH_B	"pb\n"
# define ROT_A	"ra\n"
# define ROT_B	"rb\n"
# define ROT_R	"rr\n"
# define REV_ROT_A	"rra\n"
# define REV_ROT_B	"rrb\n"
# define REV_ROT_R	"rrr\n"
# define SWAP_S	"ss\n"
# define RED "\033[1;31m"
# define BLUE "\033[1;34m"
# define BLACK "\033[0m"

/*
** Struct to store instructions and data
** fct -> push_swap or checker
**
** VISUALIZER, PUSH_SWAP, CHECKER STRUCTURE
*/

typedef struct		s_swap
{
	short			state;
	short			fct;
	short			print;
	short			arg;
	t_list			*list_ins;
	t_list			*a;
	t_list			*b;
	int				len_a;
	int				len_b;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*image_ptr;
	void			*image_ptr1;
	char			*image_str;
	char			*image_str1;
	short			pause;
	int				max;
	int				min;
	int				large;
	int				len_max;
	int				len_min;
	int				color;
}					t_swap;

/*
**							 CHECKER
*/

int					check_instructions(char *str);
int					check_arg(int ac, char **av, t_swap *d);
int					fill_list(t_swap *d);

/*
** 						OPERATIONS (Instructions)		sa/sb/ss	pa/pb
**						ra/rb/rr rra/rrb/rrr
*/

void				swap_a(t_swap *d);
void				swap_b(t_swap *d);
void				swap_ss(t_swap *d);
void				push_a(t_swap *d);
void				push_b(t_swap *d);
void				rotate_a(t_swap *d);
void				rotate_b(t_swap *d);
void				rotate_r(t_swap *d);
void				rev_rotate_a(t_swap *d);
void				rev_rotate_b(t_swap *d);
void				rev_rotate_r(t_swap *d);
void				state_stack(t_list **stack, char c);
void				apply_ops(t_swap *d, char *tmp);

/*
**                              PUSH_SWAP
*/

/*
** SORT
*/

void				sort(t_swap *d, int size, int first);
void				sort_b(t_swap *d, int size);
void				sort_small(t_swap *d, int size, int initial);
void				sort_2(t_swap *d, char s);
void				sort_3(t_swap *d);
void				sort_4(t_swap *d);
void				sort_5(t_swap *d);

/*
** MEDIAN
*/

int					size_median(t_list *stack, int median);
int					size_sorted(t_list *stack, int size);
int					find_median(t_list	*stack, int size);
int					pos_min(t_list *stack);

/*
** UTILS
*/

int					get_min_index(t_list *stack);
int					get_min_value(t_list *stack);
int					get_next_min(t_list *stack, int oldmin);
void				place_top(t_swap *d, int size);
int					check_rev_sorted(t_list *stack);
int					check_sorted(t_list *stack);
void				sort_tab(int *tab, int size);
int					check_nbs_left(t_list *stack, int size, int median);
int					check_nbs_left_b(t_list *stack, int size, int median);

/*
** UTILS2
*/

int					min_max(int a, int b, int c, short m);
int					find(t_list *stack, short m);
int					median(t_list *stack);
void				free_lists(t_swap *d);

#endif
