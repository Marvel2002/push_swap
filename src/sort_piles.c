/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_piles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 10:39:51 by mmatime           #+#    #+#             */
/*   Updated: 2018/02/12 10:39:53 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int		next_is_in_b(t_env *a)
{
	int i;

	i = 0;
	while (i < a->size_b)
	{
		if (a->pile_b[i].index == a->next)
			return (1);
		i++;
	}
	return (0);
}

void	move_in_b(t_env *a)
{
	if (a->pile_b[0].index == a->next)
	{
		ft_push_a(a);
		ft_rotate_a(a);
		a->next++;
		a->med++;
	}
	else if (a->pile_b[a->size_b - 1].index == a->next)
	{
		ft_reverse_rotate_b(a);
		ft_push_a(a);
		ft_rotate_a(a);
		a->next++;
		a->med++;
	}
	else
	{
		if (a->size_b > 1 && a->med && a->pile_b[0].index >= a->med)
			ft_rotate_b(a);
		else
			ft_push_a(a);
	}
}

void	move_in_a(t_env *a)
{
	if (a->pile_a[0].index == a->next)
	{
		ft_rotate_a(a);
		a->next++;
		a->med++;
	}
	else if (a->pile_a[1].index == a->next)
	{
		ft_swap_a(a);
		ft_rotate_a(a);
		a->next++;
		a->med++;
	}
	else
	{
		ft_push_b(a);
		if (a->size_b > 1 && a->med && a->pile_b[0].index >= a->med)
			ft_rotate_b(a);
	}
}

void	find_and_place_next(t_env *a)
{
	a->next = 1;
	while (a->pile_a[0].index != 0 || a->size_b)
	{
		if (next_is_in_b(a))
			move_in_b(a);
		else
			move_in_a(a);
	}
}

void	find_and_place_zero(t_env *a)
{
	if (!pile_is_sort(a))
	{
		while (a->pile_a[a->size_a - 1].index != 0)
		{
			if (a->pile_a[1].index == 0)
			{
				ft_swap_a(a);
				ft_rotate_a(a);
			}
			else if (a->pile_a[0].index == 0)
				ft_rotate_a(a);
			else if (a->pile_a[a->size_a - 2].index == 0)
				ft_reverse_rotate_a(a);
			else
				iter_to_zero(a);
		}
	}
	find_and_place_next(a);
}
