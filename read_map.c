/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:56:13 by cdurro            #+#    #+#             */
/*   Updated: 2023/07/12 13:16:40 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_width(char *file_name)
{
	int		fd;
	int		columns;
	char	*line;
	char	**nums;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	nums = ft_split(line, ' ');
	columns = 0;
	while (nums[columns])
	{
		free(nums[columns]);
		columns++;
	}
	close(fd);
	free(line);
	free(nums);
	return (columns);
}

int	get_height(char *file_name)
{
	int		fd;
	int		rows;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	rows = 0;
	while (line)
	{
		rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (rows);
}

static t_point	point_init(int x, int y, char **num)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = ft_atoi(num[0]);
	if (num[1] != NULL)
	{
		point.color = ft_strtol(num[1]) << 8 | 0xff;
		free(num[1]);
	}
	else
		point.color = -1;
	free(num[0]);
	free(num);
	return (point);
}

void	fill_matrix(char *file_name, t_map *map)
{
	int		x;	
	int		y;
	int		fd;
	char	*line;
	char	**nums;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return ;
	line = get_next_line(fd);
	y = -1;
	while (line)
	{
		nums = ft_split(line, ' ');
		x = -1;
		while (++x < map->width)
		{
			map->points[++y][x] = point_init(x, y, ft_split(nums[x], ','));
			free(nums[x]);
		}
		free(line);
		free(nums);
		line = get_next_line(fd);
	}
}

void	read_file(t_map *map, char *file_name)
{
	int	fd;
	int	i;

	map->width = get_width(file_name);
	map->height = get_height(file_name);
	map->points = malloc(sizeof(t_point *) * (map->height));
	i = -1;
	while (++i < map->height)
		map->points[i] = malloc(sizeof(t_point) * (map->width));
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	fill_matrix(file_name, map);
	close(fd);
}
