#include "struct.h"

void	pile_fill_a_index(t_pile_a *a, int pile_max)
{
	int i;
	int nb_max;
	int	index_max;
	int index_tmp;

	i = 0;
	index_max = pile_max - 1;
	while (index_max >= 0)
	{
		while (a[i].index != -1)
			i++;
		nb_max = a[i].nb;
		index_tmp = i;
		while (i < pile_max)
		{
			if (a[i].nb > nb_max && a[i].index == -1)
			{
				nb_max = a[i].nb;
				index_tmp = i;
			}
			i++;
		}
		a[index_tmp].index = index_max;
		i = 0;
		index_max--;
	}
}

void	pile_fill_a(t_pile_a *a, char **argv)
{
	int		i;
	int		k;
	int		pile_max;
	char 	**tab;

	i = 1;
	pile_max = 0;
	tab = NULL;
	while (argv[i])
	{
		k = 0;
		tab = ft_strsplit(argv[i], ' ');
		while (tab[k])
		{
			a[pile_max].nb = ft_atoi(tab[k]);
			a[pile_max].index = -1;
		//	printf("pile_max = %d, a[pile_max].nb = %d, a[pile_max].index = %d\n", pile_max, a[pile_max].nb, a[pile_max].index);
			k++;
			pile_max++;
		}
		free_tab(tab);
		i++;
	}
	pile_fill_a_index(a, pile_max);
	i = 0;
	while (i < pile_max)
	{
		printf("pile_max = %d, a[pile_max].nb = %d, a[pile_max].index = %d\n", i, a[i].nb, a[i].index);
		i++;
	}
}

t_env			*pile_init(void)
{
	t_env *a;
	int count;

	count = count_int_argv(argv);
	a = (t_env *)ft_memalloc(sizeof(t_env));
	a->pile_a = (pile_a *)ft_memalloc(sizeof(pile_a) * count);
	a->pile_b = (pile_b *)ft_memalloc(sizeof(pile_b) * count);

	return (a);
}

/*t_pile_a		*pile_init_a(char **argv)
{
	t_pile_a 	*a;
	int 		count;

	count = count_int_argv(argv);
	a = ft_memalloc(sizeof(t_pile_a) * count);
	if (!a)
		return (NULL);
	else
	{
		pile_fill_a(a, argv);
		return (a);
	}
}

t_pile_b		*pile_init_b(char **argv)
{
	t_pile_b 	*b;
	int			count;
	int			i;

	i = 0;
	count = count_int_argv(argv);
	b = ft_memalloc(sizeof(t_pile_b) * count);
	if (!b)
		return (NULL);
	else
	{
		while (i < count)
		{
			b[i].index = -1;
			i++;
		}
		return (b);
	}
}
*/
void	ft_putstr_error(char const *s)
{
	if (!s)
		return ;
	while (*s)
	{
		write(0, &*s, 1);
		s++;
	}
}