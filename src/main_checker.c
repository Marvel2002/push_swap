/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 10:39:37 by mmatime           #+#    #+#             */
/*   Updated: 2018/02/12 10:39:41 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int		parse_instruct(char *buf, t_env *a)
{
	int						index;
	const static char		*instruction[] = {"sa", "sb", "ra", "rb",
	"rra", "rrb", "pa", "pb", "ss", "rr", "rrr", NULL};
	static t_func_instruc			*func_exec[] = {
		&ft_swap_a, &ft_swap_b, &ft_rotate_a, &ft_rotate_b, &ft_reverse_rotate_a,
		&ft_reverse_rotate_b, &ft_push_a, &ft_push_b, &ft_ss, &ft_rr, &ft_rrr,
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

void	read_stdin(t_env *a)
{
	char *buf = NULL;

	while (get_next_line(0, &buf) > 0)
	{
		if (!parse_instruct(buf, a))
		{
			ft_putstr_error("Error\n");
			ft_free(a);
			exit(1);
		}
	}
	if (pile_is_sort(a) && a->size_b == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}
	

int		main(int argc, char **argv)
{
	t_env *a;
	int	bonus;

	a = NULL;
	bonus = 0;
	if (argc > 1)
	{
		if ((ft_strcmp(argv[1], "-v")) == 0)
			bonus = 1;
		else if ((ft_strcmp(argv[1], "-c")) == 0)
			bonus = 2;
		if (valid_tab(argv, bonus) && ft_test_duplicate(argv, bonus))
		{
			a = pile_init(argv, bonus);
			pile_fill_a(a, argv);
			read_stdin(a);
			ft_free(a);
		}
		else
			ft_putstr_error("Error\n");
	}
	return (0);
}
