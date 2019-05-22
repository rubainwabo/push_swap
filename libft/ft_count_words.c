/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 20:41:33 by rkamegne          #+#    #+#             */
/*   Updated: 2019/04/07 16:08:13 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(const char *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = -1;
	while (s[++i] && s[i] == c)
		count++;
	return (count);
}
