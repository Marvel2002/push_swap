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

void	ft_swap_a(t_env *a)
{
	int nb;
	int nb_2;

	nb = 0;
	nb_2 = 0;
	if (a->size_a > 1)
	{
		nb = a->pile_a[0];
		nb_2 = a->pile_a[1];
		a->pile_a[0] = nb_2;
		a->pile_a[1] = nb;
	}
}

void	ft_swap_b(t_env *a)
{
	int nb;
	int nb_2;

	nb = 0;
	nb_2 = 0;
	if (a->size_b > 1)
	{
		nb = a->pile_b[0];
		nb_2 = a->pile_b[1];
		a->pile_b[0] = nb_2;
		a->pile_b[1] = nb;
	}
}

void	ft_ss(t_env *a)
{
	ft_swap_a(a);
	ft_swap_b(a);
}

void	ft_rotate_a(t_env *a)
{
	int i;
	int last;

	i = 0;
	last = a->pile_a[i];
	while (i < a->size_a - 1)
	{
		a->pile_a[i] = a->pile_a[i + 1];
		i++;
	}
	a->pile_a[i] = last;
}

void	ft_rotate_b(t_env *a)
{
	int i;
	int last;

	i = 0;
	last = a->pile_b[i];
	while (i < a->size_b - 1)
	{
		a->pile_b[i] = a->pile_b[i + 1];
		i++;
	}
	a->pile_b[i] = last;
}

void	ft_rr(t_env *a)
{
	ft_rotate_a(a);
	ft_rotate_b(a);
}

void	ft_reverse_rotate_a(t_env *a)
{
	int i;
	int first;

	i = a->size_a - 1;
	first = a->pile_a[i];
	while (i > 0)
	{
		a->pile_a[i] = a->pile_a[i - 1];
		i--;
	}
	a->pile_a[i] = first;
}

void	ft_reverse_rotate_b(t_env *a)
{
	int i;
	int first;

	i = a->size_b - 1;
	first = a->pile_b[i];
	while (i > 0)
	{
		a->pile_b[i] = a->pile_b[i - 1];
		i--;
	}
	a->pile_b[i] = first;
}

void	ft_rrr(t_env *a)
{
	ft_reverse_rotate_a(a);
	ft_reverse_rotate_b(a);
}

void	ft_push_a(t_env *a)
{
	int i;

	i = a->size_a;
	ft_putstr("size_b = ");
	ft_putnbr(a->size_b);
	ft_putchar('\n');
	ft_putstr("size_a = ");
	ft_putnbr(a->size_a);
	ft_putchar('\n'); 
	if (a->size_b)
	{
		while (i > 0)
		{
			a->pile_a[i] = a->pile_a[i - 1];
			i--;
		}
		a->pile_a[0] = a->pile_b[0];
		a->size_b--;
		a->size_a++;
		i = 0;
		while (i < a->size_b)
		{
			a->pile_b[i] = a->pile_b[i + 1];
			i++;
		}
	}
}

void	ft_push_b(t_env *a)
{
	int i;

	i = a->size_b;
	ft_putstr("size_a = ");
	ft_putnbr(a->size_a);
	ft_putchar('\n');
	ft_putstr("size_b = ");
	ft_putnbr(a->size_b);
	ft_putchar('\n');
	if (a->size_a)
	{
		while (i > 0)
		{
			a->pile_b[i] = a->pile_b[i - 1];
			i--;
		}
		a->pile_b[0] = a->pile_a[0];
		a->size_a--;
		a->size_b++;
		i = 0;
		while (i < a->size_a)
		{
			a->pile_a[i] = a->pile_a[i + 1];
			i++;
		}
	}
}