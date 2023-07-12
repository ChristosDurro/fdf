/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:42:09 by cdurro            #+#    #+#             */
/*   Updated: 2023/07/12 13:06:31 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_window(t_map *map)
{
	map->window = mlx_init(WIDTH, HEIGHT, "fdf", false);
}

static void	init_colors(t_map *map)
{
	map->colors.colors[0][0] = WHITE;
	map->colors.colors[0][1] = WHITE;
	map->colors.colors[0][2] = WHITE;
	map->colors.colors[0][3] = DEFAULT_COLOR;
	map->colors.colors[0][4] = DEFAULT_COLOR;
	map->colors.colors[0][5] = WHITE;
	map->colors.colors[0][6] = WHITE;
	map->colors.colors[0][7] = WHITE;
	map->colors.colors[1][0] = DARKER_BLUE;
	map->colors.colors[1][1] = DARK_BLUE;
	map->colors.colors[1][2] = BLUE;
	map->colors.colors[1][3] = SAND_COLOR;
	map->colors.colors[1][4] = GREEN;
	map->colors.colors[1][5] = BROWN;
	map->colors.colors[1][6] = DARK_GREEN;
	map->colors.colors[1][7] = DARK_GREEN;
	map->colors.colors[2][0] = BLUE;
	map->colors.colors[2][1] = LIGHT_BLUE_1;
	map->colors.colors[2][2] = LIGHT_BLUE;
	map->colors.colors[2][3] = LIGHT_RED;
	map->colors.colors[2][4] = DARK_PURPLE;
	map->colors.colors[2][5] = PURPLE;
	map->colors.colors[2][6] = LIGHT_YELLOW;
	map->colors.colors[2][7] = LIGHT_GRAY;
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
	map->color_theme = 0;
	if (val)
	{
		map->menu.imgs = 0;
		init_colors(map);
	}
}
