/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:31:07 by cdurro            #+#    #+#             */
/*   Updated: 2023/07/12 13:20:16 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	shift_z(t_point *pixel1, t_point *pixel2, t_map *map)
{
	if (map->shift_z > 35)
		map->shift_z = 35;
	if (map->shift_z < -35)
		map->shift_z = -35;
	pixel1->z *= map->shift_z;
	pixel2->z *= map->shift_z;
}

static float	ft_max(float x, float y)
{
	if (x > y)
		return (x);
	return (y);
}

static float	ft_float_abs(float x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	draw_line(t_point pixel1, t_point pixel2, t_map *map)
{
	float	x_step;
	float	y_step;
	int		max;

	color_pixels(&pixel1, &pixel2, map);
	shift_z(&pixel1, &pixel2, map);
	if (map->view == 1)
		project(&pixel1, &pixel2, map);
	zoom_map(&pixel1, &pixel2, map);
	shift_pixels(&pixel1, &pixel2, map);
	center_map(&pixel1, &pixel2, map);
	x_step = pixel2.x - pixel1.x;
	y_step = pixel2.y - pixel1.y;
	max = ft_max(ft_float_abs(x_step), ft_float_abs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(pixel1.x - pixel2.x) || (int)(pixel1.y - pixel2.y))
	{
		if (pixel1.x > 0 && pixel1.x < WIDTH
			&& pixel1.y > 0 && pixel1.y < HEIGHT)
			mlx_put_pixel(map->img, pixel1.x, pixel1.y, pixel1.color);
		pixel1.x += x_step;
		pixel1.y += y_step;
	}
}

void	draw(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < map->width - 1)
			{
				draw_line(map->points[y][x], map->points[y][x + 1], map);
			}
			if (y < map->height - 1)
				draw_line(map->points[y][x], map->points[y + 1][x], map);
			x++;
		}
		y++;
	}
	print_menu(map);
	mlx_image_to_window(map->window, map->img, 350, 0);
}
