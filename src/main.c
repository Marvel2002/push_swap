/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:12:24 by mmatime           #+#    #+#             */
/*   Updated: 2018/01/22 13:11:39 by mmatime          ###   ########.fr       */
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

int		valid_tab(char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (valid_char(argv[i][j], argv[i][j + 1]) || valid_char(argv[i][j], argv[i][j + 1]))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_struct *a;

	a = NULL;
	if (argc > 1 && valid_tab(argv))
	{
		if ((a = malloc(sizeof(t_struct*))))
			;
		else
			return (0);
	}
	else
		ft_putstr("error\n");
	return (0);
}
