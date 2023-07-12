/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:53:17 by cdurro            #+#    #+#             */
/*   Updated: 2023/07/12 12:24:23 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_all(t_map *map)
{
	int	i;

	mlx_close_window(map->window);
	mlx_terminate(map->window);
	i = -1;
	while (++i < map->height)
		free(map->points[i]);
	free(map->points);
	free(map);
	exit(1);
}
