/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 13:13:22 by rkamegne          #+#    #+#             */
/*   Updated: 2019/06/19 14:51:15 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void		apply_ops_next(t_swap *d, char *tmp)
{
	if (!ft_strcmp(tmp, ROT_A))
		rotate_a(d);
	else if (!ft_strcmp(tmp, ROT_B))
		rotate_b(d);
	else if (!ft_strcmp(tmp, ROT_R))
		rotate_r(d);
	else if (!ft_strcmp(tmp, REV_ROT_A))
		rev_rotate_a(d);
	else if (!ft_strcmp(tmp, REV_ROT_B))
		rev_rotate_b(d);
	else if (!ft_strcmp(tmp, REV_ROT_R))
		rev_rotate_r(d);
	else if (!ft_strcmp(tmp, SWAP_S))
		swap_ss(d);
}

void		apply_ops(t_swap *d, char *tmp)
{
	if (!ft_strcmp(tmp, SWAP_A))
		swap_a(d);
	else if (!ft_strcmp(tmp, SWAP_B))
		swap_b(d);
	else if (!ft_strcmp(tmp, PUSH_A))
		push_a(d);
	else if (!ft_strcmp(tmp, PUSH_B))
		push_b(d);
	else
		apply_ops_next(d, tmp);
	d->len_a = ft_lstlen(d->a);
	d->len_b = ft_lstlen(d->b);
}
