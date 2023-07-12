/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:41:47 by cdurro            #+#    #+#             */
/*   Updated: 2023/07/12 12:54:43 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	delete_prev_imgs(t_map *map)
{
	if (map->menu.imgs)
	{
		mlx_delete_image(map->window, map->menu.controls_img);
		mlx_delete_image(map->window, map->menu.translate_img);
		mlx_delete_image(map->window, map->menu.rotate_xy_img);
		mlx_delete_image(map->window, map->menu.rotate_z_img);
		mlx_delete_image(map->window, map->menu.shift_z_img);
		mlx_delete_image(map->window, map->menu.zoom_img);
		mlx_delete_image(map->window, map->menu.project_img);
		mlx_delete_image(map->window, map->menu.normal_img);
		mlx_delete_image(map->window, map->menu.iso_img);
		mlx_delete_image(map->window, map->menu.par_img);
		mlx_delete_image(map->window, map->menu.x_img);
		mlx_delete_image(map->window, map->menu.y_img);
		mlx_delete_image(map->window, map->menu.z_img);
		mlx_delete_image(map->window, map->menu.info_img);
		mlx_delete_image(map->window, map->menu.width_img);
		mlx_delete_image(map->window, map->menu.height_img);
	}
}

static void	set_text_imgs(t_map *map)
{
	map->menu.controls_img = mlx_put_string(map->window,
			"### CONTROLS ###\n", 50, 50);
	map->menu.translate_img = mlx_put_string(map->window,
			"translate: arrows", 50, 100);
	map->menu.rotate_xy_img = mlx_put_string(map->window,
			"rotate x/y:  4\\2\\6\\8 (NUMPAD)", 50, 125);
	map->menu.rotate_z_img = mlx_put_string(map->window,
			"rotate z: '/'\\'*' (NUMPAD)", 50, 150);
	map->menu.shift_z_img = mlx_put_string(map->window,
			"shift z: -\\+ (NUMPAD)", 50, 175);
	map->menu.zoom_img = mlx_put_string(map->window,
			"zoom: -\\+", 50, 200);
	map->menu.project_img = mlx_put_string(map->window,
			"projections:", 50, 250);
	map->menu.normal_img = mlx_put_string(map->window,
			"              1: 2D", 50, 250);
	map->menu.iso_img = mlx_put_string(map->window,
			"              2: ISOMETRIC", 50, 275);
	map->menu.par_img = mlx_put_string(map->window,
			"              3: PARALLEL", 50, 300);
}

static void	set_coords_imgs(t_map *map)
{
	char	*tmp;
	float	center_x;
	float	center_y;
	char	*num;

	center_x = (WIDTH / 2 - (map->width) / 2) / 2;
	num = ft_itoa((int)center_x + map->shift_x);
	tmp = ft_strjoin("x: ", num);
	map->menu.x_img = mlx_put_string(map->window, tmp, 50, 350);
	free(tmp);
	free(num);
	center_y = (HEIGHT / 2 - (map->height) / 2) / 2;
	num = ft_itoa((int)center_y + map->shift_y);
	tmp = ft_strjoin("y: ", num);
	map->menu.y_img = mlx_put_string(map->window, tmp, 50, 375);
	free(tmp);
	free(num);
	num = ft_itoa(map->shift_z);
	tmp = ft_strjoin("z: ", num);
	map->menu.z_img = mlx_put_string(map->window, tmp, 50, 400);
	free(tmp);
	free(num);
}

static void	map_info(t_map *map)
{
	char	*tmp;
	char	*num;

	map->menu.info_img = mlx_put_string(map->window,
			"### MAP INFO ###", 50, 450);
	num = ft_itoa(map->width);
	tmp = ft_strjoin("width: ", num);
	map->menu.width_img = mlx_put_string(map->window, tmp, 50, 475);
	free(tmp);
	free(num);
	num = ft_itoa(map->height);
	tmp = ft_strjoin("height: ", num);
	map->menu.height_img = mlx_put_string(map->window, tmp, 50, 500);
	free(tmp);
	free(num);
}

void	print_menu(t_map *map)
{
	delete_prev_imgs(map);
	set_text_imgs(map);
	set_coords_imgs(map);
	map_info(map);
	map->menu.imgs = 1;
}
