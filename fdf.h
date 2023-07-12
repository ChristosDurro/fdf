/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:04:34 by cdurro            #+#    #+#             */
/*   Updated: 2023/07/12 13:05:13 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "color_codes.h"

# define WIDTH 1920
# define HEIGHT 1080
# define ONE_DEGREE 0.0174533

typedef struct s_point
{
	float			x;
	float			y;
	int				z;
	unsigned int	color;
}			t_point;

typedef struct s_angles
{
	float	a;
	float	b;
	float	c;
}			t_angles;

typedef struct s_menu
{
	int			imgs;

	mlx_image_t	*controls_img;
	mlx_image_t	*translate_img;
	mlx_image_t	*rotate_xy_img;
	mlx_image_t	*rotate_z_img;
	mlx_image_t	*shift_z_img;
	mlx_image_t	*zoom_img;
	mlx_image_t	*project_img;
	mlx_image_t	*normal_img;
	mlx_image_t	*iso_img;
	mlx_image_t	*par_img;
	mlx_image_t	*x_img;
	mlx_image_t	*y_img;
	mlx_image_t	*z_img;
	mlx_image_t	*info_img;
	mlx_image_t	*width_img;
	mlx_image_t	*height_img;
}			t_menu;

typedef struct s_color
{
	unsigned int	colors[3][8];
}			t_color;

typedef struct s_map
{
	int			width;
	int			height;
	int			shift_x;
	int			shift_y;
	int			shift_z;
	int			view;
	int			color_theme;
	float		zoom;

	mlx_t		*window;
	mlx_image_t	*img;
	t_angles	angles;
	t_point		**points;
	t_menu		menu;
	t_color		colors;
}		t_map;

void	read_file(t_map *map, char *file_name);
void	fill_matrix(char *file_name, t_map *map);
void	draw_line(t_point pixel1, t_point pixel2, t_map *map);
void	draw(t_map *map);
void	ft_print_map(t_map m);
void	center_map(t_point *p1, t_point *p2, t_map *map);
void	shift_pixels(t_point *p1, t_point *p2, t_map *map);
void	zoom_map(t_point *p1, t_point *p2, t_map *map);
void	project(t_point *p1, t_point *p2, t_map *map);
void	color_pixels(t_point *p1, t_point *p2, t_map *map);
void	translate(mlx_key_data_t key, t_map *map);
void	double_rotation(mlx_key_data_t key, t_map *map);
void	rotation(mlx_key_data_t key, t_map *map);
void	rest(mlx_key_data_t key, t_map *map);
void	init_window(t_map *map);
void	init_map(t_map *map, int val);
void	reset_map(t_map *map);
void	free_all(t_map *map);
void	handle_key_is_down(mlx_key_data_t key, void *param);
void	print_menu(t_map *map);
void	update_map(t_map *map);

t_point	isometric(t_point pixel, t_map *map);

int		get_width(char *file_name);
int		get_height(char *file_name);
int		deal_key(int key, t_map *map);
int		put_color(int z, t_map *map);

#endif