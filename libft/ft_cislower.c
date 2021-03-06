/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 20:00:24 by rkamegne          #+#    #+#             */
/*   Updated: 2018/10/22 20:37:36 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_cislower(int c)
{
	if (ft_isalpha(c) == 0)
		return (-1);
	else
	{
		if (c >= 'a' && c <= 'z')
			return (1);
		else
			return (0);
	}
}
