/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:54:40 by svalenti          #+#    #+#             */
/*   Updated: 2021/06/17 17:36:25 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_ra(t_swap *swap)
{
	int	tmp;
	int	i;

	if (!swap->veta)
		ft_error(swap, NOT_VETA);
	i = -1;
	tmp = swap->veta[0];
	while (++i < swap->lena - 1)
		swap->veta[i] = swap->veta[i + 1];
	swap->veta[i] = tmp;
	ft_putstr("ra\n");
	swap->mov++;
	ft_print(swap);
}

void	ft_rb(t_swap *swap)
{
	int	tmp;
	int	i;

	if (!swap->vetb)
		ft_error(swap, NOT_VETB);
	i = -1;
	tmp = swap->vetb[0];
	while (++i < swap->lenb - 1)
		swap->vetb[i] = swap->vetb[i + 1];
	swap->vetb[i] = tmp;
	ft_putstr("rb\n");
	swap->mov++;
	ft_print(swap);
}

void	ft_rra(t_swap *swap)
{
	int	tmp;
	int	i;

	if (!swap->veta)
		ft_error(swap, NOT_VETA);
	i = swap->lena;
	tmp = swap->veta[i - 1];
	while (--i > 0)
		swap->veta[i] = swap->veta[i - 1];
	swap->veta[i] = tmp;
	ft_putstr("rra\n");
	swap->mov++;
	ft_print(swap);
}

void	ft_rrb(t_swap *swap)
{
	int	tmp;
	int	i;

	if (!swap->vetb)
		ft_error(swap, NOT_VETB);
	i = swap->lenb;
	tmp = swap->vetb[i - 1];
	while (--i > 0)
		swap->vetb[i] = swap->vetb[i - 1];
	swap->vetb[i] = tmp;
	ft_putstr("rrb\n");
	swap->mov++;
	ft_print(swap);
}