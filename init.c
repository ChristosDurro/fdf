/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:42:09 by cdurro            #+#    #+#             */
/*   Updated: 2023/07/10 14:03:21 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_window(t_map *map)
{
	map->window = mlx_init(WIDTH, HEIGHT, "fdf", false);
	map->menu.window = map->window;
}

void	init_map(t_map *map, int val)
{
	map->angles.a = 0.087266;
	map->angles.b = -0.087266;
	map->angles.c = 0.785398;
	map->shift_x = 0;
	map->shift_y = 0;
	map->shift_z = 1;
	map->view = 0;
	if (val)
	{
		map->img = malloc(sizeof(mlx_image_t *));
		if (!map->img)
			return ;
	}
}