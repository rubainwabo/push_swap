/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:23:41 by rkamegne          #+#    #+#             */
/*   Updated: 2019/06/18 22:21:12 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int		deal_key(int key, t_swap *d)
{
	if (key == 53)
	{
		free_lists(d);
		exit(0);
	}
	else if (key == 49)
	{
		if (!d->pause)
			d->pause = 1;
		else if (d->pause == 1)
			d->pause = 0;
	}
	return (0);
}
