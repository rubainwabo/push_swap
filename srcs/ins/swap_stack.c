/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:12:49 by rkamegne          #+#    #+#             */
/*   Updated: 2019/06/19 14:48:38 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	swap_a(t_swap *d)
{
	void	*temp;

	if (d->a && d->a->next)
	{
		temp = d->a->content;
		d->a->content = d->a->next->content;
		d->a->next->content = temp;
		(d->print != 0) ? ft_printf(SWAP_A) : 0;
		(d->arg) ? state_stack(&d->a, 'a') : 0;
	}
}

void	swap_b(t_swap *d)
{
	void	*temp;

	if (d->b && d->b->next)
	{
		temp = d->b->content;
		d->b->content = d->b->next->content;
		d->b->next->content = temp;
		(d->print != 0) ? ft_printf(SWAP_B) : 0;
		(d->arg) ? state_stack(&d->b, 'b') : 0;
	}
}

void	swap_ss(t_swap *d)
{
	int		tmp;

	tmp = d->print;
	(d->print != 0) ? ft_printf(SWAP_S) : 0;
	d->print = 0;
	swap_a(d);
	swap_b(d);
	d->print = tmp;
}
