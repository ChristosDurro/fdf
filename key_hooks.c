/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:30:37 by cdurro            #+#    #+#             */
/*   Updated: 2023/07/10 10:59:44 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	translate(mlx_key_data_t keydata, t_map *map)
{
	if (keydata.key == MLX_KEY_UP && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		map->shift_y -= 10;
	if (keydata.key == MLX_KEY_DOWN && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		map->shift_y += 10;
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		map->shift_x -= 10;
	if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		map->shift_x += 10;
}

void	zoom(mlx_key_data_t keydata, t_map *map)
{
	
	if (keydata.key == MLX_KEY_EQUAL && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		map->zoom += 1.25;
	if (keydata.key == MLX_KEY_MINUS && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		map->zoom -= 1.25;
}

void	double_rotation(mlx_key_data_t keydata, t_map *map)
{	
	if (keydata.key == MLX_KEY_KP_7 && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		map->angles.a += 5 * ONE_DEGREE;
		map->angles.b -= 5 * ONE_DEGREE;
	}
	if (keydata.key == MLX_KEY_KP_9 && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		map->angles.a += 5 * ONE_DEGREE;
		map->angles.b += 5 * ONE_DEGREE;
	}
	if (keydata.key == MLX_KEY_KP_1 && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		map->angles.a -= 5 * ONE_DEGREE;
		map->angles.b -= 5 * ONE_DEGREE;
	}
	if (keydata.key == MLX_KEY_KP_3 && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		map->angles.a -= 5 * ONE_DEGREE;
		map->angles.b += 5 * ONE_DEGREE;
	}
}

void	rotation(mlx_key_data_t keydata, t_map *map)
{

	if (keydata.key == MLX_KEY_KP_8 && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		map->angles.a += 5 * ONE_DEGREE;
	if (keydata.key == MLX_KEY_KP_2 && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		map->angles.a -= 5 * ONE_DEGREE;
	if (keydata.key == MLX_KEY_KP_4 && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		map->angles.b -= 5 * ONE_DEGREE;
	if (keydata.key == MLX_KEY_KP_6 && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		map->angles.b += 5 * ONE_DEGREE;
	if (keydata.key == MLX_KEY_KP_MULTIPLY && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		map->angles.c -= 5 * ONE_DEGREE;
	if (keydata.key == MLX_KEY_KP_DIVIDE && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		map->angles.c += 5 * ONE_DEGREE;
}

void	rest(mlx_key_data_t keydata, t_map *map)
{
	if (keydata.key == MLX_KEY_KP_SUBTRACT && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		map->shift_z -= 1;
	if (keydata.key == MLX_KEY_KP_ADD && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		map->shift_z += 1;
	if (keydata.key == MLX_KEY_1 && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		map->view = 0;
	if (keydata.key == MLX_KEY_2 && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		map->view = 1;
	if (keydata.key == MLX_KEY_R && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		reset_map(map);
	if (keydata.key == MLX_KEY_ESCAPE && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		free_all(map);
		exit(0);
	}
}

