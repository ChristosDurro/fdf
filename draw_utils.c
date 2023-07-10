/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 09:57:13 by cdurro            #+#    #+#             */
/*   Updated: 2023/07/10 10:52:05 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	center_map(t_point *p1, t_point *p2, t_map *map)
{
	p1->x += (WIDTH / 2 - (map->width) / 2) / 2;
	p1->y += (HEIGHT / 2 - (map->height) / 2) / 2;
	p2->x += (WIDTH / 2 - (map->width) / 2) / 2;
	p2->y += (HEIGHT / 2 - (map->height) / 2) / 2;
}

void	shift_pixels(t_point *p1, t_point *p2, t_map *map)
{
	p1->x += map->shift_x;
	p1->y += map->shift_y;
	p2->x += map->shift_x;
	p2->y += map->shift_y;
}

void	zoom_map(t_point *p1, t_point *p2, t_map *map)
{	
	if (map->zoom <= 1.25)
		map->zoom = 1.562500;
	if (map->zoom > 86)
		map->zoom = 85;
	p1->x *= map->zoom;
	p1->y *= map->zoom;
	p2->x *= map->zoom;
	p2->y *= map->zoom;
}

int put_color(int z)
{
	if (z < -20)
		return (0x120266ff);
	else if (z > -20 && z < -10)
		return (0x234a6dff);
	else if (z > -10 && z < 0)
		return (0x2f05ffff);
	else if (z == 0)
		return (0xe2a463ff);
	else if (z > 0 && z < 10)
		return (0x2c5f16ff);
	else if (z > 10 && z < 20)
		return (0x3a1a03ff);
	else if (z > 20)
		return (0x204610ff);
	else
		return (0x1f6595ff);
		
}

void	color_pixels(t_point *p1, t_point *p2, t_map *map)
{
	if (p1->color == -1)
	{
		p1->color= put_color(p1->z);
		p2->color = put_color(p2->z);	
	}
}
