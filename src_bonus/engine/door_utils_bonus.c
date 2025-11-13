/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:53:14 by riel-fas          #+#    #+#             */
/*   Updated: 2025/10/28 14:46:06 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

void	free_door_states(t_data *data)
{
	int	x;

	if (!data->door_states)
		return ;
	x = 0;
	while (x < data->map_height)
	{
		free(data->door_states[x]);
		x++;
	}
	free(data->door_states);
	data->door_states = NULL;
}

int	is_door_open(t_data *data, int x, int y)
{
	if (y < 0 || y >= data->map_height || x < 0 || x >= data->map_width)
		return (0);
	if (!data->door_states)
		return (0);
	return (data->door_states[y][x] == '1');
}

void	toggle_door(t_data *data)
{
	int		door_x;
	int		door_y;
	double	check_dist;

	check_dist = 1.5;
	door_x = (int)(data->player_pos.x + data->player_dir_vec.x * check_dist);
	door_y = (int)(data->player_pos.y + data->player_dir_vec.y * check_dist);
	if (door_x < 0 || door_x >= data->map_width
		|| door_y < 0 || door_y >= data->map_height)
		return ;
	if (data->map[door_y][door_x] == DOOR)
	{
		if (data->door_states[door_y][door_x] == '0')
		{
			data->door_states[door_y][door_x] = '1';
			printf("🚪 Door opened at (%d, %d)\n", door_x, door_y);
		}
		else
		{
			data->door_states[door_y][door_x] = '0';
			printf("🚪 Door closed at (%d, %d)\n", door_x, door_y);
		}
	}
}
