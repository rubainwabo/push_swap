/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny_lists.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 10:36:19 by rkamegne          #+#    #+#             */
/*   Updated: 2019/06/19 00:44:11 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void			sort_2(t_swap *d, char s)
{
	if (s == 'a' && *(int *)d->a->next->content < *(int *)d->a->content)
		swap_a(d);
	if (s == 'b' && *(int *)d->b->next->content > *(int *)d->b->content)
		swap_b(d);
}

void			sort_3(t_swap *d)
{
	t_list	*stack;

	stack = d->a;
	if (!check_sorted(stack))
	{
		if (find(stack, 0) == 1)
		{
			rev_rotate_a(d);
			swap_a(d);
		}
		else if (find(stack, 0) == 2 && find(stack, 1) == 3)
			swap_a(d);
		else if (find(stack, 0) == 2 && find(stack, 1) == 1)
			rotate_a(d);
		else if (find(stack, 0) == 3 && find(stack, 1) == 2)
			rev_rotate_a(d);
		else
		{
			rotate_a(d);
			swap_a(d);
		}
	}
}

void			sort_4(t_swap *d)
{
	int		pos;
	int		i;
	t_list	*stack;

	stack = d->a;
	if (check_sorted(stack))
		return ;
	pos = pos_min(stack);
	i = -1;
	if (pos > 2)
		while (++i < 4 - pos)
			rev_rotate_a(d);
	else
		while (++i < pos)
			rotate_a(d);
	push_b(d);
	d->len_a = ft_lstlen(d->a);
	d->len_b = ft_lstlen(d->b);
	sort_3(d);
	push_a(d);
}

void			sort_5(t_swap *d)
{
	int		pos;
	int		i;
	t_list	*stack;

	stack = d->a;
	if (check_sorted(stack))
		return ;
	pos = pos_min(stack);
	i = -1;
	if (pos > 2)
		while (++i < 5 - pos)
			rev_rotate_a(d);
	else
		while (++i < pos)
			rotate_a(d);
	push_b(d);
	d->len_a = ft_lstlen(d->a);
	d->len_b = ft_lstlen(d->b);
	sort_4(d);
	push_a(d);
}
