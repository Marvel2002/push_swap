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
	if (a->size_b > 1 && a->med && a->pile_b[0].index >= a->med)
		ft_rotate_b(a);
}

int		pile_is_sort(t_env *a)
{
	int i;

	i = 0;
	while (a->pile_a[i].index == i)
		i++;
	if (i == a->size_a)
		return (1);
	return (0);
}

int		next_is_in_b(t_env *a, int next)
{
	int i;

	i = 0;
	while (i < a->size_b)
	{
		if (a->pile_b[i].index == next)
			return (1);
		i++;
	}
	return (0);
}

void	find_and_place_next(t_env *a)
{
	int next;

	next = 1;
	while (a->pile_a[0].index != 0 || a->size_b)
	{
		if (next_is_in_b(a, next))
		{
			if (a->pile_b[0].index == next)
			{
				ft_push_a(a);
				ft_rotate_a(a);
				next++;
				a->med++;
			}
			else if (a->pile_b[a->size_b - 1].index == next)
			{
				ft_reverse_rotate_b(a);
				ft_push_a(a);
				ft_rotate_a(a);
				next++;
				a->med++;
			}
			else
			{
				if (a->size_b > 1 && a->med && a->pile_b[0].index >= a->med)
					ft_rotate_b(a);
				else
					ft_push_a(a);
			}
		}
		else
		{
			if (a->pile_a[0].index == next)
			{
				ft_rotate_a(a);
				next++;
				a->med++;
			}
			else if (a->pile_a[1].index == next)
			{
				ft_swap_a(a);
				ft_rotate_a(a);
				next++;
				a->med++;
			}
			else
			{
				ft_push_b(a);
				if (a->size_b > 1 && a->med && a->pile_b[0].index >= a->med)
					ft_rotate_b(a);
			}
		}
	}
}

void	find_and_place_zero(t_env *a)
{
	if (!pile_is_sort(a))
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
	find_and_place_next(a);
}

