/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 21:19:52 by rkamegne          #+#    #+#             */
/*   Updated: 2019/06/19 14:55:06 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static	void	sort_top(t_swap *d, int size)
{
	if (size == 1)
		rotate_a(d);
	else if (size == 2)
	{
		sort_2(d, 'a');
		rotate_a(d);
		rotate_a(d);
	}
}

#define MEDIAN 0
#define TOP_LEN 1
#define B_MEDIAN 2

static	int		sort_loop(t_swap *d, int size, int *i)
{
	int		data[3];

	data[MEDIAN] = find_median(d->a, size);
	data[TOP_LEN] = 0;
	while (++(*i) < size)
	{
		if (d->b)
			data[B_MEDIAN] = find_median(d->b, ft_lstlen(d->b));
		if (*(int *)d->a->content <= data[MEDIAN])
		{
			push_b(d);
			data[TOP_LEN]++;
		}
		else
		{
			if (d->b && *(int *)d->b->content <= data[B_MEDIAN]
						&& ft_lstlen(d->b) > 5)
				rotate_r(d);
			else
				rotate_a(d);
		}
		if (check_nbs_left(d->a, size - *i, data[MEDIAN]) && ++(*i))
			break ;
	}
	return (data[TOP_LEN]);
}

static	void	apply_rra(t_swap *d, int size, int b_mid)
{
	int		min;

	while (size--)
	{
		min = get_min_index(d->b);
		if (min > b_mid)
			rev_rotate_r(d);
		else
			rev_rotate_a(d);
	}
}

static	void	pos_rra(t_swap *d, int b_size, int size)
{
	int save;
	int	left;
	int	i;

	save = *((int *)(d->a->content));
	if (!(check_rev_sorted(d->b)))
		sort_b(d, b_size);
	else
	{
		i = -1;
		while (++i < b_size)
			push_a(d);
		i = -1;
		while (++i < b_size)
			rotate_a(d);
	}
	while (!size_sorted(d->a, size_median(d->a, save)))
		sort(d, size_median(d->a, save), 0);
	left = size_median(d->a, save);
	while (left--)
		rotate_a(d);
	if (!size_sorted(d->a, size - b_size))
		sort(d, size - b_size, 0);
}

void			sort(t_swap *d, int size, int first)
{
	int		top_len;
	int		index;

	if (size <= 2)
	{
		sort_top(d, size);
		return ;
	}
	index = -1;
	top_len = sort_loop(d, size, &index);
	if (!first)
		apply_rra(d, index - top_len, top_len / 2);
	pos_rra(d, top_len, size);
}
