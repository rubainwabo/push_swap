#include "push_swap.h"

static	void	swap(int *i, int *j)
{
	int		temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

void    swap_stack(int *stack, int len)
{
	if (len >= 2)
		swap(&stack[0], &stack[1]);
}

void	swap_ss(int *a, int *b, int len1, int len2)
{
	swap_stack(a, len1);
	swap_stack(b, len2);
}

/*
** len of the stack which is pushing
*/

void	push_stack(int *pusher, int *receiver, int len, int *elt)
{
	if (len >= 1 && *elt < len - 1)
	{
		receiver[len - *elt - 1] = pusher[*elt];
		pusher[*elt] = 0;
		*elt++;
	}
}

void	rotate_stack(int *stack, int len)
{
	int		i;

	i = 0;
	while (i + 1 < len)
	{
		swap(&stack[i], &stack[i + 1]);
		i++;
	}
}

void	rotate_rr(int *a, int *b, int len1, int len2)
{
	rotate_stack(a, len1);
	rotate_stack(b, len2);
}

void	rev_rotate(int *stack, int len)
{
	while (len - 1 >= 0)
	{
		len--;
		swap(&stack[len], &stack[len - 1]);
	}
}

void	rev_rotate_rr(int *a, int *b, int len1, int len2)
{
	rev_rotate(a, len1);
	rev_rotate(b, len2);
}