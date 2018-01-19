/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:47:11 by mmatime           #+#    #+#             */
/*   Updated: 2018/01/19 18:02:20 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int			string_is_digit(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9'))
			i++;
		else
			return (0);
	}
	return (1);
}

int			*init_pile_a(int i, char **argv)
{
	int	*pile_a;
	int index;
	int	index_zero;
	
	index = 1;
	index_zero = 0;
	pile_a = (int *)ft_memalloc(sizeof(*pile_a) * i);
	while (index < i)
	{
		pile_a[index_zero] = ft_atoi(argv[index]);
		index++;
		index_zero++;
	}
	return (pile_a);
}

void	ft_put_int_tab(int *tab, int i)
{
	int index;

	index = 0;
	while (index < i)
	{
		ft_putnbr(tab[index]);
		ft_putchar('\n');
		index++;
	}
}

int		ft_test_doublons(char **argv)
{
	int i;
	int cmp;
	int cmp_2;
	
	i = 1;
	cmp = 0;
	while (argv[i])
		i++;
	i--;
	while (i > 0)
	{
		cmp_2 = i - 1;
		while (cmp_2 > 0)
		{
			cmp = ft_strcmp(argv[i], argv[cmp_2]);
			if (cmp == 0)
				return (0);
			else
				cmp_2--;
		}
		i--;
	}
	return (1);
}

int			main(int argc, char **argv)
{
	int i;
	int *pile_a;
	int *pile_b;
	
	i = 1;
	pile_a = NULL;
	pile_b = NULL;
	if (argc > 1 && ft_test_doublons(argv))
	{
		while (i < argc)
		{
			if (string_is_digit(argv[i]))
				i++;
			else
			{
				ft_putstr("error, not an int\n");
				return (0);
			}
		}
	}
	else
	{
		ft_putstr("error, not enough arguments or same values registered\n");
		return (0);
	}
	pile_a = init_pile_a(i, argv);
	pile_b = (int *)ft_memalloc(sizeof(*pile_b) * i);
	i = 0;
	while (i < argc - 1) // affichage du tableau apres son initialisation
	{
		ft_putnbr(pile_a[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
