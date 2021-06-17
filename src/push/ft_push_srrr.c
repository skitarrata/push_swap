/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_srrr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:54:53 by svalenti          #+#    #+#             */
/*   Updated: 2021/06/17 17:37:34 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_ss(t_swap *swap)
{
	ft_sa(swap);
	ft_sb(swap);
	ft_putstr("ss\n");
	swap->mov++;
	ft_print(swap);
}

void	ft_rr(t_swap *swap)
{
	ft_ra(swap);
	ft_rb(swap);
	ft_putstr("rr\n");
	swap->mov++;
	ft_print(swap);
}

void	ft_rrr(t_swap *swap)
{
	ft_rra(swap);
	ft_rrb(swap);
	ft_putstr("rrr\n");
	swap->mov++;
	ft_print(swap);
}
