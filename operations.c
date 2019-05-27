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
** len of the stack which is receiving
*/

void	push_b(int *a, int *b, int len) // take the first element of a
{
	static int	index;

	index = 0;
	if (len >= 1 && index <= len - 1)
	{
		b[len - index - 1] = a[index];
		index++;
	}
}

void	push_a(int *b, int *a, int len) // take the first element of b
{
	static int	index;

	index = 0;
	if (len >= 1 && index <= len - 1)
	{
		a[len - index -1] = b[index];
		index++;
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
	while (len - 2 >= 0)
	{
		swap(&stack[len - 1], &stack[len - 2]);
		len--;
	}
}

void	rev_rotate_rr(int *a, int *b, int len1, int len2)
{
	rev_rotate(a, len1);
	rev_rotate(b, len2);
}

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_putstr("Not enough arguments :(\n");
		return (0);
	}
	int		len = 6;
	int tab[6] = {2, 1, 3, 6, 5, 8};
	int tab1[6] = {0};
	int i = 0;
	while (i < ac)
	{
		 if (!ft_strcmp(av[i], A))
		 	swap_stack(tab, len);
		 else if (!ft_strcmp(av[i], B))
		 	swap_stack(tab1, 0);
		else if (!ft_strcmp(av[i], C))
		 	push_a(tab1, tab, 0);
		else if (!ft_strcmp(av[i], D))
		 	push_b(tab, tab1, len);
		else if (!ft_strcmp(av[i], E))
		 	rotate_stack(tab, len);
		else if (!ft_strcmp(av[i], F))
		 	rotate_stack(tab1, len);
		else if (!ft_strcmp(av[i], G))
		 	rotate_rr(tab, tab1, len, len);
		else if (!ft_strcmp(av[i], H))
		 	rev_rotate(tab, len);
		else if (!ft_strcmp(av[i], I))
		 	rev_rotate(tab, len);
	 	else if (!ft_strcmp(av[i], J))
		 	rev_rotate_rr(tab, tab1, len, len);
		else if (!ft_strcmp(av[i], K))
		 	swap_ss(tab, tab1, len, len);
		i++;
	}
	i = 0;
	while (i < len)
	{
		ft_printf("a -- sorted element tab[%d] = %d\n", i, tab[i]);
		i++;
	}
	i = 0;
	while (i < len)
	{
		ft_printf("b -- sorted element tab1[%d] = %d\n", i, tab1[i]);
		i++;
	}
	return (0);
}
