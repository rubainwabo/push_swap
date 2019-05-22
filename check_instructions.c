#include "push_swap.h"

int     ft_check_instructions(char *str)
{
	if (ft_strcmp(str, A) && ft_strcmp(str, B) && ft_strcmp(str, C) && ft_strcmp(str, D)
	&& ft_strcmp(str, E) && ft_strcmp(str, F) && ft_strcmp(str, G) && ft_strcmp(str, H)
	&& ft_strcmp(str, I) && ft_strcmp(str, J))
		return (0);
	return (1);
}

int    ft_check_str(int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
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
	}
	return (1);
}