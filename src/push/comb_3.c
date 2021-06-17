#include "../header/push_swap.h"

int	ft_check_order(t_swap *swap, int b)
{
	int i;

	i = -1 + b;
	while (++i < swap->lena - 1)
		if (swap->veta[i] > swap->veta[i + 1])
			return (1);
	return (0);
}

static void	ft_comb_3(t_swap *swap)
{
	int i;

	i = swap->lena;
	if (swap->veta[0] > swap->veta[i - 1] && swap->veta[0] < swap->veta[1])
		ft_rra(swap);
	if (swap->veta[0] > swap->veta[i - 1] && swap->veta[0] > swap->veta[1] && i != 2)
		ft_ra(swap);
	if (swap->veta[0] > swap->veta[1])
		ft_sa(swap);
	else if (swap->veta[0] < swap->veta[1] && swap->veta[0] < swap->veta[i - 1]
		&& ft_check_order(swap, 0))
	{
		ft_sa(swap);
		ft_ra(swap);
	}

}

static void ft_comb_5(t_swap *swap)
{
	int i;
	int dim;
	int cycle;

	cycle = 1;
	i = swap->lena;
	dim = i;
	while (cycle)
	{
		while (i > 3 && ft_check_order(swap, 1))
		{
			ft_pb(swap);
			i--;
		}
		ft_comb_3(swap);
		while (i < dim)
		{
			ft_pa(swap);
			ft_comb_3(swap);
			i++;
		}
		cycle = ft_check_order(swap, 0);
		if (cycle)
			ft_rra(swap);
	}
}

void	ft_which_combination(t_swap *swap)
{
	if (swap->lena <= 3)
		ft_comb_3(swap);
	else if (swap->lena > 3 && swap->lena <= 5)
		ft_comb_5(swap);
	else if (swap->lena > 5)
		ft_subsequence(swap);
}
