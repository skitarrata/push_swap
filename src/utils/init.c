/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:24:02 by svalenti          #+#    #+#             */
/*   Updated: 2021/06/11 18:33:18 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	ft_word_counter(t_swap *swap, char *argv[])
{
	int	i;
	int	j;
	int	count;
	int	trigger;

	i = -1;
	count = 0;
	while (argv[++i])
	{
		j = -1;
		trigger = 0;
		while (argv[i][++j])
		{
			if (argv[i][j] == ' ')
				trigger = 0;
			else if (trigger == 0)
			{
				trigger = 1;
				count++;
			}
		}
	}
	swap->lena = count - 1;
}

void	ft_print(t_swap *swap)
{
	int i;

	i = -1;
	while (++i < swap->lena)
		printf("%ld\n", swap->veta[i]);
}

void	ft_init_vet(t_swap *swap, char *argv[])
{
	int i;
	int j;
	int k;
	int sign;

	i = 0;
	k = 0;
	sign = 1;
	swap->vetb = NULL;
	ft_word_counter(swap, argv);
	swap->veta = (long *)ft_calloc(swap->lena, sizeof(long));
	if (!(swap->veta))
		ft_error(swap, MALLOC_FAIL);
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] == '-')
				sign = -1;
			if (argv[i][j] >= 48 && argv[i][j] <= 57)
			{
				swap->veta[k] = ((swap->veta[k] * 10) + argv[i][j] - 48);
				if ((argv[i][j + 1] == ' ' || !argv[i][j + 1]))
				{
					swap->veta[k] *= sign;
					sign = 1;
					k++;
				}
			}
		}
	}
	ft_check_double(swap, argv);
	ft_check_int(swap, argv);
	ft_print(swap);
}
