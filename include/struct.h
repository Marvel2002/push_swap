/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:11:01 by mmatime           #+#    #+#             */
/*   Updated: 2018/01/23 15:00:36 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H

#define STRUCT_H

#include "../libft/libft.h"
#include <stdio.h>

typedef struct	s_env
{
	int		*pile_a;
	int		*pile_b;
	int		size_a;
	int		size_b;
	int		pile_max;
	int		push_on_a;
	int		push_on_b;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}				t_env;

int		ft_test_duplicate(char **argv);
void	ft_swap_a(t_env *a);
void	ft_swap_b(t_env *a);
void	ft_ss(t_env *a);
void	ft_rr(t_env *a);
void	ft_rrr(t_env *a);
void	ft_rotate_a(t_env *a);
void	ft_reverse_rotate_a(t_env *a);
void	ft_push_a(t_env *a);
void	ft_push_b(t_env *a);
void	free_tab(char **tab);

#endif
