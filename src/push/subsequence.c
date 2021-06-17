#include "../header/push_swap.h"

static int	ft_lensub(t_swap *swap)
{
	int i;
	int	res;

	i = 0;
	res = 1;
	swap->lsub = 1;
/* 	if (swap->lena == 1)
		return (swap->lsub); */
	while (++i < swap->lena)
	{
		res = ft_lensub(swap);
		if (swap->veta[i - 1] < swap->veta[swap->lena - 1] && res + 1 > swap->lsub)
			swap->lsub = res + 1;
	}
/* 	if (*max < swap->lsub)
		*max = swap->lsub; */
	return (swap->lsub);
}

void	ft_subsequence(t_swap *swap)
{
	int i;
	int j;
	int count;

	ft_lensub(swap);
	swap->subv = (long *)ft_calloc(swap->lena, sizeof(long));
	swap->index = (long *)ft_calloc(swap->lsub, sizeof(long));
	if (!swap->index || !swap->subv)
		ft_error(swap, MALLOC_FAIL);
	i = 0;
	swap->subv[i] = 1;
	while (i < swap->lena)
	{
		j = 0;
		while (j < i)
		{
			if (swap->veta[j] < swap->veta[i])
			{
				if (swap->subv[i] < swap->subv[j] + 1)
					swap->subv[i] = swap->subv[j] + 1;
			}
			else if (swap->veta[j] > swap->veta[i] && !swap->subv[i])
				swap->subv[i] = 1;
			j++;
		}
		i++;
	}
	i = swap->lena - 1;
	count = swap->lsub;
	while (count > 0)
	{
		if (swap->subv[i] == count)
		{
			count--;
			swap->index[count] = i;
		}
		i--;
	}
	i = -1;
	while (++i < swap->lsub)
		printf("%ld\n", swap->veta[swap->index[i]]);
}