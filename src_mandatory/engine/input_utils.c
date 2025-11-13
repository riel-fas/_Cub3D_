/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:06:27 by riel-fas          #+#    #+#             */
/*   Updated: 2025/10/28 11:09:12 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	rotate_player(t_data *data, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	data->player_angle += angle;
	data->player_angle = normalize_angle(data->player_angle);
	old_dir_x = data->player_dir_vec.x;
	data->player_dir_vec.x = data->player_dir_vec.x * cos(angle) - 
		data->player_dir_vec.y * sin(angle);
	data->player_dir_vec.y = old_dir_x * sin(angle) + 
		data->player_dir_vec.y * cos(angle);
	old_plane_x = data->camera_plane.x;
	data->camera_plane.x = data->camera_plane.x * cos(angle) - 
		data->camera_plane.y * sin(angle);
	data->camera_plane.y = old_plane_x * sin(angle) + 
		data->camera_plane.y * cos(angle);
}

void	handle_input(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		data->game_running = FALSE;
		mlx_close_window(data->mlx);
		return ;
	}
	handle_movement_keys(keydata, data);
	handle_rotation_keys(keydata, data);
}

void	process_forward_backward(t_data *data)
{
	double	move_x;
	double	move_y;

	if (data->keys.w_pressed)
	{
		move_x = data->player_dir_vec.x * MOVE_SPEED;
		move_y = data->player_dir_vec.y * MOVE_SPEED;
		move_player(data, move_x, move_y);
	}
	if (data->keys.s_pressed)
	{
		move_x = -data->player_dir_vec.x * MOVE_SPEED;
		move_y = -data->player_dir_vec.y * MOVE_SPEED;
		move_player(data, move_x, move_y);
	}
}

void	process_strafe(t_data *data)
{
	double	move_x;
	double	move_y;

	if (data->keys.a_pressed)
	{
		move_x = data->player_dir_vec.y * MOVE_SPEED;
		move_y = -data->player_dir_vec.x * MOVE_SPEED;
		move_player(data, move_x, move_y);
	}
	if (data->keys.d_pressed)
	{
		move_x = -data->player_dir_vec.y * MOVE_SPEED;
		move_y = data->player_dir_vec.x * MOVE_SPEED;
		move_player(data, move_x, move_y);
	}
}
