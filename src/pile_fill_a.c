/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_fill_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 10:39:49 by mmatime           #+#    #+#             */
/*   Updated: 2018/02/12 10:39:50 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

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
	int		nb;
	char	**tab;
	int		i;

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
