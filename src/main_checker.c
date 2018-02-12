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
	const static char		*instruction[] = {"sa\n", "sb\n", "ra\n", "rb\n", "rra\n", "rrb\n", "pa\n", "pb\n", "ss\n", "rr\n", "rrr\n", NULL};
	int						index;
	t_func_instruc			*func_exec[] =
	{
	 	&ft_swap_a,
	 	&ft_swap_b,
	 	&ft_rotate_a,
	 	&ft_rotate_b,
	 	&ft_reverse_rotate_a,
	 	&ft_reverse_rotate_b,
	 	&ft_push_a,
	 	&ft_push_b,
	 	&ft_ss,
	 	&ft_rr,
	 	&ft_rrr,
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
	char buf[5];

	ft_bzero(buf, sizeof(buf));
	while (read(0, buf, sizeof(buf)) != -1)
	{
		if (parse_instruct(buf, a))
			ft_bzero(buf, sizeof(buf));
		else if (!parse_instruct(buf, a))
		{
			if (pile_is_sort(a) && a->size_b == 0)
			{
				ft_putstr("OK\n");
				break ;
			}
			else
			{
				ft_putstr("KO\n");
				break ;
			}
		}
	}
}

int		main(int argc, char **argv)
{
	t_env *a;

	a = NULL;
	if (argc > 1)
	{
		if (valid_tab(argv) && ft_test_duplicate(argv))
		{
			a = pile_init(argv);
			pile_fill_a(a, argv);
			read_stdin(a);
			ft_putstr("LOL");
		}
		else
			ft_putstr_error("Error\n");
	}
	return (0);
}
