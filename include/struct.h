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

# define STRUCT_H

# include "../libft/libft.h"
# define YEL   "\x1B[33m"

typedef	struct	s_te
{
	int		i;
	int		j;
	char	**tab_1;
	char	**tab_2;
}				t_te;

typedef	struct	s_pile
{
	int			nb;
	int			index;
}				t_pile;

typedef	struct	s_env
{
	t_pile		*pile_a;
	t_pile		*pile_b;
	int			size_a;
	int			size_b;
	int			size_max;
	int			med;
	int			push_swap;
	int			checker;
	int			next;
	int			i;
	int			color;
	int			display;
}				t_env;

typedef void	(t_func_instruc)(t_env *a);
int				parse_instruct(char *buf, t_env *a);
void			read_stdin(t_env *a);
t_env			*pile_init(char **argv, int bonus);
void			pile_fill_a(t_env *a, char **argv);
int				ft_test_duplicate(char **argv, int bonus);
void			ft_swap_a(t_env *a);
void			ft_swap_b(t_env *a);
void			ft_ss(t_env *a);
void			ft_rotate_a(t_env *a);
void			ft_rotate_b(t_env *a);
void			ft_rr(t_env *a);
void			ft_reverse_rotate_a(t_env *a);
void			ft_reverse_rotate_b(t_env *a);
void			ft_rrr(t_env *a);
void			ft_push_a(t_env *a);
void			ft_push_b(t_env *b);
void			free_tab(char **tab);
int				valid_tab(char **argv, int bonus);
void			ft_putstr_error(char const *s);
void			display(t_env *a);
int				count_int_argv(char **argv, int bonus);
void			find_and_place_zero(t_env *a);
int				pile_is_sort(t_env *a);
void			ft_free(t_env *a);
void			iter_to_zero(t_env *a);
void			print_rra(t_env *a);
void			raise_a_down_b(t_env *a);
void			raise_b_down_a(t_env *a);
int				count_int_tab(char **tab);
void			pile_fill_a_index(t_env *a);
t_env			*pile_init(char **argv, int bonus);
void			ft_putstr_error(char const *s);
int				next_is_in_b(t_env *a);
void			move_in_b(t_env *a);
void			move_in_a(t_env *a);
void			print_ra(t_env *a);
void			print_rra(t_env *a);
void			find_and_place_next(t_env *a);
void			ft_free(t_env *a);
int				pos_zero(t_env *a);
int				valid_char(char nb, char nb_plus);
int				ft_longtoi(const char *str);
int				ft_compare_one_tab(char **tab);
int				ft_compare_tabs(char **tab_1, char **tab_2);
int				ft_test_duplicate(char **argv, int bonus);

#endif
