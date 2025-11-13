/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils_1_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 00:00:00 by riel-fas          #+#    #+#             */
/*   Updated: 2025/10/28 14:47:35 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static void	draw_player_circle_row(t_data *data, int center_x, 
	int center_y, int dy)
{
	int	dx;
	int	x;
	int	y;
	int	radius;

	radius = 3;
	dx = -radius;
	while (dx <= radius)
	{
		if (dx * dx + dy * dy <= radius * radius)
		{
			x = center_x + dx;
			y = center_y + dy;
			draw_minimap_pixel(data, x, y, MINIMAP_PLAYER_COLOR);
		}
		dx++;
	}
}

void	draw_minimap_player(t_data *data)
{
	int	dy;
	int	radius;
	int	center_x;
	int	center_y;

	radius = 3;
	center_x = data->minimap.x_pos + data->minimap.center_x;
	center_y = data->minimap.y_pos + data->minimap.center_y;
	dy = -radius;
	while (dy <= radius)
	{
		draw_player_circle_row(data, center_x, center_y, dy);
		dy++;
	}
}

static void	draw_single_ray(t_data *data, double ray_angle, 
	int center_x, int center_y)
{
	int		x;
	int		y;
	int		steps;
	int		z;
	double	ray_length;

	ray_length = 20.0;
	steps = (int)ray_length;
	z = 0;
	while (z < steps)
	{
		x = center_x + (int)(cos(ray_angle) * z);
		y = center_y + (int)(sin(ray_angle) * z);
		draw_minimap_pixel(data, x, y, MINIMAP_RAY_COLOR);
		z++;
	}
}

void	draw_minimap_rays(t_data *data)
{
	double	ray_angle;
	int		center_x;
	int		center_y;

	center_x = data->minimap.x_pos + data->minimap.center_x;
	center_y = data->minimap.y_pos + data->minimap.center_y;
	ray_angle = data->player_angle - FOV / 2;
	while (ray_angle <= data->player_angle + FOV / 2)
	{
		draw_single_ray(data, ray_angle, center_x, center_y);
		ray_angle += FOV / 20;
	}
}
