/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 10:39:39 by rkamegne          #+#    #+#             */
/*   Updated: 2019/06/19 00:33:17 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int				min_max(int a, int b, int c, short m)
{
	if (m != 1)
	{
		if (a < b)
			return ((a < c) ? 1 : 0);
	}
	else
	{
		if (a > b)
			return ((a > c) ? 1 : 0);
	}
	return (0);
}

int				find(t_list *stack, short m)
{
	if (m != 1)
	{
		if (min_max(*(int *)stack->content, *(int *)stack->next->content,
				*(int *)stack->next->next->content, 0))
			return (1);
		else if (min_max(*(int *)stack->next->next->content,
				*(int *)stack->next->content, *(int *)stack->content, 0))
			return (3);
	}
	else
	{
		if (min_max(*(int *)stack->content, *(int *)stack->next->content,
				*(int *)stack->next->next->content, 1))
			return (1);
		else if (min_max(*(int *)stack->next->next->content,
				*(int *)stack->next->content, *(int *)stack->content, 1))
			return (3);
	}
	return (2);
}

int				median(t_list *stack)
{
	t_list	*list;
	int		min;

	list = stack;
	min = *(int *)stack->content;
	while (list)
	{
		if (*(int *)list->content < min)
			min = *(int *)list->content;
		list = list->next;
	}
	return (min);
}

void			free_lists(t_swap *d)
{
	ft_lstdel(&d->a, ft_free_content);
	ft_lstdel(&d->list_ins, ft_free_content);
}
