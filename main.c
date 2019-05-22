#include "libft/libft.h"

int     main(int ac, char **av)
{
    while (--ac > 0)
    {
    int i = ft_atoi(av[ac]);
    ft_printf("number = %d\n", i);
    }
    return (0);
}