/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 04:47:24 by rkamegne          #+#    #+#             */
/*   Updated: 2019/06/18 23:34:26 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static	int		check_next(int ac, char **av, t_swap *d)
{
	if (!check_arg(ac, av, d))
	{
		(d->state == 1) ? ft_memdel((void **)av) : 0;
		ft_lstdel(&d->a, ft_free_content);
		ft_putstr("Error\n");
		return (0);
	}
	d->b = NULL;
	d->len_a = ft_lstlen(d->a);
	if (d->len_a == 2)
		sort_2(d, 'a');
	else if (d->len_a == 3)
		sort_3(d);
	else if (d->len_a == 4)
		sort_4(d);
	else if (d->len_a == 5)
		sort_5(d);
	else if (!check_sorted(d->a))
		sort(d, d->len_a, 1);
	return (1);
}

int				push_swap(int ac, char **av, t_swap *d)
{
	d->state = 0;
	d->fct = 0;
	d->print = 1;
	d->len_max = 550;
	d->len_min = 25;
	if (ac == 1)
		exit(EXIT_SUCCESS);
	if (ac == 2)
	{
		d->state = 1;
		if (!(av = ft_strsplit(av[(d->arg) ? 2 : 1], ' ')))
			ft_error("Error");
		ac -= 2;
		while (av[ac])
			ac++;
	}
	if (!check_next(ac, av, d))
		return (0);
	(d->state == 1) ? ft_memdel((void **)av) : 0;
	ft_lstdel(&d->a, ft_free_content);
	return (1);
}

int				main(int ac, char **av)
{
	t_swap		d;

	d.arg = 0;
	if (ac == 2 && !ft_strcmp("-v", av[1]))
		ft_error("Error");
	else if (ac == 3 && !ft_strcmp("-v", av[1]))
	{
		d.arg = 1;
		push_swap(2, av, &d);
	}
	else if (ac > 3 && !ft_strcmp("-v", av[1]))
	{
		d.arg = 1;
		push_swap(ac, av, &d);
	}
	else
		push_swap(ac, av, &d);
	return (0);
}
