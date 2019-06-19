/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 02:40:38 by rkamegne          #+#    #+#             */
/*   Updated: 2019/06/19 14:54:01 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static	t_list	*get_tail(t_list **stack)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *stack;
	prev = NULL;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (prev)
		prev->next = NULL;
	return (tmp);
}

void			rev_rotate_a(t_swap *d)
{
	t_list		*tmp;

	if (d->a && d->a->next)
	{
		tmp = get_tail(&d->a);
		ft_lstadd(&d->a, tmp);
		(d->print != 0) ? ft_printf(REV_ROT_A) : 0;
		(d->arg) ? state_stack(&d->a, 'a') : 0;
	}
}

void			rev_rotate_b(t_swap *d)
{
	t_list		*tmp;

	if (d->b && d->b->next)
	{
		tmp = get_tail(&d->b);
		ft_lstadd(&d->b, tmp);
		(d->print != 0) ? ft_printf(REV_ROT_B) : 0;
		(d->arg) ? state_stack(&d->b, 'b') : 0;
	}
}

void			rev_rotate_r(t_swap *d)
{
	int		tmp;

	tmp = d->print;
	(d->print != 0) ? ft_printf(REV_ROT_R) : 0;
	d->print = 0;
	rev_rotate_a(d);
	rev_rotate_b(d);
	d->print = tmp;
}
