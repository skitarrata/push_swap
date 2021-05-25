#include "../header/push_swap.h"

void	ft_parse_arg(int argc, char *argv[])
{
	int i;

	i = 0;
	if (argc >= 2)
		while (argv[++i])
			ft_check_num(argv[i]);
	else
		ft_error(PAR);
}