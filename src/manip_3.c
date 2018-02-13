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
