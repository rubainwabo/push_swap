#include "push_swap.h"

int     ft_check_instructions(char *str)
{
	if (ft_strcmp(str, A) && ft_strcmp(str, B) && ft_strcmp(str, C) && ft_strcmp(str, D)
	&& ft_strcmp(str, E) && ft_strcmp(str, F) && ft_strcmp(str, G) && ft_strcmp(str, H)
	&& ft_strcmp(str, I) && ft_strcmp(str, J) && ft_strcmp(str, K))
		return (0);
	return (1);
}

int    ft_check_str(int ac, char **av, t_swap *d)
{
	int		i;
	int		j;
	char		*line;
	t_list		*list;

	i = (d->state) ? 0 : 1;
	list = NULL;
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
			while (get_next_line(0, &line) > 0 && line)
			{
				if (!ft_check_instructions(line))
					return (0);
				if (!list)
					list = ft_lstnew((void *)line, (size_t)ft_strlen(line));
				else
					ft_lstaddback(&list, ft_lstnew((void *)line, (size_t)ft_strlen(line)));
			}
		}
	}
		i = 0;
		while (list)
		{	i++;
			ft_printf("instruction %d = %s\n",i, (char *)list->content);
			list = list->next;
		}
	return (1);
}
