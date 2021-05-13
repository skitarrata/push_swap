/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:07:26 by plpelleg          #+#    #+#             */
/*   Updated: 2021/04/30 19:14:45 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

/*
Used for exiting the program, showing custom error messages(defined in error.h)
Calls free functions for each structure and for the 'all' structure.
*/

void	ft_error(char *text, t_all *all)
{
	if (ft_strncmp(END, text, 7))
		printf("Error\n%s", text);
	else
		printf("%s", text);
	ft_free(all);
//	ft_free_info(all);
//	ft_clear_texture(all);
//	ft_free_mlx(all);
//	ft_free_coord(all);
	free(all);
	exit(0);
}
