/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:46:52 by rkamegne          #+#    #+#             */
/*   Updated: 2019/06/19 14:45:59 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push_b(t_swap *d)
{
	t_list	*tmp;

	if (d->a)
	{
		tmp = d->a;
		d->a = d->a->next;
		tmp->next = NULL;
		ft_lstadd(&d->b, tmp);
		(d->print != 0) ? ft_printf(PUSH_B) : 0;
		(d->arg) ? state_stack(&d->a, 'a') : 0;
		(d->arg) ? state_stack(&d->b, 'b') : 0;
	}
}

void	push_a(t_swap *d)
{
	t_list	*tmp;

	if (d->b)
	{
		tmp = d->b;
		d->b = d->b->next;
		tmp->next = NULL;
		ft_lstadd(&d->a, tmp);
		(d->print != 0) ? ft_printf(PUSH_A) : 0;
		(d->arg) ? state_stack(&d->a, 'a') : 0;
		(d->arg) ? state_stack(&d->b, 'b') : 0;
	}
}
