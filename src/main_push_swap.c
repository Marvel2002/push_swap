#include "struct.h"

int		main(int argc, char **argv)
{
	t_pile_a *a;
	t_pile_b *b;

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		if (valid_tab(argv) && ft_test_duplicate(argv))
		{
			ft_putstr("OK\n");
			a = pile_init_a(argv); 
			b = pile_init_b(argv); 
	//		sort_pile_a(a);
		//	display_instruct(a);
		}
		else
			ft_putstr_error("Error\n");
	}
	else
		return (0);
	return (0);
}
