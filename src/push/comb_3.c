/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:47:45 by svalenti          #+#    #+#             */
/*   Updated: 2021/06/17 19:23:10 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	ft_comb_3(t_swap *swap)
{
	int i;

	i = swap->lena;
	if (swap->veta[0] > swap->veta[i - 1] && swap->veta[0] < swap->veta[1])
		ft_rra(swap);
	if (swap->veta[0] > swap->veta[i - 1] && swap->veta[0] > swap->veta[1] && i != 2)
		ft_ra(swap);
	if (swap->veta[0] > swap->veta[1])
		ft_sa(swap);
	else if (swap->veta[0] < swap->veta[1] && swap->veta[0] < swap->veta[i - 1]
		&& ft_check_order(swap, 0))
	{
		ft_sa(swap);
		ft_ra(swap);
	}

}

static void ft_comb_5(t_swap *swap)
{
	int i;
	int dim;
	int cycle;

	cycle = 1;
	i = swap->lena;
	dim = i;
	while (cycle)
	{
		ft_comb_3(swap);
		while (i > 3 && ft_check_order(swap, 1))
		{
			ft_pb(swap);
			i--;
		}
		ft_comb_3(swap);
		while (i < dim)
		{
			ft_pa(swap);
			ft_comb_3(swap);
			i++;
		}
		cycle = ft_check_order(swap, 0);
		if (cycle)
			ft_rra(swap);
	}
}

/* static void ft_comb(t_swap *swap)
{
	int cycle;

	cycle = 1;
	while (cycle)
	{
		ft_comb_3(swap);
		cycle = ft_check_order(swap, 0);
	}
} */

void	ft_which_combination(t_swap *swap)
{
	if (swap->lena <= 3)
		ft_comb_3(swap);
	else if (swap->lena > 3 && swap->lena <= 5)
		ft_comb_5(swap);
	else if (swap->lena > 5)
		ft_subsequence(swap);
}
