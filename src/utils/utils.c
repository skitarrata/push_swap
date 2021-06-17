/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:53:43 by svalenti          #+#    #+#             */
/*   Updated: 2021/06/17 16:53:48 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_putstr(char *text)
{
	int i;

	i = -1;
	if (!text)
		exit(0);
	while (text[++i])
		write(1, &text[i], 1);
}

long	*ft_intjoin(t_swap *swap, long const *vet, int dim)
{
	long	*nvet;
	int		i;

	i = 0;
	dim += 1;
	nvet = (long *)ft_calloc(dim, sizeof(long));
	if (!nvet)
		ft_error(swap, MALLOC_FAIL);
	while (++i < dim)
		nvet[i] = vet[i - 1];
	return (nvet);
}

long	*ft_intremove(t_swap *swap, long const *vet, int dim)
{
	long	*nvet;
	int		i;

	i = -1;
	dim -= 1;
	nvet = (long *)ft_calloc(dim, sizeof(long));
	if (!nvet)
		ft_error(swap, MALLOC_FAIL);
	while (++i < dim)
		nvet[i] = vet[i + 1];
	return (nvet);
}
