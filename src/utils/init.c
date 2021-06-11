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

static int	ft_word_counter(char *argv[])
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
	return (count - 1);
}

/* static void		ft_conversion_num(t_swap *swap, char *argv)
{
	int i;
	int res;
	int sign;

	i = -1;
	res = 0;
	sign = 0;
	while (argv[++i])
	{
		while (argv[i] >= 48 && argv[i] <= 57)
			swap->veta[i - 1] = (swap->veta[i - 1] * 10) + argv[i] - 48;
	}
	swap->veta[i - 1]
} */

void	ft_init_vet(t_swap *swap, char *argv[])
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	swap->vetb = NULL;
	swap->veta = ft_calloc(ft_word_counter(argv), sizeof(int));
	if (!(swap->veta))
		ft_error(MALLOC_FAIL);
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] >= 48 && argv[i][j] <= 57)
			{
				swap->veta[k] = (swap->veta[k] * 10) + argv[i][j] - 48;
				if ((argv[i][j + 1] == ' ' || !argv[i][j + 1]))
					k++;
			}
			j++;
		}
	}
}