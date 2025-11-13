/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:48:20 by riel-fas          #+#    #+#             */
/*   Updated: 2025/10/28 14:47:57 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

int	is_pixel_in_minimap(t_data *data, int x, int y)
{
	return (x >= data->minimap.x_pos 
		&& x < data->minimap.x_pos + data->minimap.size
		&& y >= data->minimap.y_pos 
		&& y < data->minimap.y_pos + data->minimap.size);
}

void	draw_minimap_pixel(t_data *data, int x, int y, uint32_t color)
{
	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		if (is_pixel_in_minimap(data, x, y))
			mlx_put_pixel(data->image, x, y, color);
	}
}

void	draw_minimap_tile(t_data *data, int map_x, int map_y, uint32_t color)
{
	int	screen_x;
	int	screen_y;
	int	dx;
	int	dy;
	int	tile_size;

	tile_size = data->minimap.tile_size;
	screen_x = data->minimap.x_pos + (int)((map_x - data->player_x) 
			* tile_size) + data->minimap.center_x;
	screen_y = data->minimap.y_pos + (int)((map_y - data->player_y) 
			* tile_size) + data->minimap.center_y;
	dy = 0;
	while (dy < tile_size)
	{
		dx = 0;
		while (dx < tile_size)
		{
			draw_minimap_pixel(data, screen_x + dx, screen_y + dy, color);
			dx++;
		}
		dy++;
	}
}
