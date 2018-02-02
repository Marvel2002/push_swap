#include "struct.h"

void		pile_init(t_env *a, char **argv)
{
	a->pile_max = count_int_argv(argv);
	a->pile_a = (int*)ft_memalloc(sizeof(int) * a->pile_max);
	a->pile_b = (int*)ft_memalloc(sizeof(int) * a->pile_max);
	a->size_a = a->pile_max;
	a->size_b = 0;
	a->push_on_a = 0;
	a->push_on_b = 0;
	a->sa = 0;
	a->sb = 0;
	a->ss = 0;
	a->pa = 0;
	a->pb = 0;
	a->ra = 0;
	a->rb = 0;
	a->rr = 0;
	a->rra = 0;
	a->rrb = 0;
	a->rrr = 0;
}

void	calcule_rotation_mid_b(int nb, t_env *a)
{
	int i;
	int index_mid;

	i = a->size_b - 1;
	index_mid = 0;
	while (i > 0)
	{
		if (nb > a->pile_b[i] && nb < a->pile_b[i - 1])
			index_mid = i;
		i--;
	}
	if ((a->size_b - index_mid) > index_mid)
	{
		while (index_mid > 0)
		{
			ft_rotate_b(a);
			index_mid--;
		}
		ft_push_b(a);
	}
	else
	{
		while (index_mid < a->size_b)
		{
			ft_reverse_rotate_b(a);
			index_mid++;
		}
		ft_push_b(a);
	}
}

void	display_instruct(t_env *a)
{
	printf("sa = %d\n", a->sa);
	printf("sb = %d\n", a->sb);
	printf("ss = %d\n", a->ss);
	printf("pa = %d\n", a->pa);
	printf("pb = %d\n", a->pb);
	printf("ra = %d\n", a->ra);
	printf("rb = %d\n", a->rb);
	printf("rr = %d\n", a->rr);
	printf("rra = %d\n", a->rra);
	printf("rrb = %d\n", a->rrb);
	printf("rrr = %d\n", a->rrr);
	printf("TOTAL de %d instructions\n", a->sa + a->sb + a->ss + a->pa + a->pb + a->ra + a->rb + a->rr + a->rrr + a->rrb + a->rrr);
}

void	display(int *tab, int count, char c)
{
	int i;

	i = 0;
	ft_putstr("pile ");
	ft_putchar(c);
	ft_putstr("= ");
	while (i < count)
	{
		ft_putnbr(tab[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

void	ft_putstr_error(char const *s)
{
	if (!s)
		return ;
	while (*s)
	{
		write(0, &*s, 1);
		s++;
	}
}