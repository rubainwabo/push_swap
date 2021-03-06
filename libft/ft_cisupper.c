/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 20:02:26 by rkamegne          #+#    #+#             */
/*   Updated: 2018/10/22 20:37:48 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_cisupper(int c)
{
	if (ft_isalpha(c) == 0)
		return (-1);
	else
	{
		if (c >= 'A' && c <= 'Z')
			return (1);
		else
			return (0);
	}
}
