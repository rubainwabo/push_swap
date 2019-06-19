/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:12:56 by rkamegne          #+#    #+#             */
/*   Updated: 2019/06/19 14:45:52 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	state_stack(t_list **stack, char c)
{
	t_list			*tmp;
	char			*color;

	color = NULL;
	if (stack && *stack)
	{
		tmp = *stack;
		color = (c == 'a') ? RED : BLUE;
		ft_printf("%s=================================================%s\n",
				color, BLACK);
		ft_printf("%sstack %c : %s", color, c, BLACK);
		while (tmp)
		{
			ft_printf(" %s%d%s", color, *((int *)tmp->content), BLACK);
			tmp = tmp->next;
		}
		ft_printf("\n%s==============================================%s\n",
				color, BLACK);
	}
}

void	rotate_a(t_swap *d)
{
	t_list	*tmp;

	if (d->a && d->a->next)
	{
		tmp = d->a;
		d->a = d->a->next;
		tmp->next = NULL;
		ft_lstaddback(&d->a, tmp);
		(d->print != 0) ? ft_printf(ROT_A) : 0;
		(d->arg) ? state_stack(&d->a, 'a') : 0;
	}
}

void	rotate_b(t_swap *d)
{
	t_list	*tmp;

	if (d->b && d->b->next)
	{
		tmp = d->b;
		d->b = d->b->next;
		tmp->next = NULL;
		ft_lstaddback(&d->b, tmp);
		(d->print != 0) ? ft_printf(ROT_B) : 0;
		(d->arg) ? state_stack(&d->b, 'b') : 0;
	}
}

void	rotate_r(t_swap *d)
{
	int		tmp;

	tmp = d->print;
	(d->print != 0) ? ft_printf(ROT_R) : 0;
	d->print = 0;
	rotate_a(d);
	rotate_b(d);
	d->print = tmp;
}
