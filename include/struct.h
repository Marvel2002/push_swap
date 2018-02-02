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
void	ft_rotate_b(t_env *a);
void	ft_reverse_rotate_a(t_env *a);
void	ft_reverse_rotate_b(t_env *a);
void	ft_push_a(t_env *a);
void	ft_push_b(t_env *a);
void	free_tab(char **tab);
int		valid_tab(char **argv);
void	pile_fill(t_env *a, char **argv);
void	display_instruct(t_env *a);
void	pile_init(t_env *a, char **argv);
void	sort_pile_a(t_env *a);
void	sort_pile_b(t_env *a);
void	ft_putstr_error(char const *s);
void	calcule_rotation_mid_b(int nb, t_env *a);
int		nb_is_max_a(int nb, t_env *a);
int		nb_is_max_b(int nb, t_env *a);
int		nb_is_min_b(int nb, t_env *a);
int		nb_is_min_a(int nb, t_env *a);
int		last_is_min(int nb, int index, t_env *a);
int		set_index_min_position_b(t_env *a);
int		set_index_max_position_b(t_env *a);
int		set_index_max_position_a(t_env *a);
int		set_index_min_position_a(t_env *a);
void	calcule_rotation_on_b(t_env *a);
void	display(int *tab, int count, char c);
int		count_int_argv(char **argv);

#endif
