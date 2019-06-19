/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 21:57:34 by rkamegne          #+#    #+#             */
/*   Updated: 2019/06/18 22:04:29 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int				pos_min(t_list *stack)
{
	t_list	*list;
	int		min;
	int		i;
	int		pos_min;

	i = 0;
	pos_min = 0;
	list = stack;
	min = *(int *)stack->content;
	while (list)
	{
		if (*(int *)list->content < min)
		{
			pos_min = i;
			min = *(int *)list->content;
		}
		list = list->next;
		i++;
	}
	return (pos_min);
}

int				size_sorted(t_list *stack, int size)
{
	int i;

	i = -1;
	while (stack && stack->next && ++i < size)
	{
		if ((*(int *)stack->content) > (*(int *)stack->next->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}

int				size_median(t_list *stack, int median)
{
	int		i;

	i = 0;
	while (stack)
	{
		if (*(int *)stack->content == median)
			return (i);
		stack = stack->next;
		i++;
	}
	return (i);
}

static	int		count_low_nbs(t_list *stack, int value, int size)
{
	int		count;
	int		i;

	count = 0;
	i = -1;
	while (stack && ++i < size)
	{
		count += *(int *)stack->content < value;
		stack = stack->next;
	}
	return (count);
}

int				find_median(t_list *stack, int size)
{
	int		half;
	int		value;
	t_list	*list;
	int		i;

	half = size / 2;
	list = stack;
	i = -1;
	while (list && ++i < size)
	{
		value = *(int *)list->content;
		if (count_low_nbs(stack, value, size) == half)
			return (value);
		list = list->next;
	}
	return (0);
}
