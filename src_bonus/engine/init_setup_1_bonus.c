/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_setup_1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:41:42 by riel-fas          #+#    #+#             */
/*   Updated: 2025/10/28 11:02:30 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

void	setup_player_position(t_data *data)
{
	data->player_pos.x = data->player_x;
	data->player_pos.y = data->player_y;
}

void	setup_direction_north(t_data *data)
{
	data->player_dir_vec.x = 0.0;
	data->player_dir_vec.y = -1.0;
	data->camera_plane.x = 0.66;
	data->camera_plane.y = 0.0;
}

void	setup_direction_south(t_data *data)
{
	data->player_dir_vec.x = 0.0;
	data->player_dir_vec.y = 1.0;
	data->camera_plane.x = -0.66;
	data->camera_plane.y = 0.0;
}

void	setup_direction_east(t_data *data)
{
	data->player_dir_vec.x = 1.0;
	data->player_dir_vec.y = 0.0;
	data->camera_plane.x = 0.0;
	data->camera_plane.y = 0.66;
}

void	setup_direction_west(t_data *data)
{
	data->player_dir_vec.x = -1.0;
	data->player_dir_vec.y = 0.0;
	data->camera_plane.x = 0.0;
	data->camera_plane.y = -0.66;
}
