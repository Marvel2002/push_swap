/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:28:45 by mmatime           #+#    #+#             */
/*   Updated: 2018/01/23 16:28:56 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	ft_swap_a(t_pile_a *a)
{
	int nb_tmp;
	int index_tmp;

	if (a[0].index != -1 && a[1].index != -1)
	{
		nb_tmp = a[0].nb;
		index_tmp = a[0].index;
		a[0].nb = a[1].nb;
		a[0].index = a[1].index;
		a[1].nb = nb_tmp;
		a[1].index = index_tmp;
	}
	ft_putstr("sa\n");
}

void	ft_swap_b(t_pile_b *b)
{
	int nb_tmp;
	int index_tmp;

	if (b[0].index != -1 && b[1].index != -1)
	{
		nb_tmp = b[0].nb;
		index_tmp = b[0].index;
		b[0].nb = b[1].nb;
		b[0].index = b[1].index;
		b[1].nb = nb_tmp;
		b[1].index = index_tmp;
	}
	ft_putstr("sb\n");
}
/*
void	ft_ss(t_struct *b)
{
	ft_putstr("ss\n");
}

void	ft_rotate_a(t_struct *b)
{
	ft_putstr("ra\n");
}

void	ft_rotate_b(t_struct *b)
{
	ft_putstr("rb\n");
}

void	ft_rr(t_struct *b)
{
	ft_putstr("rr\n");
}

void	ft_reverse_rotate_a(t_struct *b)
{
	ft_putstr("rra\n");
}

void	ft_reverse_rotate_b(t_struct *b)
{
	ft_putstr("rrb\n");
}

void	ft_rrr(t_struct *b)
{
	ft_putstr("rrr\n");
}

void	ft_push_a(t_struct *b)
{
	ft_putstr("pa\n");
}

void	ft_push_b(t_struct *b)
{
	ft_putstr("pb\n");
}*/