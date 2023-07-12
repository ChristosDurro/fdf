/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:30:37 by cdurro            #+#    #+#             */
/*   Updated: 2023/07/12 11:26:00 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate(mlx_key_data_t keydata, t_map *map)
{
	if (mlx_is_key_down(map->window, MLX_KEY_UP))
		map->shift_y -= 10;
	if (mlx_is_key_down(map->window, MLX_KEY_DOWN))
		map->shift_y += 10;
	if (mlx_is_key_down(map->window, MLX_KEY_LEFT))
		map->shift_x -= 10;
	if (mlx_is_key_down(map->window, MLX_KEY_RIGHT))
		map->shift_x += 10;
}

void	double_rotation(mlx_key_data_t keydata, t_map *map)
{
	if (mlx_is_key_down(map->window, MLX_KEY_KP_7))
	{
		map->angles.a += 5 * ONE_DEGREE;
		map->angles.b -= 5 * ONE_DEGREE;
	}
	if (mlx_is_key_down(map->window, MLX_KEY_KP_9))
	{
		map->angles.a += 5 * ONE_DEGREE;
		map->angles.b += 5 * ONE_DEGREE;
	}
	if (mlx_is_key_down(map->window, MLX_KEY_KP_1))
	{
		map->angles.a -= 5 * ONE_DEGREE;
		map->angles.b -= 5 * ONE_DEGREE;
	}
	if (mlx_is_key_down(map->window, MLX_KEY_KP_3))
	{
		map->angles.a -= 5 * ONE_DEGREE;
		map->angles.b += 5 * ONE_DEGREE;
	}
}

void	rotation(mlx_key_data_t keydata, t_map *map)
{
	if (mlx_is_key_down(map->window, MLX_KEY_KP_8))
		map->angles.a += 5 * ONE_DEGREE;
	if (mlx_is_key_down(map->window, MLX_KEY_KP_2))
		map->angles.a -= 5 * ONE_DEGREE;
	if (mlx_is_key_down(map->window, MLX_KEY_KP_4))
		map->angles.b -= 5 * ONE_DEGREE;
	if (mlx_is_key_down(map->window, MLX_KEY_KP_6))
		map->angles.b += 5 * ONE_DEGREE;
	if (mlx_is_key_down(map->window, MLX_KEY_KP_MULTIPLY))
		map->angles.c -= 5 * ONE_DEGREE;
	if (mlx_is_key_down(map->window, MLX_KEY_KP_DIVIDE))
		map->angles.c += 5 * ONE_DEGREE;
}

void	rest(mlx_key_data_t keydata, t_map *map)
{
	if (mlx_is_key_down(map->window, MLX_KEY_KP_SUBTRACT))
		map->shift_z -= 1;
	if (mlx_is_key_down(map->window, MLX_KEY_KP_ADD))
		map->shift_z += 1;
	if (mlx_is_key_down(map->window, MLX_KEY_1))
		map->view = 0;
	if (mlx_is_key_down(map->window, MLX_KEY_2))
		map->view = 1;
	if (mlx_is_key_down(map->window, MLX_KEY_R))
		reset_map(map);
	if (mlx_is_key_down(map->window, MLX_KEY_C))
		map->color_theme += 1;
	if (mlx_is_key_down(map->window, MLX_KEY_ESCAPE))
	{
		free_all(map);
		exit(1);
	}
}
