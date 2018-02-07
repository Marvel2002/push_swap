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

typedef	struct  s_pile_a
{
	int nb;
	int index;
}				t_pile_a;

typedef	struct  s_pile_b
{
	int nb;
	int index;
}				t_pile_b;

t_pile_a	*pile_init_a(char **argv);
t_pile_b	*pile_init_b(char **argv);
void		pile_fill_a(t_pile_a *a, char **argv);
void		pile_fill_b(t_pile_b *b, char **argv);
int			ft_test_duplicate(char **argv);
void		ft_swap_a(t_pile_a *a);
void		ft_swap_b(t_pile_b *b);
void		ft_ss(t_pile_a *a, t_pile_b *b);
void		ft_rr(t_pile_a *a, t_pile_b *b);
void		ft_rrr(t_pile_a *a, t_pile_b *b);
void		ft_rotate_a(t_pile_a *a);
void		ft_rotate_b(t_pile_b *b);
void		ft_reverse_rotate_a(t_pile_a *a);
void		ft_reverse_rotate_b(t_pile_b *b);
void		ft_push_a(t_pile_a *a);
void		ft_push_b(t_pile_b *b);
void		free_tab(char **tab);
int			valid_tab(char **argv);
void		ft_putstr_error(char const *s);
int			count_int_argv(char **argv);

#endif
