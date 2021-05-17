#include "../header/push_swap.h"

void	ft_ss(t_swap *swap)
{
	ft_sa(swap);
	ft_sb(swap);
	ft_putstr("ss\n");
}

void	ft_rr(t_swap *swap)
{
	ft_ra(swap);
	ft_rb(swap);
	ft_putstr("rr\n");
}

void	ft_rrr(t_swap *swap)
{
	ft_rra(swap);
	ft_rrb(swap);
	ft_putstr("rrr\n");
}