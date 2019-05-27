#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# define A	"sa"
# define B	"sb"
# define C	"pa"
# define D	"pb"
# define E	"ra"
# define F	"rb"
# define G	"rr"
# define H	"rra"
# define I	"rrb"
# define J	"rrr"
# define K	"ss"

/*
** Struct to store instructions and data
*/

typedef struct		s_swap
{
	//int				*data;
	short			state;
	t_list			*list;
	t_list			*list_num;
}					t_swap;
int					check_instructions(char *str);
int					check_str(int ac, char **av, t_swap *d);
int					checker(int ac, char **av);

#endif
