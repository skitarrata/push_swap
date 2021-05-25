#include "../header/push_swap.h"

void	ft_check_num(char *argv)
{
	int i;

	i = -1;
	while (argv[++i])
		if (argv[i] < 48 || argv[i] > 57)
			ft_error(BAD_PAR);
}