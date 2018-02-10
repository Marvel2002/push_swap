#include "struct.h"

int		pos_zero(t_env *a)
{
	int i;

	i = 0;
	while (a->pile_a[i].index != 0)
		i++;
	return (i);
}

void	iter_to_zero(t_env *a)
{
	if (pos_zero(a) < a->size_a / 2)
		ft_push_b(a);
	else
	{
		ft_reverse_rotate_a(a);
		ft_push_b(a);
	}
	if (a->size_b > 1 && a->med && a->pile_b[0].index > a->med)
		ft_rotate_b(a);
}

void	find_and_place_zero(t_env *a)
{
	while (a->pile_a[a->size_a - 1].index != 0)
	{
		if (a->pile_a[1].index == 0)
		{
			ft_swap_a(a);
			ft_rotate_a(a);
		}
		else if (a->pile_a[0].index == 0)
			ft_rotate_a(a);
		else if (a->pile_a[a->size_a - 2].index == 0)
			ft_reverse_rotate_a(a);
		else
			iter_to_zero(a);
	}
}

/*void	sort_pile_b(t_env *a)
{
	int i;
	int index_min;
	int nb;

	i = a->size_b - 1;
	index_min = set_index_min_position_b(a);
	nb = a->pile_a[0];
	if (a->size_b == 0 || a->size_b == 1)
		ft_push_b(a);
	else if (a->size_b == 2)
	{
		if (index_min == 0)
			ft_swap_b(a);
		ft_push_b(a);
		if (a->pile_b[0] < a->pile_b[1] && a->pile_b[0] > a->pile_b[2])
			ft_swap_b(a);
	}
	else
	{

		if (nb_is_max_b(nb, a) || nb_is_min_b(nb, a))
		{
			if (set_index_max_position_b(a) == 0)
				ft_push_b(a);
			else
				calcule_rotation_on_b(a);
		}
		else
			calcule_rotation_mid_b(nb, a);
	}
}

void	sort_pile_a(t_env *a)
{
	int i;
	int j;
	int index_max;
	int index_min;

	i = 0;
	j = 0;
//	ft_putstr("LA PILE RECUE EST : \n");
//	display(a->pile_a, a->size_a, 'a');
	while (i < a->pile_max)
	{
		if (a->pile_a[0] > a->pile_a[1])
			ft_swap_a(a);
		else if (a->pile_a[0] < a->pile_a[1] && a->pile_a[0] < a->pile_a[a->size_a - 1] && i == 0)
		{
			ft_rotate_a(a);
			i++;
		}
		else if (a->pile_a[0] < a->pile_a[1] && a->pile_a[0] > a->pile_a[a->size_a - 1])
		{
			ft_rotate_a(a);
			i++;
		}
		else
		{
			sort_pile_b(a);
			i++;
		}
	}
	index_max = set_index_max_position_b(a);
	if ((a->size_b - index_max) > index_max)
	{
		while (index_max > 0)
		{
			ft_rotate_b(a);
			index_max--;
		}
	}
	else
	{
		while (index_max < a->size_b)
		{
			ft_reverse_rotate_b(a);
			index_max++;
		}
	}
	index_min = 0;
	ft_rotate_a(a);
	while (a->size_b && !nb_is_min_a(a->pile_b[0], a))
	{
		if (a->pile_b[0] > a->pile_a[a->size_a - 1])
			ft_push_a(a);
		else
			ft_reverse_rotate_a(a);
	}
	while (set_index_max_position_a(a) != a->size_a - 1)
		ft_reverse_rotate_a(a);
	while (a->size_b)
		ft_push_a(a);
//	ft_putstr("LA PILE TRIÉE EST : \n");
//	display(a->pile_a, a->size_a, 'a');
}*/




