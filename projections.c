/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:05:24 by cdurro            #+#    #+#             */
/*   Updated: 2023/07/12 13:13:57 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	isometric(t_point pixel, t_map *map)
{
	float	tmp_x;
	float	tmp_y;

	pixel.x -= map->width / 2;
	pixel.y -= map->height / 2;
	tmp_x = pixel.x;
	tmp_y = pixel.y;
	pixel.y = tmp_y * cos(map->angles.a) - pixel.z * sin(map->angles.a);
	pixel.z = tmp_y * sin(map->angles.a) + pixel.z * cos(map->angles.a);
	pixel.x = tmp_x * cos(map->angles.b) + pixel.z * sin(map->angles.b);
	pixel.z = -tmp_x * sin(map->angles.b) + pixel.z * cos(map->angles.b);
	tmp_x = pixel.x;
	tmp_y = pixel.y;
	pixel.x = tmp_x * cos(map->angles.c) - tmp_y * sin(map->angles.c);
	pixel.y = tmp_x * sin(map->angles.c) + tmp_y * cos(map->angles.c);
	pixel.x += map->width / 2;
	pixel.y += map->height / 2;
	return (pixel);
}

void	project(t_point *p1, t_point *p2, t_map *map)
{
	*p1 = isometric(*p1, map);
	*p2 = isometric(*p2, map);
}
