/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:05:02 by riel-fas          #+#    #+#             */
/*   Updated: 2025/10/28 11:02:45 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

void	handle_rotation_keys(mlx_key_data_t keydata, t_data *data)
{
	if (keydata.key == MLX_KEY_LEFT)
	{
		if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
			data->keys.left_pressed = 1;
		else
			data->keys.left_pressed = 0;
	}
	else if (keydata.key == MLX_KEY_RIGHT)
	{
		if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
			data->keys.right_pressed = 1;
		else
			data->keys.right_pressed = 0;
	}
}

void	handle_f_key(mlx_key_data_t keydata, t_data *data)
{
	if (keydata.action == MLX_PRESS)
		toggle_door(data);
}
