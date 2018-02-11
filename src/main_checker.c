#include "struct.h"

void	read_stdin()
{
	char buf[4];

	ft_bzero(buf, 4);
	while (read(0, buf, 4) != -1)
	{
		ft_putstr(buf);
		ft_bzero(buf, 4);
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
			read_stdin();
		}
		else
			ft_putstr_error("Error\n");
	}
	return (0);
}
