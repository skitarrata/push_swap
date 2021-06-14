#include "../header/push_swap.h"

void	ft_sa(t_swap *swap)
{
	int	tmp;

	if (!swap->veta)
		ft_error(swap, NOT_VETA);
	tmp = swap->veta[0];
	swap->veta[0] = swap->veta[1];
	swap->veta[1] = tmp;
	ft_putstr("sa\n");
}

void	ft_sb(t_swap *swap)
{
	int	tmp;

	if (!swap->vetb)
		ft_error(swap, NOT_VETB) ;
	tmp = swap->vetb[0];
	swap->vetb[0] = swap->vetb[1];
	swap->vetb[1] = tmp;
	ft_putstr("sb\n");
}

void	ft_pa(t_swap *swap)
{
	if (!swap->vetb)
		return ;
	swap->veta = ft_intjoin(swap, swap->veta, swap->lena);
	swap->lena += 1;
	swap->veta[0] = swap->vetb[0];
	swap->vetb = ft_intremove(swap, swap->vetb, swap->lenb);
	if (swap->lenb == 1)
		free(swap->vetb);
	swap->lenb -= 1;
	ft_putstr("pa\n");
}

void	ft_pb(t_swap *swap)
{
	int	tmp;

	if (!swap->veta || swap->vetb)
		ft_error(swap, NOT_VET);
	tmp = swap->vetb[0];
	swap->vetb[0] = swap->veta[0];
	swap->veta[0] = tmp;
	ft_putstr("pa\n");
}