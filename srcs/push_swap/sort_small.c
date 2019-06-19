/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 09:39:39 by rkamegne          #+#    #+#             */
/*   Updated: 2019/06/19 00:44:20 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static	void	pos_rotate(t_swap *d, int *size, int count)
{
	int	min;

	(*size)--;
	push_a(d);
	min = get_min_index(d->b);
	if (d->b && min < *size / 2)
		rotate_r(d);
	else
		rotate_a(d);
	while (count--)
	{
		rotate_a(d);
		(*size)--;
	}
}

static	void	exec_rrb(t_swap *d, int *size, int pos)
{
	int		next_min;
	int		count;
	int		min_value;

	min_value = get_min_value(d->b);
	next_min = get_next_min(d->b, pos);
	count = 0;
	while (d->b && min_value != *(int *)d->b->content)
	{
		if (d->b && count < 2 && next_min == *(int *)d->b->content)
		{
			count++;
			push_a(d);
			if (count == 2)
				swap_a(d);
			next_min = get_next_min(d->b, pos);
			continue ;
		}
		rev_rotate_b(d);
	}
	pos_rotate(d, size, count);
}

static	void	exec_rb(t_swap *d, int *size, int pos)
{
	int		next_min;
	int		count;
	int		min_value;

	min_value = get_min_value(d->b);
	next_min = get_next_min(d->b, pos);
	count = 0;
	while (d->b && min_value != *(int *)d->b->content)
	{
		if (d->b && count < 2 && next_min == *(int *)d->b->content)
		{
			count++;
			push_a(d);
			if (count == 2)
				swap_a(d);
			next_min = get_next_min(d->b, pos);
			continue ;
		}
		rotate_b(d);
	}
	pos_rotate(d, size, count);
}

static	int		sorted(t_swap *d, int size)
{
	int		i;

	if (check_rev_sorted(d->b))
	{
		i = 0;
		while (d->b)
		{
			push_a(d);
			i++;
		}
		while (i--)
			rotate_a(d);
		return (1);
	}
	else if (check_sorted(d->b))
	{
		i = -1;
		while (++i < size)
		{
			push_a(d);
			rotate_a(d);
		}
		return (1);
	}
	return (0);
}

void			sort_small(t_swap *d, int size, int initial)
{
	if (size <= 2)
	{
		place_top(d, size);
		return ;
	}
	if (get_min_index(d->b) > size / 2)
		exec_rrb(d, &size, get_min_index(d->b));
	else
		exec_rb(d, &size, get_min_index(d->b));
	if (sorted(d, size) == 0)
		sort_small(d, size, initial);
}
