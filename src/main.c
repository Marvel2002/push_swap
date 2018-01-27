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
				free_tab(tab_2);
			}
		}
		else
			return (0);
		i++;
		free_tab(tab_1);
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
			if (valid_char(argv[i][j], argv[i][j + 1]))
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
	a->pile_a = (int*)ft_memalloc(sizeof(int) * a->pile_max);
	a->pile_b = (int*)ft_memalloc(sizeof(int) * a->pile_max);
	a->size_a = a->pile_max;
	a->size_b = 0;
	a->push_on_a = 0;
	a->push_on_b = 0;
	a->sa = 0;
	a->sb = 0;
	a->ss = 0;
	a->pa = 0;
	a->pb = 0;
	a->ra = 0;
	a->rb = 0;
	a->rr = 0;
	a->rra = 0;
	a->rrb = 0;
	a->rrr = 0;
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

void	display(int *tab, int count, char c)
{
	int i;

	i = 0;
	ft_putstr("pile ");
	ft_putchar(c);
	ft_putstr("= ");
	while (i < count)
	{
		ft_putnbr(tab[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

int		first_is_max(int nb, t_env *a)
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

void	sort_pile_a(t_env *a)
{
	int i;

	i = 0;
	while (i < a->size_a && a->pile_max > 1)
	{
		if (i == 0 && first_is_max(a->pile_a[i], a))
			ft_rotate_a(a);
		else if (i == a->size_a - 1 && last_is_min(a->pile_a[i], i, a) && a->size_a > 2)
			ft_reverse_rotate_a(a);
		else if (i == 1 && a->pile_a[i] < a->pile_a[i - 1])
		{
			ft_swap_a(a);
			i = 0;
		}
		else if (i > 1 && a->pile_a[i] < a->pile_a[i - 1])
		{
			ft_push_b(a);
			i = 0;
		}
		else
			i++;
	}
}

void	start_sort(t_env *a)
{
	sort_pile_a(a);
	while (a->size_b)
	{
		ft_push_a(a);
		sort_pile_a(a);
	}
}

void	display_instruct(t_env *a)
{
	printf("sa = %d\n", a->sa);
	printf("sb = %d\n", a->sb);
	printf("ss = %d\n", a->ss);
	printf("pa = %d\n", a->pa);
	printf("pb = %d\n", a->pb);
	printf("ra = %d\n", a->ra);
	printf("rb = %d\n", a->rb);
	printf("rr = %d\n", a->rr);
	printf("rra = %d\n", a->rra);
	printf("rrb = %d\n", a->rrb);
	printf("rrr = %d\n", a->rrr);
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
			pile_init(a, argv); 
			pile_fill(a, argv);
			start_sort(a);
			display(a->pile_a, a->size_a, 'a');
			display_instruct(a);
		}
		else
			ft_putstr("Error\n");
	}
	else
		ft_putstr("Error\n");
	return (0);
}
