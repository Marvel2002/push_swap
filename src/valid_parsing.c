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

int				valid_char(char nb, char nb_plus)
{
	if (ft_isdigit(nb) && !(nb_plus == '-'))
		return (1);
	else if (nb == '-' && ft_isdigit(nb_plus))
		return (1);
	return (0);
}

void	ft_quit(t_env *a)
{
	write(2, "Error\n", 6);
	ft_free(a);
	exit(1);
}

int		ft_double(t_env *a)
{
	int i;
	int j;

	i = a->size_a - 1;
	while (i > 0)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (a->pile_a[i].nb != a->pile_a[j].nb)
				j--;
			else
				return (0);
		}
		i--;
	}
	return (1);
}
