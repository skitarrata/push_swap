/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:24:13 by svalenti          #+#    #+#             */
/*   Updated: 2021/06/11 18:31:32 by svalenti         ###   ########.fr       */
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
	if (swap->lena == 1)
	{
		ft_print(swap);
		ft_error(swap, END);
	}
	ft_rra(swap);
	ft_print(swap);
	ft_error(swap, END);
}











/* 
#include <stdio.h>
#include <stdlib.h>

int		ft_subsequence(int arr[], int n, int *max)
{
	int i;
	int	res;
	int	max_end;

	i = 0;
	res = 1;
	max_end = 1;

	if (n == 1)
		return (max_end);
	while (++i < n)
	{
		res = ft_subsequence(arr, i, max);
		if (arr[i - 1] < arr[n - 1] && res + 1 > max_end)
			max_end = res + 1;
	}
	if (*max < max_end)
		*max = max_end;
	return (max_end);
}

void	ft_subvet(int arr[], int n, int max)
{
	int i;
	int j;
	int count;
	int vet[max];

	i = 0;
	j = 0;
	count = 0;
	vet[i] = arr[i];
	while (j < max - 1 && i < n - 1)
	{
		if (vet[j] < arr[i + 1])
		{
			vet[j + 1] = arr[i + 1];
			j++;
		}
		i++;
		if (i == n - 1 && j != max - 1)
		{
			j = 0;
			count++;
			i = count;
			vet[j] = arr[i];
		}
	}
	i = -1;
	while (++i < max)
		printf("%d\n", vet[i]);
}

int		ft_lis(int arr[], int n)
{
	int max;

	max = 1;
	ft_subsequence(arr, n, &max);
	ft_subvet(arr, n, max);
	return (max);
}

int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("vet of lis is %d\n", ft_lis(arr, n));
    return 0;
} */