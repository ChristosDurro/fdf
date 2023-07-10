/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:05:24 by cdurro            #+#    #+#             */
/*   Updated: 2023/07/10 10:35:02 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point isometric(t_point pixel, t_map *map)
{
	pixel.x -= map->width / 2;
	pixel.y -= map->height / 2;
    float tmpX = pixel.x;
    float tmpY = pixel.y;

    pixel.y = tmpY * cos(map->angles.a) -pixel.z * sin(map->angles.a);
	pixel.z = tmpY * sin(map->angles.a) +pixel.z * cos(map->angles.a);
    pixel.x = tmpX * cos(map->angles.b) +pixel.z * sin(map->angles.b);
	pixel.z = -tmpX * sin(map->angles.b) +pixel.z * cos(map->angles.b);
    tmpX = pixel.x;
    tmpY = pixel.y;
    pixel.x = tmpX * cos(map->angles.c) - tmpY * sin(map->angles.c);
    pixel.y = tmpX * sin(map->angles.c) + tmpY * cos(map->angles.c);
	pixel.x += map->width / 2;
	pixel.y += map->height / 2;
	// printf("angle a: %f\n", map->angles.a);
	// printf("angle b: %f\n", map->angles.b);
	// printf("angle c: %f\n", map->angles.c);
	return (pixel);
}

void	project(t_point *p1, t_point *p2, t_map *map)
{
	*p1 = isometric(*p1, map);
	*p2 = isometric(*p2, map);
}