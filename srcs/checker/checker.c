/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 03:51:42 by rkamegne          #+#    #+#             */
/*   Updated: 2019/06/18 23:13:12 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static	void	checker_ops(t_swap *d)
{
	t_list		*tmp;

	tmp = d->list_ins;
	d->b = NULL;
	while (tmp)
	{
		apply_ops(d, tmp->content);
		tmp = tmp->next;
	}
}

static	int		check_solved(t_swap *d)
{
	t_list	*tmp;
	int		list_len;
	int		a;
	int		b;

	list_len = ft_lstlen(d->a);
	checker_ops(d);
	if (ft_lstlen(d->b) || list_len != ft_lstlen(d->a))
		return (0);
	tmp = d->a;
	while (tmp->next)
	{
		a = *((int *)tmp->content);
		b = *((int *)tmp->next->content);
		if (a > b)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static	int		checker_next(int ac, char **av, t_swap *d)
{
	if (!check_arg(ac, av, d))
	{
		(d->state == 1) ? ft_memdel((void **)av) : 0;
		ft_putstr("Error\n");
		free_lists(d);
		return (0);
	}
	if (d->fct && !check_solved(d))
	{
		(d->state == 1) ? ft_memdel((void **)av) : 0;
		ft_putstr("KO\n");
		free_lists(d);
		return (0);
	}
	return (1);
}

static	int		checker(int ac, char **av, t_swap *d)
{
	d->state = 0;
	d->fct = 1;
	d->print = 0;
	if (ac == 1)
		exit(EXIT_SUCCESS);
	if (ac == 2 && (d->state = 1))
	{
		if (!(av = ft_strsplit(av[(d->arg) ? 2 : 1], ' ')))
			ft_error("Error");
		ac -= 2;
		while (av[ac])
			ac++;
	}
	if (!checker_next(ac, av, d))
		return (0);
	ft_putstr("OK\n");
	(d->state == 1) ? ft_memdel((void **)av) : 0;
	free_lists(d);
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
		checker(2, av, &d);
	}
	else if (ac > 3 && !ft_strcmp("-v", av[1]))
	{
		d.arg = 1;
		checker(ac, av, &d);
	}
	else
		checker(ac, av, &d);
	return (0);
}
