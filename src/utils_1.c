#include "struct.h"

void	display(t_env *a)
{
	int i;

	i = 0;
	ft_putstr("pile a = ");
	while (i < a->size_a)
	{
		ft_putnbr_c(a->pile_a[i].index, ' ');
		i++;	
	}
	ft_putchar('\n');
	i = 0;
	ft_putstr("pile b = ");
	while (i < a->size_b)
	{
		ft_putnbr_c(a->pile_b[i].index, ' ');
		i++;	
	}
	ft_putchar('\n');
}