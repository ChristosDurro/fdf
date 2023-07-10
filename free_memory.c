/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:53:17 by cdurro            #+#    #+#             */
/*   Updated: 2023/07/10 13:41:28 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_all(t_map *map)
{
	int	i;
	mlx_terminate(map->window);

	// mlx_delete_image(map->window, map->img);
	// mlx_close_window(map->window);
	i = -1;
	while (++i < map->height)
		free(map->points[i]);
	free(map->points);
	free(map);
}