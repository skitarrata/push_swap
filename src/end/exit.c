
#include "../header/push_swap.h"

void	ft_error(t_swap *swap, char *text)
{
	ft_putstr(text);
	ft_free_swap(swap);
	exit(0);
}
