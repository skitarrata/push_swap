/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsequence.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:44:38 by svalenti          #+#    #+#             */
/*   Updated: 2021/06/17 19:13:53 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	ft_lensub(t_swap *swap)
{
	int i;

	i = -1;
	swap->lsub = 1;
	while (++i < swap->lena - 1)
		if (swap->subv[i] < swap->subv[i + 1])
			swap->lsub = swap->subv[i + 1];
}

static void	ft_index_sub(t_swap *swap)
{
	int i;
	int count;

	ft_lensub(swap);
	swap->index = (long *)ft_calloc(swap->lsub, sizeof(long));
	if (!swap->index)
		ft_error(swap, MALLOC_FAIL);
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
}

void	ft_subsequence(t_swap *swap)
{
	int i;
	int j;

	swap->subv = (long *)ft_calloc(swap->lena, sizeof(long));
	if (!swap->subv)
		ft_error(swap, MALLOC_FAIL);
	i = 0;
	swap->subv[i] = 1;
	while (i < swap->lena)
	{
		j = -1;
		while (++j < i)
		{
			if (swap->veta[j] < swap->veta[i])
			{
				if (swap->subv[i] < swap->subv[j] + 1)
					swap->subv[i] = swap->subv[j] + 1;
			}
			else if (swap->veta[j] > swap->veta[i] && !swap->subv[i])
				swap->subv[i] = 1;
		}
		i++;
	}
	ft_index_sub(swap);
/* 	i = -1;
	while (++i < swap->lsub)
		printf("%ld\n", swap->veta[swap->index[i]]); */
}