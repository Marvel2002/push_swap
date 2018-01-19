/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:47:11 by mmatime           #+#    #+#             */
/*   Updated: 2018/01/19 15:58:18 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int			string_is_digit(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
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
	
	index = 0;
	pile_a = (int *)ft_memalloc(sizeof(*pile_a) * i);
	while (index < i)
	{
		pile_a[index] = ft_atoi(argv[index]);
		index++;
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

int			main(int argc, char **argv)
{
	int i;
	int *pile_a;
	
	i = 1;
	pile_a = NULL;
	if (argc > 1)
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
		ft_putstr("error, not enough arguments\n");
		return (0);
	}
	pile_a = init_pile_a(i, argv);
	ft_put_int_tab(pile_a, i);
	return (0);
}
