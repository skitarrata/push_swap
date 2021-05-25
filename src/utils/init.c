#include "../header/push_swap.h"

static int		ft_conversion_num(char *argv)
{
	int i;
	int res;

	i = -1;
	res = 0;
	while (argv[++i])
		res = (res * 10) + argv[i] - 48;
	return (res);
}

void	ft_init_vet(t_swap *swap, int argc, char *argv[])
{
	int i;

	i = 0;
	swap->vetb = NULL;
	swap->veta = ft_calloc(argc - 1, sizeof(int));
	if (!(swap->veta))
		ft_error(MALLOC_FAIL);
	while (++i < argc - 1)
		swap->veta[i - 1] = ft_conversion_num(argv[i]);
}