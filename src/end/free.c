
#include "../header/push_swap.h"

/*
All following functions free, for each structure, the variables which have
been allocated.
*/

static void	ft_free_map(t_info *info)
{
	int		i;
	t_map	*map;

	map = info->map;
	i = 0;
	if (map->char_map)
	{
		while (info->map->char_map[i])
			free(info->map->char_map[i++]);
		free(info->map->char_map);
	}
	if (map->int_map)
		free(map->int_map);
	if (map->sprite)
	{
		i = 0;
		while (map->sprite[i])
			free(map->sprite[i++]);
		free(map->sprite);
	}
	if (map)
		free(map);
}

void	ft_free_info(t_all *all)
{
	int		i;
	t_info	*info;

	i = 0;
	info = all->info;
	if (info->NO)
		free(info->NO);
	if (info->SO)
		free(info->SO);
	if (info->WE)
		free(info->WE);
	if (info->EA)
		free(info->EA);
	if (info->S)
		free(info->S);
	ft_free_map(info);
	if (info)
		free(info);
}

static void	ft_free_mlx(t_all *all)
{
	t_mlx	*mlx;

	mlx = all->mlx;
	if (mlx->img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	if (mlx->win)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win);
		mlx_destroy_window(mlx->mlx_ptr, mlx->win);
	}
	else if (mlx->mlx_ptr)
		free(mlx->mlx_ptr);
	if (mlx)
		free(mlx);
}

static void	ft_clear_texture(t_all *all)
{
	if (all->walls)
	{
		if (all->walls->NO)
		{
			mlx_destroy_image(all->mlx->mlx_ptr, all->walls->NO->tex_ptr);
			free(all->walls->NO);
		}
		if (all->walls->SO)
		{
			mlx_destroy_image(all->mlx->mlx_ptr, all->walls->SO->tex_ptr);
			free(all->walls->SO);
		}
		if (all->walls->EA)
		{
			mlx_destroy_image(all->mlx->mlx_ptr, all->walls->EA->tex_ptr);
			free(all->walls->EA);
		}
		if (all->walls->WE)
		{
			mlx_destroy_image(all->mlx->mlx_ptr, all->walls->WE->tex_ptr);
			free(all->walls->WE);
		}
		free(all->walls);
	}
	if (all->spr && all->spr->tex)
	{
		mlx_destroy_image(all->mlx->mlx_ptr, all->spr->tex->tex_ptr);
		free(all->spr->tex);
	}
}

void	ft_free(t_all *all)
{
	ft_free_info(all);
	ft_clear_texture(all);
	ft_free_mlx(all);
	if (all->coord)
		free(all->coord);
	if (all->print)
		free(all->print);
	if (all->spr)
	{
		if (all->spr->dist)
			free(all->spr->dist);
		free(all->spr);
	}
}
