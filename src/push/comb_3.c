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

static void	ft_comb_a(t_swap *swap)
{
	int i;

	i = swap->lena;
	if (swap->veta[0] > swap->veta[i - 1] && swap->veta[0] < swap->veta[1])
		ft_rra(swap, 0);
	if (swap->veta[0] > swap->veta[i - 1] && swap->veta[0] > swap->veta[1] && i != 2)
		ft_ra(swap, 0);
	if (swap->veta[0] > swap->veta[1])
		ft_sa(swap, 0);
	else if (swap->veta[0] < swap->veta[1] && swap->veta[0] < swap->veta[i - 1]
		&& ft_check_three(swap->veta, i))
	{
		ft_sa(swap, 0);
		ft_ra(swap, 0);
	}

}

static void	ft_comb_b(t_swap *swap)
{
	int i;

	i = swap->lenb;
	if (i == 1 || !swap->lenb)
		return ;
	if (swap->vetb[0] < swap->vetb[i - 1] && swap->vetb[0] > swap->vetb[1])
		ft_rrb(swap, 0);
	if (swap->vetb[0] < swap->vetb[i - 1] && swap->vetb[0] < swap->vetb[1] && i != 2)
		ft_rb(swap, 0);
	if (swap->vetb[0] < swap->vetb[1])
		ft_sb(swap, 0);
	else if (swap->vetb[0] < swap->vetb[1] && swap->vetb[0] > swap->vetb[i - 1]
		&& !ft_check_three(swap->vetb, i))
	{
		ft_sb(swap, 0);
		ft_rb(swap, 0);
	}

}

static void	ft_comb(t_swap *swap)
{
	int i;
	int j;

	i = swap->lena;
	j = swap->lenb;
	if (j == 1 || !swap->lenb)
		return ;
	if (swap->veta[0] > swap->veta[i - 1] && swap->veta[0] < swap->veta[1]
		&& swap->vetb[0] < swap->vetb[j - 1] && swap->vetb[0] > swap->vetb[1])
		ft_rrr(swap);
	if (swap->veta[0] > swap->veta[i - 1] && swap->veta[0] > swap->veta[1]
		&& i != 2 && swap->vetb[0] < swap->vetb[j - 1]
		&& swap->vetb[0] < swap->vetb[1] && j != 2)
		ft_rr(swap);
	if (swap->veta[0] > swap->veta[1] && swap->vetb[0] < swap->vetb[1])
		ft_ss(swap);
/* 	else if (swap->vetb[0] < swap->vetb[1] && swap->vetb[0] > swap->vetb[j - 1]
		&& !ft_check_three(swap->vetb, j))
	{
		ft_sb(swap);
		ft_rb(swap);
	} */
}

static void ft_control_comb(t_swap *swap)
{
	ft_comb(swap);
	ft_comb_a(swap);
	ft_comb_b(swap);
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
		ft_control_comb(swap);
		while (i > 3 && ft_check_order(swap, 1))
		{
			ft_pb(swap);
			i--;
		}
		ft_control_comb(swap);
		while (i < dim)
		{
			ft_pa(swap);
			ft_control_comb(swap);
			i++;
		}
		cycle = ft_check_order(swap, 0);
		if (cycle)
			ft_rra(swap, 0);
	}
}

static void ft_sequence(t_swap *swap)
{
	int	i;
	int cycle;

	cycle = 1;
	while (cycle)
	{
		ft_control_comb(swap);
		ft_subsequence(swap);
		i = 0;
		while (i < swap->lsub)
		{
			if (swap->subv[i] == swap->veta[0])
			{
				ft_ra(swap, 0);
				i++;
			}
			else
				ft_pb(swap);
		}
		i = 0;
		ft_control_comb(swap);
		while (i < swap->lenb)
		{
			ft_pa(swap);
			ft_control_comb(swap);
			//i++;
		}
		free(swap->subv);
		cycle = ft_check_order(swap, 0);
	}
}

void	ft_which_combination(t_swap *swap)
{
	if (swap->lena <= 3)
		ft_comb_a(swap);
	else if (swap->lena >= 4)
		ft_sequence(swap);
}
