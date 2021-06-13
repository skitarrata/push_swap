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

void	ft_check_num(t_swap *swap, char *argv)
{
	int i;

	i = -1;
	while (argv[++i])
	{
		if ((argv[i] < 48 || argv[i] > 57) && (argv[i] != ' ' && argv[i] != '-' && argv[i] != '+'))
			ft_error(swap, BAD_PAR);
		if ((argv[i] == '-' || argv[i] == '+') && (argv[i + 1] == ' ' || !argv[i + 1]))
			ft_error(swap, BAD_PAR);
		if ((argv[i] >= 48 && argv[i] <= 57) && (argv[i + 1] == '-' || argv[i + 1] == '+'))
			ft_error(swap, BAD_PAR);
	}
}

void	ft_check_double(t_swap *swap, char *argv[])
{
	int	i;
	int	j;
	int len;

	i = -1;
	while (++i <= swap->lena)
	{
		j = i;
		while (++j <= swap->lena)
			if (swap->veta[i] == swap->veta[j])
				ft_error(swap, DOU_PAR);
	}
}

void	ft_check_int(t_swap *swap, char *argv[])
{
	int i;
	int len;

	i = -1;
	while (++i < swap->lena)
	{
		if (swap->veta[i] > 2147483647)
			ft_error(swap, OVER);
		else if (swap->veta[i] < -2147483648)
			ft_error(swap, OVER);
	}
}
