/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 10:39:56 by mmatime           #+#    #+#             */
/*   Updated: 2018/02/12 10:39:58 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	pile_fill_a_index(t_env *a)
{
	int i;
	int nb_max;
	int	index_max;
	int index_tmp;

	i = 0;
	index_max = a->size_max - 1;
	while (index_max >= 0)
	{
		while (a->pile_a[i].index != -1)
			i++;
		nb_max = a->pile_a[i].nb;
		index_tmp = i;
		while (i < a->size_max)
		{
			if (a->pile_a[i].nb > nb_max && a->pile_a[i].index == -1)
			{
				nb_max = a->pile_a[i].nb;
				index_tmp = i;
			}
			i++;
		}
		a->pile_a[index_tmp].index = index_max;
		i = 0;
		index_max--;
	}
}

void	pile_fill_a(t_env *a, char **argv)
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
			a->pile_a[pile_max].nb = ft_atoi(tab[k]);
			a->pile_a[pile_max].index = -1;
			k++;
			pile_max++;
		}
		free_tab(tab);
		i++;
	}
	pile_fill_a_index(a);
}

t_env			*pile_init(char **argv)
{
	t_env *a;

	a = (t_env *)ft_memalloc(sizeof(t_env));
	a->size_max = count_int_argv(argv);
	a->size_a = a->size_max;
	if (a->size_max > 11)
		a->med = a->size_max / 8;
	else
		a->med = 0;
	a->pile_a = (t_pile *)ft_memalloc(sizeof(t_pile) * a->size_max);
	a->pile_b = (t_pile *)ft_memalloc(sizeof(t_pile) * a->size_max);
	return (a);
}

void	ft_putstr_error(char const *s)
{
	if (!s)
		return ;
	while (*s)
	{
		write(2, &*s, 1);
		s++;
	}
}
