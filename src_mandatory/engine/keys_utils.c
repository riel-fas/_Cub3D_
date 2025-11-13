/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:58:30 by riel-fas          #+#    #+#             */
/*   Updated: 2025/10/28 11:09:20 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	handle_w_key(mlx_key_data_t keydata, t_data *data)
{
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		data->keys.w_pressed = 1;
	else
		data->keys.w_pressed = 0;
}

void	handle_a_key(mlx_key_data_t keydata, t_data *data)
{
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		data->keys.a_pressed = 1;
	else
		data->keys.a_pressed = 0;
}

void	handle_s_key(mlx_key_data_t keydata, t_data *data)
{
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		data->keys.s_pressed = 1;
	else
		data->keys.s_pressed = 0;
}

void	handle_d_key(mlx_key_data_t keydata, t_data *data)
{
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		data->keys.d_pressed = 1;
	else
		data->keys.d_pressed = 0;
}
