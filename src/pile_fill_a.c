/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_fill_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 10:39:49 by mmatime           #+#    #+#             */
/*   Updated: 2018/02/12 10:39:50 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int			count_int_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void		free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int			count_int_argv(char **argv, int bonus)
{
	int		nb;
	char	**tab;
	int		i;

	nb = 0;
	i = (bonus) ? 2 : 1;
	tab = NULL;
	while (argv[i])
	{
		tab = ft_strsplit(argv[i], ' ');
		nb += count_int_tab(tab);
		free_tab(tab);
		i++;
	}
	return (nb);
}

int			parse_instruct(char *buf, t_env *a)
{
	int								index;
	const static char				*instruction[] = {"sa", "sb", "ra", "rb",
	"rra", "rrb", "pa", "pb", "ss", "rr", "rrr", NULL};
	static t_func_instruc			*func_exec[] = {
		&ft_swap_a, &ft_swap_b, &ft_rotate_a, &ft_rotate_b,
		&ft_reverse_rotate_a, &ft_reverse_rotate_b, &ft_push_a,
		&ft_push_b, &ft_ss, &ft_rr, &ft_rrr,
	};

	index = 0;
	while (instruction[index])
		if (ft_strcmp(instruction[index], buf) == 0)
		{
			func_exec[index](a);
			return (1);
		}
		else
			index++;
	return (0);
}

void		read_stdin(t_env *a)
{
	char *buf;

	buf = NULL;
	while (get_next_line(0, &buf) > 0)
	{
		if (!parse_instruct(buf, a))
		{
			write(2, "Error\n", 6);
			ft_free(a);
			free(buf);
			exit(1);
		}
		free(buf);
	}
	if (pile_is_sort(a) && a->size_b == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}
