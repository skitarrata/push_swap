
#include "../header/push_swap.h"

long	ft_find_max(t_swap *swap)
{
	long	max;
	int i;

	i = 0;
	max = swap->vetb[0];
	while (++i < swap->lenb)
		if (swap->vetb[i] > max)
			max = swap->vetb[i];
	return (max);
}

long	ft_find_max_a(t_swap *swap)
{
	long	max;
	int	i;

	i = 0;
	max = swap->veta[0];
	while (++i < swap->lena)
		if (swap->veta[i] > max)
			max = swap->veta[i];
	return (max);
}

long	ft_find_min(t_swap *swap)
{
	long	min;
	int i;

	i = 0;
	min = swap->veta[0];
	while (++i < swap->lena)
		if (swap->veta[i] < min)
			min = swap->veta[i];
	return (min);
}

static void	ft_pass_min_zero_pos(t_swap *swap)
{
	long min;

	min = ft_find_min(swap);
	while (swap->veta[0] > min)
	{
		if (min == swap->veta[1])
			ft_sa(swap, 0);
		else if (min == swap->veta[swap->lena - 1])
			ft_rra(swap, 0);
		else
			ft_ra(swap, 0);
	}
}

void	ft_check(t_swap *swap)
{
	while (swap->lena > 3)
	{
		ft_pass_min_zero_pos(swap);
		ft_pb(swap);
	}
	ft_sort_three(swap);
	while (swap->lenb > 0)
		ft_pa(swap);
	ft_error(swap, END);
}