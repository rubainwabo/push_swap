#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define A	"sa\n"
# define B	"sb\n"
# define C	"pa\n"
# define D	"pb\n"
# define E	"ra\n"
# define F	"rb\n"
# define G	"rr\n"
# define H	"rra\n"
# define I	"rrb\n"
# define J	"rrr\n"
# define K	"ss\n"
# include "libft/libft.h"
# include <stdio.h>

/*
** Struct to store instructions and data
*/

typedef struct s_swap
{
	int			*data;
	short			state;
}				t_swap;
int				ft_check_instructions(char *str);
int				ft_check_str(int ac, char **av, t_swap *d);
int				ft_checker(int ac, char **av);

#endif
