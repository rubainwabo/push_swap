/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 22:12:59 by rkamegne          #+#    #+#             */
/*   Updated: 2019/06/18 23:32:55 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	place_top(t_swap *d, int size)
{
	if (size == 2)
	{
		sort_2(d, 'b');
		push_a(d);
		push_a(d);
		rotate_a(d);
		rotate_a(d);
	}
	else if (size == 1)
	{
		push_a(d);
		rotate_a(d);
	}
}

int		check_rev_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (*(int *)stack->content < *(int *)stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int		check_sorted(t_list *stack)
{
	int		i;

	i = -1;
	while (stack && stack->next)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_tab(int *tab, int size)
{
	int		swap;
	int		i;
	int		temp;

	swap = 1;
	while (swap)
	{
		swap = 0;
		i = 0;
		while (++i < size)
		{
			if (tab[i - 1] > tab[i])
			{
				temp = tab[i];
				tab[i] = tab[i - 1];
				tab[i - 1] = temp;
				swap = 1;
			}
		}
	}
}
