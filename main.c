/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:04:21 by cdurro            #+#    #+#             */
/*   Updated: 2023/07/12 13:07:56 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_key_is_down(mlx_key_data_t keydata, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	translate(keydata, map);
	rotation(keydata, map);
	double_rotation(keydata, map);
	rest(keydata, map);
	update_map(map);
}

void	handle_scroll(double x, double y, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (y > 0)
		map->zoom += 1.25;
	else
		map->zoom -= 1.25;
	update_map(map);
}

int	close_window(t_map *map)
{
	free_all(map);
	exit(0);
	return (0);
}

void	ft_print_map(t_map map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map.height)
	{
		x = -1;
		while (++x < map.width)
			printf("%3lld", (long long)map.points[y][x].z);
		printf("\n");
		y++;
	}
	printf("Width: %d\n", map.width);
	printf("Height: %d\n", map.height);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (1);
	if (argc == 2)
	{
		init_map(map, 1);
		read_file(map, argv[1]);
		init_window(map);
		if (map->width > 30)
			map->zoom = 1.562500;
		else
			map->zoom = 20.0;
		map->img = mlx_new_image(map->window, WIDTH, HEIGHT);
		draw(map);
		mlx_key_hook(map->window, &handle_key_is_down, map);
		mlx_scroll_hook(map->window, &handle_scroll, map);
		mlx_loop(map->window);
	}
	return (0);
}
