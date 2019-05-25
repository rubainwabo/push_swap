#include "push_swap.h"

void		fill_tab(t_swap *d, char **av, int len)
{
	int	i;
	int	j;

	i = 0;
	j = (d->state == 1 && (len--)) ? 0 : 1;
	while (j < len)
	{
		d->data[i] = ft_atoi(av[j]);
		ft_printf("data stored at %d = %d\n", i, d->data[i]);
		i++;
		j++;
	}
}
int		ft_checker(int ac, char **av)
{
	t_swap			d;

	if (ac == 2)
	{
		d.state = 1;
		if (!(av = ft_strsplit(av[1], ' ')))
		{
			perror("malloc failed");
			return (0);
		}
		ac -= 2;
		while (av[ac])
			ac++;
	}
	if (!ft_check_str(ac, av, &d))
	{
		ft_putstr("Error\n");
		return (0);
	}
	ac += (d.state == 1) ? 1 : 0;
	if (!(d.data = (int *)malloc(sizeof(int) * (ac - 1))))
	{
		perror("malloc failed!\n");
		return (0);
	}
	fill_tab(&d, av, ac);
	return (1);
}

int		main(int ac, char **av)
{
	ft_checker(ac, av);
	return (0);
}
