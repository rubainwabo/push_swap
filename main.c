#include "libft/libft.h"
#include <stdio.h>

int     main(int ac, char **av)
{
    /*while (--ac > 0)
    {
    int i = ft_atoi(av[ac]);
    ft_printf("number = %d\n", i);
    }*/
	char	*line;
	while (get_next_line(0, &line) > 0 && line)
	{
		ft_printf("line read = %s\n", line);
		free(line);
	}
    return (0);
}
