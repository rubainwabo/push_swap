#include "push_swap.h"

int		ft_checker(int ac, char **av)
{
	t_swap		d;
	int			i;

	i = 0;
	if (!ft_check_str(ac, av))
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (!(d.data = (int *)malloc(sizeof(int) * ac - 1)))
	{
		perror("malloc failed!\n");
		return (0);
	}
	while (i + 1 < ac)
	{
		d.data[i] = ft_atoi(av[i + 1]);
		ft_printf("data stored at %d = %d\n", i, d.data[i]);
		i++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	ft_checker(ac, av);
	return (0);
}