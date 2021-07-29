/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:24:13 by svalenti          #+#    #+#             */
/*   Updated: 2021/06/17 17:34:14 by svalenti         ###   ########.fr       */
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
	swap->vetb = NULL;
	if (swap->lena == 1)
	{
		ft_print(swap);
		ft_error(swap, END);
	}
	ft_which_combination(swap);
	ft_error(swap, END);
}
