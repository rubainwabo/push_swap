/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:45:42 by rkamegne          #+#    #+#             */
/*   Updated: 2019/06/18 20:54:10 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void			put_pixel_img(char *image_str, int x, int y, int color)
{
	unsigned int	pos;

	if (x < WIDTH && y < HEIGHT && x >= 0 && y >= 0)
	{
		pos = (x + WIDTH * y) * 4;
		image_str[pos] = color & 0xFF;
		image_str[pos + 1] = (color >> 8) & 0xFF;
		image_str[pos + 2] = (color >> 16) & 0xFF;
	}
}

static	void	ft_draw_l(char *img, int color, t_draw draw)
{
	int	i;

	i = 1;
	while (i <= draw.dx)
	{
		draw.x += draw.xinc;
		draw.color = color;
		draw.cumul += draw.dy;
		if (draw.cumul >= draw.dx)
		{
			draw.cumul -= draw.dx;
			draw.y += draw.yinc;
		}
		if (draw.x < WIDTH && draw.x > 0)
			put_pixel_img(img, draw.x, draw.y, draw.color);
		i++;
	}
}

static	void	ft_draw_h(char *img, int color, t_draw draw)
{
	int	i;

	i = 1;
	while (i <= draw.dy)
	{
		draw.y += draw.yinc;
		draw.color = color;
		draw.cumul += draw.dx;
		if (draw.cumul >= draw.dy)
		{
			draw.cumul -= draw.dy;
			draw.x += draw.xinc;
		}
		if (draw.x < WIDTH && draw.x > 0)
			put_pixel_img(img, draw.x, draw.y, draw.color);
		i++;
	}
}

void			draw_line(char *img, t_point start_pt, t_point end_pt)
{
	t_draw	draw;

	draw.x = start_pt.x;
	draw.y = start_pt.y;
	draw.dy = end_pt.y - start_pt.y;
	draw.dx = end_pt.x - start_pt.x;
	draw.xinc = (draw.dx > 0) ? 1 : -1;
	draw.yinc = (draw.dy > 0) ? 1 : -1;
	if (draw.dx < 0)
		draw.dx = -draw.dx;
	if (draw.dy < 0)
		draw.dy = -draw.dy;
	if (draw.dx > draw.dy)
	{
		draw.cumul = draw.dx / 2;
		ft_draw_l(img, start_pt.color, draw);
	}
	else
	{
		draw.cumul = draw.dy / 2;
		ft_draw_h(img, start_pt.color, draw);
	}
}
