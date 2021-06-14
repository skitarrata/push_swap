/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:24:13 by svalenti          #+#    #+#             */
/*   Updated: 2021/06/14 17:20:15 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int		main(int argc, char *argv[])
{
	t_swap	*swap;

	swap = (t_swap *)ft_calloc(1, sizeof(t_swap));
	if (!swap)
		ft_error(swap, MALLOC_FAIL);
	ft_parse_arg(swap, argc, argv);
	ft_init_vet(swap, argv);

	swap->vetb = ft_calloc(4, sizeof(long));
	swap->vetb[0] = 4;
	swap->vetb[1] = 5;
	swap->vetb[2] = 7;
	swap->vetb[3] = 1;
	swap->lenb = 4;

	if (swap->lena == 1)
	{
		ft_print(swap);
		ft_error(swap, END);
	}
	ft_ra(swap);
	ft_print(swap);
	ft_error(swap, END);
}
