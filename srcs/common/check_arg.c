/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:12:32 by rkamegne          #+#    #+#             */
/*   Updated: 2019/06/18 23:23:13 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static	int		check_double(t_list *lst, int num)
{
	t_list	*tmp;
	int		n;

	tmp = lst;
	while (tmp)
	{
		n = *((int *)tmp->content);
		if (n == num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static	int		check_integer(char *str, int *num)
{
	int		sign;
	int		len;

	*num = ft_atoi(str);
	if ((sign = *str == '-'))
		str++;
	if (!ft_isnumber(str))
		return (0);
	while (*str == '0')
		str++;
	len = ft_strlen(str);
	if (len > 10 || (len == 10 && *str > '2'))
		return (0);
	return (!((sign && *num > 0) || (!sign && *num < 0)));
}

static	int		init_stack(t_swap *d, char *str)
{
	int		n;
	t_list	*new;

	if (!(check_integer(str, &n)) || !(new = ft_lstnew((void *)&n,
					sizeof(int))))
		return (0);
	if (!d->a)
		d->a = new;
	else
	{
		if (!(check_double(d->a, n)))
		{
			ft_lstdelone(&new, ft_free_content);
			return (0);
		}
		ft_lstaddback(&d->a, new);
	}
	return (1);
}

static	int		init_list(int i, int ac, char **av, t_swap *d)
{
	while (i < ac)
	{
		if (!init_stack(d, av[i]))
			return (0);
		i++;
		if (d->fct && i == ac)
		{
			if (!(fill_list(d)))
				return (0);
		}
	}
	return (1);
}

int				check_arg(int ac, char **av, t_swap *d)
{
	int			i;
	int			num;

	d->a = NULL;
	d->list_ins = NULL;
	num = 0;
	i = (d->state == 1) ? 0 : 1;
	i += (d->arg && !d->state) ? 1 : 0;
	if (ac == 1)
	{
		if (!(check_integer(av[i], &num)))
			return (0);
		(d->fct != 0 && d->fct != 2) ? ft_putendl("OK") : 0;
		exit(0);
	}
	if (!init_list(i, ac, av, d))
		return (0);
	return (1);
}
