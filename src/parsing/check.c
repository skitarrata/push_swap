/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:23:15 by svalenti          #+#    #+#             */
/*   Updated: 2021/06/11 17:46:45 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header/push_swap.h"

void	ft_check_num(char *argv)
{
	int i;

	i = -1;
	while (argv[++i])
		if ((argv[i] < 48 || argv[i] > 57) && (argv[i] != ' ' && argv[i] != '-' && argv[i] != '+'))
			ft_error(BAD_PAR);
		if ((argv[i] >= 48 && argv[i] <= 57) && (argv[i + 1] == '-' || argv[i + 1] == '+'))
			ft_error(BAD_PAR);
}