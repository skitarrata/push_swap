/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:24:02 by svalenti          #+#    #+#             */
/*   Updated: 2021/06/17 17:54:42 by svalenti         ###   ########.fr       */
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

static void	ft_print_mov(t_swap *swap)
{
	char	*str;

	str = ft_itoa(swap->mov);
	ft_putstr("	MOVE\n");
	ft_putstr("	");
	ft_putstr(str);
	ft_putstr("\n\n");
	free(str);
}

void	ft_print(t_swap *swap)
{
	int		i;
	char	*str1;
	char	*str2;	

	i = 0;
	ft_putstr("STACK A		STACK B\n");
	while (i < swap->lena || i < swap->lenb)
	{
		str1 = ft_itoa(swap->veta[i]);
		ft_putstr(str1);
		if (i < swap->lenb)
		{
			ft_putstr("		");
			str2 = ft_itoa(swap->vetb[i]);
			ft_putstr(str2);
			free(str2);
		}
		ft_putstr("\n");
		free(str1);
		i++;
	}
	ft_print_mov(swap);
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
	//swap->vetb = NULL;
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
	ft_check_double(swap);
	ft_check_int(swap);
	//ft_bubbleSort(swap);
}
