#include "push_swap.h"

void	sort_tab(int *tab, int len)
{
	int		i;
	int		tmp;

	i = 0;
	while(i + 1 < len)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

int		ft_checker(int ac, char **av)
{
	t_swap			d;

	d.state = 0;
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
	ac += ((d.state == 1) ? 1 : 0);
	if (!(d.data = (int *)malloc(sizeof(int) * (ac - 1))))
	{
		perror("malloc failed!\n");
		return (0);
	}
	ac -= ((d.state == 1) ? 1 : 0);
	if (!check_str(ac, av, &d))
	{
		ft_putstr("Error\n");
		return (0);
	}
	sort_tab(d.data, ac);
	d.state = 0;
	ac -= ((d.state == 0) ? 1 : 0);
	while (d.state < ac)
		//ft_printf("Sorted tab element %d = %d\n", d.state, d.data[d.state]);
		d.state++;
	return (1);
}

int		main(int ac, char **av)
{
	ft_checker(ac, av);
	return (0);
}
