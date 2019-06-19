/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 17:37:41 by rkamegne          #+#    #+#             */
/*   Updated: 2019/06/18 22:20:26 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void			init(t_swap *d)
{
	d->b = NULL;
	d->len_a = ft_lstlen(d->a);
	d->len_b = 0;
	d->color = 0;
	d->max = 0;
	d->min = 0;
	d->len_max = 0;
	d->len_min = 0;
	if (!(d->large = WIDTH / d->len_a))
		d->large = 1;
	d->max = max_min(d->a, 1);
	d->min = max_min(d->a, 2);
	d->len_max = 550;
	d->len_min = 25;
	d->pause = 0;
}

static	int		checker_next(int ac, char **av, t_swap *d)
{
	if (!check_arg(ac, av, d))
	{
		(d->state == 1) ? ft_memdel((void **)av) : 0;
		ft_lstdel(&d->a, ft_free_content);
		ft_error("Error");
	}
	init(d);
	return (1);
}

int				get_instructions(int ac, char **av, t_swap *d)
{
	if (ac == 1)
		exit(EXIT_SUCCESS);
	if (ac == 2)
	{
		d->state = 1;
		if (!(av = ft_strsplit(av[1], ' ')))
			return (0);
		ac -= 2;
		while (av[ac])
			ac++;
	}
	if (!checker_next(ac, av, d))
		return (0);
	(d->state == 1) ? ft_memdel((void **)av) : 0;
	return (1);
}

void			build_images(t_swap *d)
{
	int		specs[3];

	if (!(d->image_ptr = mlx_new_image(d->mlx_ptr, WIDTH, HEIGHT)))
		ft_error("Error");
	if (!(d->image_str = mlx_get_data_addr(d->image_ptr, &specs[0],
					&specs[1], &specs[2])))
		ft_error("Error");
}

int				main(int ac, char **av)
{
	t_swap	d;
	int		i;

	i = -1;
	d.state = 0;
	d.fct = 2;
	d.print = 0;
	if (!get_instructions(ac, av, &d))
		ft_error("Error");
	if (!(d.mlx_ptr = mlx_init()))
		ft_error("Init of the mlx_window failed");
	if (!(d.win_ptr = mlx_new_window(d.mlx_ptr, WIDTH, HEIGHT, "visualizer")))
		ft_error("Init of the mlx_window failed");
	build_images(&d);
	mlx_key_hook(d.win_ptr, deal_key, &d);
	mlx_loop_hook(d.mlx_ptr, &draw_graphics, &d);
	mlx_loop(d.mlx_ptr);
	return (0);
}
