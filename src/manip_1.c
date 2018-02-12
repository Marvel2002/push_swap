/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:28:45 by mmatime           #+#    #+#             */
/*   Updated: 2018/02/12 10:39:47 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	ft_swap_a(t_env *a)
{
	int nb_tmp;
	int index_tmp;

	if (a->size_a > 1)
	{
		nb_tmp = a->pile_a[0].nb;
		index_tmp = a->pile_a[0].index;
		a->pile_a[0].nb = a->pile_a[1].nb;
		a->pile_a[0].index = a->pile_a[1].index;
		a->pile_a[1].nb = nb_tmp;
		a->pile_a[1].index = index_tmp;
	}
	if (a->push_swap)
	{
		if (a->color && pile_is_sort(a) && a->size_b == 0)
		{
			ft_putstr(YEL);
			ft_putstr("sa\n");
		}
		else
			ft_putstr("sa\n");
	}
	if (a->display)
		display(a);
}

void	ft_swap_b(t_env *a)
{
	int nb_tmp;
	int index_tmp;

	if (a->size_b > 1)
	{
		nb_tmp = a->pile_b[0].nb;
		index_tmp = a->pile_b[0].index;
		a->pile_b[0].nb = a->pile_b[1].nb;
		a->pile_b[0].index = a->pile_b[1].index;
		a->pile_b[1].nb = nb_tmp;
		a->pile_b[1].index = index_tmp;
	}
	if (a->push_swap)
		ft_putstr("sb\n");
	if (a->display)
		display(a);
}

void	ft_ss(t_env *a)
{
	ft_swap_a(a);
	ft_swap_b(a);
	if (a->push_swap)
		ft_putstr("ss\n");
	if (a->display)
		display(a);
}

void	ft_rotate_a(t_env *a)
{
	int i;
	int nb_tmp;
	int index_tmp;

	i = 0;
	nb_tmp = a->pile_a[0].nb;
	index_tmp = a->pile_a[0].index;
	while (i < a->size_a - 1)
	{
		a->pile_a[i].nb = a->pile_a[i + 1].nb;
		a->pile_a[i].index = a->pile_a[i + 1].index;
		i++;
	}
	a->pile_a[i].nb = nb_tmp;
	a->pile_a[i].index = index_tmp;
	if (a->push_swap)
		print_ra(a);
	if (a->display)
		display(a);
}

void	ft_rotate_b(t_env *a)
{
	int i;
	int nb_tmp;
	int index_tmp;

	i = 0;
	nb_tmp = a->pile_b[0].nb;
	index_tmp = a->pile_b[0].index;
	while (i < a->size_b - 1)
	{
		a->pile_b[i].nb = a->pile_b[i + 1].nb;
		a->pile_b[i].index = a->pile_b[i + 1].index;
		i++;
	}
	a->pile_b[i].nb = nb_tmp;
	a->pile_b[i].index = index_tmp;
	if (a->push_swap)
		ft_putstr("rb\n");
	if (a->display)
		display(a);
}
