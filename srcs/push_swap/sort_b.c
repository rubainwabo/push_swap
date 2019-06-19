/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 21:43:41 by rkamegne          #+#    #+#             */
/*   Updated: 2019/06/19 00:34:52 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static	int		*create_tab(t_swap *d)
{
	int		*tab;
	int		i;
	t_list	*tmp;

	if (!(tab = (int *)ft_memalloc(sizeof(int) * ft_lstlen(d->b))))
	{
		free_lists(d);
		exit(1);
	}
	i = 0;
	tmp = d->b;
	while (tmp)
	{
		tab[i++] = *((int *)tmp->content);
		tmp = tmp->next;
	}
	sort_tab(tab, i);
	return (tab);
}

static	int		exec_ins(t_swap *d, int median, int **tab)
{
	if (*(int *)d->b->content == **tab)
	{
		push_a(d);
		if (*(int *)d->b->content != *((*tab) + 1)
			&& *(int *)d->b->content <= median)
			rotate_r(d);
		else
			rotate_a(d);
		(*tab)++;
	}
	else if (*(int *)d->b->content > median)
		push_a(d);
	else
		rotate_b(d);
	if (check_nbs_left_b(d->b, ft_lstlen(d->b), median))
		return (1);
	return (0);
}

void			sort_b(t_swap *d, int size)
{
	int		*tab;
	int		median;
	int		*copy;

	if (size <= 30)
	{
		sort_small(d, size, size);
		return ;
	}
	median = find_median(d->b, ft_lstlen(d->b));
	tab = create_tab(d);
	copy = tab;
	while (size--)
	{
		if (exec_ins(d, median, &tab))
			break ;
	}
	free(copy);
	sort_b(d, ft_lstlen(d->b));
}
