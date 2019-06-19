/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 10:52:16 by rkamegne          #+#    #+#             */
/*   Updated: 2019/06/19 14:52:07 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int		check_instructions(char *str)
{
	if (ft_strcmp(str, SWAP_A) && ft_strcmp(str, SWAP_B) &&
	ft_strcmp(str, PUSH_A) && ft_strcmp(str, PUSH_B) && ft_strcmp(str, ROT_A)
	&& ft_strcmp(str, ROT_B) && ft_strcmp(str, ROT_R)
	&& ft_strcmp(str, REV_ROT_A) && ft_strcmp(str, REV_ROT_B)
	&& ft_strcmp(str, REV_ROT_R) && ft_strcmp(str, SWAP_S))
		return (0);
	return (1);
}

int		fill_list(t_swap *d)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (!check_instructions(line))
			return (0);
		if (!d->list_ins)
		{
			if (!(d->list_ins = ft_lstnew((void *)line,
							(size_t)ft_strlen(line))))
				return (0);
		}
		else
			ft_lstaddback(&d->list_ins, ft_lstnew((void *)line,
			(size_t)ft_strlen(line)));
		free(line);
	}
	return (1);
}
