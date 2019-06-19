/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:40:29 by rkamegne          #+#    #+#             */
/*   Updated: 2019/06/18 22:23:00 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int		scaling_compute(t_swap *d, int nbr)
{
	double	a;
	double	b;

	a = (double)(d->len_max - d->len_min) / (d->max - d->min);
	b = (double)d->len_max - a * d->max;
	return (a * nbr + b);
}

int		max_min(t_list *stack, int c)
{
	t_list	*tmp;
	int		m;

	tmp = stack;
	m = *(int *)tmp->content;
	if (c == 1)
	{
		while (tmp)
		{
			if (*(int *)tmp->content > m)
				m = *(int *)tmp->content;
			tmp = tmp->next;
		}
		return (m);
	}
	else
	{
		while (tmp)
		{
			if (*(int *)tmp->content < m)
				m = *(int *)tmp->content;
			tmp = tmp->next;
		}
		return (m);
	}
}

void	draw_rec_b(t_swap *d, int start, int size)
{
	int		i;
	int		height;

	i = -1;
	height = HEIGHT - size;
	while (++i < d->large)
		draw_line(d->image_str, (t_point){.x = start + i, .y = height,
		.color = d->color}, (t_point){.x = start + i, .y = HEIGHT, .color = 0});
}

void	draw_rec_a(t_swap *d, int start, int size)
{
	int		i;
	int		height;

	i = -1;
	height = 575 - size;
	while (++i < d->large)
		draw_line(d->image_str, (t_point){.x = start + i, .y = height,
		.color = d->color}, (t_point){.x = start + i, .y = 574, .color = 0});
}
