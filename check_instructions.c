#include "push_swap.h"

int		check_double(t_swap *d, int index, int elt)
{
	while (--index >= 0)
		if (d->data[index] == elt)
			return (0);
	return (1);
}

int     check_instructions(char *str)
{
	if (ft_strcmp(str, A) && ft_strcmp(str, B) && ft_strcmp(str, C) && ft_strcmp(str, D)
	&& ft_strcmp(str, E) && ft_strcmp(str, F) && ft_strcmp(str, G) && ft_strcmp(str, H)
	&& ft_strcmp(str, I) && ft_strcmp(str, J) && ft_strcmp(str, K))
		return (0);
	return (1);
}

int		fill_list(t_swap *d)
{
	char	*line;

	line = NULL;
	d->list = NULL;
	while (get_next_line(0, &line) > 0 && line)
	{
		if (!check_instructions(line))
			return (0);
		if (!d->list)
			d->list = ft_lstnew((void *)line, (size_t)ft_strlen(line));
		else
			ft_lstaddback(&d->list, ft_lstnew((void *)line, (size_t)ft_strlen(line)));
	}
	printf("toto\n");
	return (1);
}

int		fill_tab(t_swap *d, char **av, int len)
{
	int		i;
	int		j;
	int		elt;

	i = 0;
	j = (d->state == 1 && (len--)) ? 0 : 1;
	while (j < len)
	{
		elt = ft_atoi(av[j++]);
		if (!check_double(d, i, elt))
			return (0);
		d->data[i] = elt;
		//ft_printf("data stored at %d = %d\n", i, d->data[i]);
		i++;
	}
	return (1);
}

int    check_str(int ac, char **av, t_swap *d)
{
	int		i;
	int		j;

	i = (d->state == 1) ? 0 : 1;
	if (ac == 1)
	{
		ft_putendl("OK");
		return (1);
	}
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		i++;
		if (i == ac)
		{
			j = ac + ((d->state == 1) ? 1 : 0); // Can't change the value of ac
			if (!fill_tab(d, av, j))
				return (0);
			if (!(fill_list(d)))
				return (0);
		}
	}
	// i = 0;
	// while (d->list)
	// {	i++;
	// 	printf("instruction %d = %s\n",i, (char *)d->list->content);
	// 	d->list = d->list->next;
	// }
	return (1);
}
