/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 19:46:43 by mmatime           #+#    #+#             */
/*   Updated: 2018/02/12 19:46:44 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	print_ra(t_env *a)
{
	if (a->color && pile_is_sort(a) && a->size_b == 0)
	{
		ft_putstr(YEL);
		ft_putstr("ra\n");
	}
	else
		ft_putstr("ra\n");
}

void	print_rra(t_env *a)
{
	if (a->color && pile_is_sort(a) && a->size_b == 0)
	{
		ft_putstr(YEL);
		ft_putstr("rra\n");
	}
	else
		ft_putstr("rra\n");
}

void	raise_a_down_b(t_env *a)
{
	a->size_a++;
	a->size_b--;
}

void	raise_b_down_a(t_env *a)
{
	a->size_a--;
	a->size_b++;
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
