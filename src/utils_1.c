#include "struct.h"

int		nb_is_max_a(int nb, t_env *a)
{
	int i;

	i = 1;
	while (i < a->size_a)
	{
		if (nb > a->pile_a[i])
			i++;
		else
			return (0);
	}
	return (1);
}

int		nb_is_max_b(int nb, t_env *a)
{
	int i;

	i = 0;
	while (i < a->size_b)
	{
		if (nb > a->pile_b[i])
			i++;
		else
			return (0);
	}
	return (1);
}

int		nb_is_min_b(int nb, t_env *a)
{
	int i;

	i = 0;
	while (i < a->size_b)
	{
		if (nb < a->pile_b[i])
			i++;
		else
			return (0);
	}
	return (1);
}

int		nb_is_min_a(int nb, t_env *a)
{
	int i;

	i = 0;
	while (i < a->size_a)
	{
		if (nb < a->pile_a[i])
			i++;
		else
			return (0);
	}
	return (1);
}

int		last_is_min(int nb, int index, t_env *a)
{
	int i;

	i = index;
	while (i > 0)
	{
		if (nb <= a->pile_a[i])
			i--;
		else
			return (0);
	}
	return (1);
}