#include "struct.h"

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
			find_and_place_zero(a);
		}
		else
			ft_putstr_error("Error\n");
	}
	else
		return (0);
	return (0);
}
