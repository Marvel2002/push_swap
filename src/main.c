/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:12:24 by mmatime           #+#    #+#             */
/*   Updated: 2018/01/23 16:27:52 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int		valid_char(char nb, char nb_plus)
{
	if (ft_isdigit(nb) && !(nb_plus == '-'))
		return (1);
	else if (nb == '-' && ft_isdigit(nb_plus))
		return (1);
	else
		return (0);
}

int		ft_compare_one_tab(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]) == 0)
				return (0);
			else
				j++;
		}
		i++;
	}
	return (1);
}

int		ft_compare_tabs(char **tab_1, char **tab_2)
{
	int i;
	int j;

	i = 0;
	while (tab_1[i])
	{
		j = 0;
		while (tab_2[j])
		{
			if (ft_strcmp(tab_1[i], tab_2[j]) == 0)
				return (0);
			else
				j++;
		}
		i++;
	}
	return (1);
}

int		ft_test_duplicate(char **argv)
{
	int i;
	int j;
	char **tab_1;
	char **tab_2;

	i = 1;
	tab_1 = NULL;
	tab_2 = NULL;
	while (argv[i])
	{
		tab_1 = ft_strsplit(argv[i], ' ');
		if (ft_compare_one_tab(tab_1))
		{
			j = i + 1;
			while (argv[j])
			{
				tab_2 = ft_strsplit(argv[j], ' ');
				if (ft_compare_tabs(tab_1, tab_2))
					j++;
				else
					return (0);
			}
		}
		else
			return (0);
		i++;
	}
	return (1);
}


int		valid_tab(char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "") == 0)
			return (0);
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] == ' ' || argv[i][j] == '\t')
				j++;
			if (valid_char(argv[i][j], argv[i][j + 1]) || valid_char(argv[i][j], argv[i][j + 1]))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int			count_int_tab(char **tab)
{
	int i;
	
	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void		free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int			count_int_argv(char **argv)
{
	int nb;
	char **tab;
	int i;

	nb = 0;
	i = 1;
	tab = NULL;
	while (argv[i])
	{
		tab = ft_strsplit(argv[i], ' ');
		nb += count_int_tab(tab);
		free_tab(tab);
		i++;
	}
	return (nb);
}

void		add_from_tab(t_env *a, char **tab, int k)
{
	int index;
	int index_i;

	index = 0;
	index_i = k;
	while (tab[index])
	{
		a->pile_a[index_i] = ft_atoi(tab[index]);
		index++;
		index_i++;
	}
}

void		pile_init(t_env *a, char **argv)
{
	a->pile_max = count_int_argv(argv);
	a->pile_a = (int*)ft_memalloc(sizeof(int*) * a->pile_max);
	a->pile_b = (int*)ft_memalloc(sizeof(int*) * a->pile_max);
	a->size_a = a->pile_max;
	a->size_b = 0;
}

void	pile_fill(t_env *a, char **argv)
{
	int i;
	int nb;
	char **tab;
	int k;

	i = 1;
	nb = 0;
	tab = NULL;
	k = 0;
	while (argv[i])
	{
		tab = ft_strsplit(argv[i], ' ');
		nb = count_int_tab(tab);
		if (nb == 1)
		{
			a->pile_a[k] = ft_atoi(argv[i]);
			k++;
		}
		else
		{
			add_from_tab(a, tab, k);
			k += nb;
		}
		free_tab(tab);
		i++;
	}	
}

void	ft_puttabint(int *tab, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		ft_putnbr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}
	

int		main(int argc, char **argv)
{
	t_env *a;

	a = NULL;
	if (argc > 1 && valid_tab(argv) && ft_test_duplicate(argv))
	{
		if ((a = (t_env*)malloc(sizeof(*a))))
		{
			ft_putstr("OK\n");
			/*pile_init(a, argv); // toutes ces opérations servent à tester les fonctions pour avoir le même résultat que le sujet
			pile_fill(a, argv);
			ft_putstr("pile_A = \n");
			ft_puttabint(a->pile_a, a->size_a);
			ft_putstr("pile_B = \n");
			ft_puttabint(a->pile_b, a->size_b);
			ft_swap_a(a);
			ft_putstr("pile_A = \n");
			ft_puttabint(a->pile_a, a->size_a);
			ft_putstr("pile_B = \n");
			ft_puttabint(a->pile_b, a->size_b);
			ft_push_b(a);
			ft_push_b(a);
			ft_push_b(a);
			ft_putstr("pile_A = \n");
			ft_puttabint(a->pile_a, a->size_a);
			ft_putstr("pile_B = \n");
			ft_puttabint(a->pile_b, a->size_b);
			ft_rr(a);
			ft_putstr("pile_A = \n");
			ft_puttabint(a->pile_a, a->size_a);
			ft_putstr("pile_B = \n");
			ft_puttabint(a->pile_b, a->size_b);
			ft_rrr(a);
			ft_putstr("pile_A = \n");
			ft_puttabint(a->pile_a, a->size_a);
			ft_putstr("pile_B = \n");
			ft_puttabint(a->pile_b, a->size_b);
			ft_swap_a(a);
			ft_putstr("pile_A = \n");
			ft_puttabint(a->pile_a, a->size_a);
			ft_putstr("pile_B = \n");
			ft_puttabint(a->pile_b, a->size_b);
			ft_push_a(a);
			ft_push_a(a);
			ft_push_a(a);
			ft_putstr("pile_A = \n");
			ft_puttabint(a->pile_a, a->size_a);
			ft_putstr("pile_B = \n");
			ft_puttabint(a->pile_b, a->size_b);*/
		}
		else
			return (0);
	}
	else
		ft_putstr("Error\n");
	return (0);
}
