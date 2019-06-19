/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 22:07:21 by rkamegne          #+#    #+#             */
/*   Updated: 2019/06/18 22:17:57 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int		check_nbs_left(t_list *stack, int size, int median)
{
	int		i;
	t_list	*save;
	int		count;

	i = -1;
	save = stack;
	count = 0;
	while (++i < size && stack)
	{
		if (*(int *)stack->content <= median)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int		check_nbs_left_b(t_list *stack, int size, int median)
{
	int		i;
	t_list	*save;

	i = -1;
	save = stack;
	while (++i < size)
	{
		if (*(int *)stack->content > median)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int		get_min_index(t_list *stack)
{
	int		i;
	int		index;
	int		value;

	if (!stack)
		return (0);
	i = 0;
	index = 0;
	value = *(int *)stack->content;
	while (stack)
	{
		if (*(int *)stack->content < value)
		{
			value = *(int *)stack->content;
			index = i;
		}
		stack = stack->next;
		i++;
	}
	return (index);
}

int		get_next_min(t_list *stack, int oldmin)
{
	int		min;
	int		i;

	if (oldmin != 0)
		min = *(int *)stack->content;
	else
		min = *(int *)stack->next->content;
	i = 0;
	while (stack)
	{
		if (*(int *)stack->content < min && i != oldmin)
			min = *(int *)stack->content;
		i++;
		stack = stack->next;
	}
	return (min);
}

int		get_min_value(t_list *stack)
{
	int value;

	if (!stack)
		return (0);
	value = *(int *)stack->content;
	while (stack)
	{
		if (*(int *)stack->content < value)
			value = *(int *)stack->content;
		stack = stack->next;
	}
	return (value);
}
