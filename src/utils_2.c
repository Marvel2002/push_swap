#include "struct.h"

int		set_index_min_position_b(t_env *a)
{
	int i;
	int nb_min;
	int index_min;

	i = 1;
	index_min = 0;
	nb_min = a->pile_b[0];
	while (i < a->size_b)
	{
		if (nb_min > a->pile_b[i])
		{
			index_min = i;
			nb_min = a->pile_b[i];
		}
		i++;
	}
	return (index_min);
}

int		set_index_max_position_b(t_env *a)
{
	int i;
	int nb_max;
	int index_max;

	i = 1;
	index_max = 0;
	nb_max = a->pile_b[0];
	while (i < a->size_b)
	{
		if (nb_max < a->pile_b[i])
		{
			index_max = i;
			nb_max = a->pile_b[i];
		}
		i++;
	}
	return (index_max);
}

int		set_index_max_position_a(t_env *a)
{
	int i;
	int nb_max;
	int index_max;

	i = 1;
	index_max = 0;
	nb_max = a->pile_a[0];
	while (i < a->size_a)
	{
		if (nb_max < a->pile_a[i])
		{
			index_max = i;
			nb_max = a->pile_a[i];
		}
		i++;
	}
	return (index_max);
}

int		set_index_min_position_a(t_env *a)
{
	int i;
	int nb_min;
	int index_min;

	i = 1;
	index_min = 0;
	nb_min = a->pile_a[0];
	while (i < a->size_a)
	{
		if (nb_min > a->pile_a[i])
		{
			index_min = i;
			nb_min = a->pile_a[i];
		}
		i++;
	}
	return (index_min);
}

void	calcule_rotation_on_b(t_env *a)
{
	int index_max;

	index_max = set_index_max_position_b(a);
	while (index_max > 0)
	{
		ft_rotate_b(a);
		index_max--;
	}
	ft_push_b(a);
}