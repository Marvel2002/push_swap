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

typedef	struct  s_pile
{
	int nb;
	int index;
}				t_pile;

typedef	struct  s_env
{
	t_pile *pile_a;
	t_pile *pile_b;
	int 	size_a;
	int		size_b;
	int		size_max;
	int		med;
	int		push_swap;
	int		checker;
}				t_env;

typedef void	(t_func_instruc)(t_env *a);

t_env		*pile_init(char **argv);
void		pile_fill_a(t_env *a, char **argv);
int			ft_test_duplicate(char **argv);
void		ft_swap_a(t_env *a);
void		ft_swap_b(t_env *a);
void		ft_ss(t_env *a);
void		ft_rotate_a(t_env *a);
void		ft_rotate_b(t_env *a);
void		ft_rr(t_env *a);
void		ft_reverse_rotate_a(t_env *a);
void		ft_reverse_rotate_b(t_env *a);
void		ft_rrr(t_env *a);
void		ft_push_a(t_env *a);
void		ft_push_b(t_env *b);
void		free_tab(char **tab);
int			valid_tab(char **argv);
void		ft_putstr_error(char const *s);
void		display(t_env *a);
int			count_int_argv(char **argv);
void		find_and_place_zero(t_env *a);
int			pile_is_sort(t_env *a);

#endif
