/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:58:21 by cdurro            #+#    #+#             */
/*   Updated: 2023/07/12 13:05:38 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_map(t_map *map)
{
	init_map(map, 0);
	update_map(map);
}

void	update_map(t_map *map)
{
	mlx_delete_image(map->window, map->img);
	map->img = mlx_new_image(map->window, WIDTH, HEIGHT);
	if (!map->img)
		return ;
	draw(map);
}
