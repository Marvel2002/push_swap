#include "struct.h"

int		parse_instruct(char *buf)
{
	if (ft_strcmp("sa\n", buf) == 0)
		ft_putstr(buf);
	else if (ft_strcmp("sb\n", buf) == 0)
		ft_putstr(buf);
	else if (ft_strcmp("pa\n", buf) == 0)
		ft_putstr(buf);
	else if (ft_strcmp("pb\n", buf) == 0)
		ft_putstr(buf);
	else
		return (0);
	return (1);
}

void	read_stdin()
{
	char buf[5];

	ft_bzero(buf, sizeof(buf));
	while (read(0, buf, sizeof(buf)) != -1)
	{
		if (parse_instruct(buf))
			;
		else
			ft_putstr("MAUVAISE INSTRUCT\n");
		ft_bzero(buf, sizeof(buf));
		
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
