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
		if (swap->vet[i] < swap->vet[i + 1])
			swap->lsub = swap->vet[i + 1];
}

static void	ft_subvector(t_swap *swap)
{
	int i;

	swap->subv = (long *)ft_calloc(swap->lsub, sizeof(long));
	if (!swap->subv)
		ft_error(swap, MALLOC_FAIL);
	i = -1;
	while (++i < swap->lsub)
		swap->subv[i] = swap->veta[swap->index[i]];
	free(swap->index);
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
		if (swap->vet[i] == count)
		{
			count--;
			swap->index[count] = i;
		}
		i--;
	}
	ft_subvector(swap);
	free(swap->vet);
}

void	ft_subsequence(t_swap *swap)
{
	int i;
	int j;

	swap->vet = (long *)ft_calloc(swap->lena, sizeof(long));
	if (!swap->vet)
		ft_error(swap, MALLOC_FAIL);
	i = 0;
	swap->vet[i] = 1;
	while (i < swap->lena)
	{
		j = -1;
		while (++j < i)
		{
			if (swap->veta[j] < swap->veta[i])
			{
				if (swap->vet[i] < swap->vet[j] + 1)
					swap->vet[i] = swap->vet[j] + 1;
			}
			else if (swap->veta[j] > swap->veta[i] && !swap->vet[i])
				swap->vet[i] = 1;
		}
		i++;
	}
	ft_index_sub(swap);
	//free(swap->vet);
/* 	i = -1;
	while (++i < swap->lsub)
		printf("%ld\n", swap->veta[swap->index[i]]); */
}