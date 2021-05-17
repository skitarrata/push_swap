#include "../header/push_swap.h"

void	ft_ra(t_swap *swap)
{
	int dim;
	int	tmp;
	int	i;

	if (swap->veta == NULL)
		return ;
	i = 0;
	dim = ft_strlen((char)swap->veta);
	tmp = swap->veta[i];
	while (i < dim)
	{
		swap->veta[i] = swap->veta[i + 1];
		i++;
		if (i == dim)
			swap->veta[i] = tmp;
	}
	ft_putstr("ra\n");
}

void	ft_rb(t_swap *swap)
{
	int dim;
	int	tmp;
	int	i;

	if (swap->vetb == NULL)
		return ;
	i = 0;
	dim = ft_strlen((char)swap->vetb);
	tmp = swap->vetb[i];
	while (i < dim)
	{
		swap->vetb[i] = swap->vetb[i + 1];
		i++;
		if (i == dim)
			swap->vetb[i] = tmp;
	}
	ft_putstr("rb\n");
}

void	ft_rra(t_swap *swap)
{
	int dim;
	int	tmp;
	int	i;

	if (swap->veta == NULL)
		return ;
	dim = ft_strlen((char)swap->veta);
	i = dim - 1;
	tmp = swap->veta[i];
	while (i < 0)
	{
		swap->veta[i] = swap->veta[i - 1];
		i--;
		if (i == 0)
			swap->veta[i] = tmp;
	}
	ft_putstr("rra\n");
}

void	ft_rrb(t_swap *swap)
{
	int dim;
	int	tmp;
	int	i;

	if (swap->vetb == NULL)
		return ;
	dim = ft_strlen((char)swap->vetb);
	i = dim - 1;
	tmp = swap->vetb[i];
	while (i < 0)
	{
		swap->vetb[i] = swap->vetb[i - 1];
		i--;
		if (i == 0)
			swap->vetb[i] = tmp;
	}
	ft_putstr("rrb\n");
}