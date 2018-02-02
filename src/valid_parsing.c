#include "struct.h"

int		valid_char(char nb, char nb_plus)
{
	if (ft_isdigit(nb) && !(nb_plus == '-'))
		return (1);
	else if (nb == '-' && ft_isdigit(nb_plus))
		return (1);
	else
		return (0);
}

int		ft_compare_one_tab(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]) == 0)
				return (0);
			else
				j++;
		}
		i++;
	}
	return (1);
}

int		ft_compare_tabs(char **tab_1, char **tab_2)
{
	int i;
	int j;

	i = 0;
	while (tab_1[i])
	{
		j = 0;
		while (tab_2[j])
		{
			if (ft_strcmp(tab_1[i], tab_2[j]) == 0)
				return (0);
			else
				j++;
		}
		i++;
	}
	return (1);
}

int		ft_test_duplicate(char **argv)
{
	int i;
	int j;
	char **tab_1;
	char **tab_2;

	i = 1;
	tab_1 = NULL;
	tab_2 = NULL;
	while (argv[i])
	{
		tab_1 = ft_strsplit(argv[i], ' ');
		if (ft_compare_one_tab(tab_1))
		{
			j = i + 1;
			while (argv[j])
			{
				tab_2 = ft_strsplit(argv[j], ' ');
				if (ft_compare_tabs(tab_1, tab_2))
					j++;
				else
					return (0);
				free_tab(tab_2);
			}
		}
		else
			return (0);
		i++;
		free_tab(tab_1);
	}
	return (1);
}


int		valid_tab(char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "") == 0)
			return (0);
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] == ' ' || argv[i][j] == '\t')
				j++;
			if (valid_char(argv[i][j], argv[i][j + 1]))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}