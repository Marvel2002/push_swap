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

int		main(int argc, char **argv)
{
	t_env	*a;
	int		bonus;

	a = NULL;
	bonus = 0;
	if (argc > 1)
	{
		if ((ft_strcmp(argv[1], "-v")) == 0)
			bonus = 1;
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
