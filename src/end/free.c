
#include "../header/push_swap.h"

void	ft_free_swap(t_swap *swap)
{
	if (swap->veta)
		free(swap->veta);
	if (swap->vetb)
		free(swap->vetb);
	if (swap)
		free(swap);
}