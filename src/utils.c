/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 10:39:54 by mmatime           #+#    #+#             */
/*   Updated: 2018/02/12 10:39:55 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	display(t_env *a)
{
	int i;

	i = 0;
	ft_putstr("pile a = ");
	while (i < a->size_a)
	{
		ft_putnbr_c(a->pile_a[i].nb, ' ');
		i++;
	}
	ft_putchar('\n');
	i = 0;
	ft_putstr("pile b = ");
	while (i < a->size_b)
	{
		ft_putnbr_c(a->pile_b[i].nb, ' ');
		i++;
	}
	ft_putchar('\n');
}

void	ft_free(t_env *a)
{
	free(a->pile_a);
	free(a->pile_b);
	free(a);
}

int		pile_is_sort(t_env *a)
{
	int i;

	i = 0;
	while (i < a->size_a)
	{
		if (a->pile_a[i].index == i)
			i++;
		else
			return (0);
	}
	return (1);
}

int		pos_zero(t_env *a)
{
	int i;

	i = 0;
	while (a->pile_a[i].index != 0)
		i++;
	return (i);
}

void	iter_to_zero(t_env *a)
{
	if (pos_zero(a) < a->size_a / 2)
		ft_push_b(a);
	else
	{
		ft_reverse_rotate_a(a);
		ft_push_b(a);
	}
	if (a->size_b > 1 && a->med && a->pile_b[0].index >= a->med)
		ft_rotate_b(a);
}
