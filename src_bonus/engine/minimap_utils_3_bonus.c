/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils_3_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:48:58 by riel-fas          #+#    #+#             */
/*   Updated: 2025/10/28 14:49:09 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static uint32_t	get_tile_color(char tile)
{
	if (tile == '1')
		return (MINIMAP_WALL_COLOR);
	else if (tile == 'D')
		return (MINIMAP_DOOR_COLOR);
	else if (tile == '0' || tile == 'N' || tile == 'S' 
		|| tile == 'E' || tile == 'W')
		return (MINIMAP_FLOOR_COLOR);
	else
		return (MINIMAP_BG_COLOR);
}

static void	draw_minimap_row(t_data *data, int y, int range)
{
	int			x;
	uint32_t	color;

	x = (int)data->player_x - range;
	while (x < (int)data->player_x + range)
	{
		if (x >= 0 && x < data->map_width && y >= 0 && y < data->map_height)
		{
			color = get_tile_color(data->map[y][x]);
			draw_minimap_tile(data, x, y, color);
		}
		x++;
	}
}

void	draw_minimap_tiles(t_data *data)
{
	int	x;
	int	range;

	range = (data->minimap.size / data->minimap.tile_size) / 2 + 2;
	x = (int)data->player_y - range;
	while (x < (int)data->player_y + range)
	{
		draw_minimap_row(data, x, range);
		x++;
	}
}
