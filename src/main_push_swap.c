#include "struct.h"

int		main(int argc, char **argv)
{
	t_env *a;

	a = NULL;
	if (argc > 1)
	{
		if ((a = (t_env*)malloc(sizeof(*a))) && valid_tab(argv) && ft_test_duplicate(argv))
		{
			ft_putstr("OK\n");
			pile_init(a, argv); 
			pile_fill(a, argv);
			sort_pile_a(a);
		//	display_instruct(a);
		}
		else
			ft_putstr_error("Error\n");
	}
	else
		return (0);
	return (0);
}
