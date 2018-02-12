/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 10:39:59 by mmatime           #+#    #+#             */
/*   Updated: 2018/02/12 10:40:03 by mmatime          ###   ########.fr       */
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

int		ft_longtoi(const char *str)
{
	long	i;
	int		negativ;
	long	nb;

	i = 0;
	negativ = 0;
	nb = 0;
	if (str[i] == '-')
	{
		negativ = 1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i] - '0';
		if ((nb > 2147483647 && !negativ) || (nb > 2147483648 && negativ))
			return (0);
		i++;
	}
	return (1);
}

int		ft_compare_one_tab(char **tab)
{
	int i;
	int j;

	i = 0;
	if (!ft_longtoi(tab[i]))
		return (0);
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

int		ft_test_duplicate(char **argv, int bonus)
{
	t_te	temp;

	temp.i = (bonus) ? 2 : 1;
	while (argv[temp.i])
	{
		temp.tab_1 = ft_strsplit(argv[temp.i], ' ');
		if (ft_compare_one_tab(temp.tab_1))
		{
			temp.j = temp.i + 1;
			while (argv[temp.j])
			{
				temp.tab_2 = ft_strsplit(argv[temp.j], ' ');
				if (ft_compare_tabs(temp.tab_1, temp.tab_2))
					temp.j++;
				else
					return (0);
				free_tab(temp.tab_2);
			}
		}
		else
			return (0);
		temp.i++;
		free_tab(temp.tab_1);
	}
	return (1);
}

int		valid_tab(char **argv, int bonus)
{
	int i;
	int j;

	i = (bonus) ? 2 : 1;
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
