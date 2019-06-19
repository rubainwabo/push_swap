/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:51:24 by rkamegne          #+#    #+#             */
/*   Updated: 2019/06/19 14:31:17 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	draw_dec(t_swap *d)
{
	int		i;

	i = -1;
	while (++i < WIDTH)
	{
		if (i == WIDTH / 2)
			mlx_string_put(d->mlx_ptr, d->win_ptr, i - 20, 576, 0xffffff,
			"TOP -> STACK A");
		mlx_pixel_put(d->mlx_ptr, d->win_ptr, i, 575, 0xffffff);
	}
	i = -1;
	while (++i < WIDTH)
	{
		if (i == WIDTH / 2)
			mlx_string_put(d->mlx_ptr, d->win_ptr, i - 20, 600, 0xffffff,
			"BOT -> STACK B");
		mlx_pixel_put(d->mlx_ptr, d->win_ptr, i, 625, 0xffffff);
	}
}

#define C1	0xffff00
#define C2	0x00ffff

void	draw_stack_a(t_swap *d)
{
	t_list	*tmp;
	int		i;
	int		size;

	i = 1;
	tmp = d->a;
	while (tmp)
	{
		size = scaling_compute(d, *(int *)tmp->content);
		d->color = get_color(C1, C2, (double)size / d->len_max);
		draw_rec_a(d, i, size);
		tmp = tmp->next;
		i += d->large + 1;
	}
}

void	draw_stack_b(t_swap *d)
{
	t_list	*tmp;
	int		i;
	int		size;

	i = 1;
	tmp = d->b;
	while (tmp)
	{
		size = scaling_compute(d, *(int *)tmp->content);
		d->color = get_color(C1, C2, (double)size / d->len_max);
		draw_rec_b(d, i, size);
		tmp = tmp->next;
		i += d->large + 1;
	}
}

int		draw_graphics(t_swap *d)
{
	t_list	*tmp;

	if (d->pause == 1)
	{
		apply_ops(d, d->list_ins->content);
		if (d->list_ins->next)
		{
			tmp = d->list_ins;
			d->list_ins = d->list_ins->next;
			free(tmp);
		}
		else
			d->pause = 2;
	}
	mlx_destroy_image(d->mlx_ptr, d->image_ptr);
	build_images(d);
	draw_stack_a(d);
	draw_stack_b(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->image_ptr, 0, 0);
	(d->pause == 0 || d->pause == 2) ? draw_dec(d) : 0;
	return (1);
}
