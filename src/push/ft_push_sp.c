#include "../header/push_swap.h"

void	ft_sa(t_swap *swap)
{
	int	tmp;

	if (swap->veta == NULL)
		return ;
	tmp = swap->veta[0];
	swap->veta[0] = swap->veta[1];
	swap->veta[1] = tmp;
	ft_putstr("sa\n");
}

void	ft_sb(t_swap *swap)
{
	int	tmp;

	if (swap->vetb == NULL)
		return ;
	tmp = swap->vetb[0];
	swap->vetb[0] = swap->vetb[1];
	swap->vetb[1] = tmp;
	ft_putstr("sb\n");
}

void	ft_pa(t_swap *swap)
{
	int	tmp;

	if (swap->vetb == NULL)
		return ;
	tmp = swap->veta[0];
	swap->veta[0] = swap->vetb[0];
	swap->vetb[0] = tmp;
	ft_putstr("pa\n");
}

void	ft_pb(t_swap *swap)
{
	int	tmp;

	if (swap->veta == NULL)
		return ;
	tmp = swap->vetb[0];
	swap->vetb[0] = swap->veta[0];
	swap->veta[0] = tmp;
	ft_putstr("pa\n");
}