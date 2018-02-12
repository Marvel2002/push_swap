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
		ft_putstr("sa\n");
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
		ft_putstr("ra\n");
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

void	ft_rr(t_env *a)
{
	ft_rotate_a(a);
	ft_rotate_b(a);
	if (a->push_swap)
		ft_putstr("rr\n");
	if (a->display)
		display(a);
}

void	ft_reverse_rotate_a(t_env *a)
{
	int i;
	int nb_tmp;
	int index_tmp;

	i = a->size_a - 1;
	nb_tmp = a->pile_a[i].nb;
	index_tmp = a->pile_a[i].index;
	while (i > 0)
	{
		a->pile_a[i].nb = a->pile_a[i - 1].nb;
		a->pile_a[i].index = a->pile_a[i - 1].index;
		i--;
	}
	a->pile_a[i].nb = nb_tmp;
	a->pile_a[i].index = index_tmp;
	if (a->push_swap)
		ft_putstr("rra\n");
	if (a->display)
		display(a);
}

void	ft_reverse_rotate_b(t_env *a)
{
	int i;
	int nb_tmp;
	int index_tmp;

	if (a->size_b > 1)
	{
		i = a->size_b - 1;
		nb_tmp = a->pile_b[i].nb;
		index_tmp = a->pile_b[i].index;
		while (i > 0)
		{
			a->pile_b[i].nb = a->pile_b[i - 1].nb;
			a->pile_b[i].index = a->pile_b[i - 1].index;
			i--;
		}
		a->pile_b[i].nb = nb_tmp;
		a->pile_b[i].index = index_tmp;
	}
	if (a->push_swap)
		ft_putstr("rrb\n");
}

void	ft_rrr(t_env *a)
{
	ft_reverse_rotate_a(a);
	ft_reverse_rotate_b(a);
	if (a->push_swap)
		ft_putstr("rrr\n");
	if (a->display)
		display(a);
}

void	ft_push_a(t_env *a)
{
	int i;

	if (a->size_b)
	{
		i = a->size_a;
		while (i > 0)
		{
			a->pile_a[i].nb = a->pile_a[i - 1].nb;
			a->pile_a[i].index = a->pile_a[i - 1].index;
			i--;
		}
		a->pile_a[i].nb = a->pile_b[0].nb;
		a->pile_a[i].index = a->pile_b[0].index;
		a->size_a++;
		a->size_b--;
		while (i < a->size_b)
		{
			a->pile_b[i].nb = a->pile_b[i + 1].nb;
			a->pile_b[i].index = a->pile_b[i + 1].index;
			i++;
		}
	}
	if (a->push_swap)
		ft_putstr("pa\n");
	if (a->display)
		display(a);
}

void	ft_push_b(t_env *a)
{
	int i;

	if (a->size_a)
	{
		i = a->size_b;
		while (i > 0)
		{
			a->pile_b[i].nb = a->pile_b[i - 1].nb;
			a->pile_b[i].index = a->pile_b[i - 1].index;
			i--;
		}
		a->pile_b[i].nb = a->pile_a[0].nb;
		a->pile_b[i].index = a->pile_a[0].index;
		a->size_a--;
		a->size_b++;
		while (i < a->size_a)
		{
			a->pile_a[i].nb = a->pile_a[i + 1].nb;
			a->pile_a[i].index = a->pile_a[i + 1].index;
			i++;
		}
	}
	if (a->push_swap)
		ft_putstr("pb\n");
	if (a->display)
		display(a);
}
