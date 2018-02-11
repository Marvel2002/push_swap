#include "struct.h"

int		main(int argc, char **argv)
{
	t_env *a;
	char buf[4];

	a = NULL;
	if (argc > 1)
	{
		if (valid_tab(argv) && ft_test_duplicate(argv))
		{
			a = pile_init(argv);
			pile_fill_a(a, argv);
			while (read(0, buf, 3) == 3)
			{
				ft_putstr(buf);
			}
		}
		else
			ft_putstr_error("Error\n");
	}
	return (0);
}
