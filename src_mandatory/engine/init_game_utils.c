/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:12:48 by riel-fas          #+#    #+#             */
/*   Updated: 2025/10/28 11:08:50 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	init_mlx(t_data *data)
{
	printf("🖥️  Initializing MLX42...\n");
	data->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, false);
	if (!data->mlx)
	{
		printf("❌ Failed to initialize MLX42\n");
		return (FALSE);
	}
	data->image = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data->image)
	{
		printf("❌ Failed to create MLX image\n");
		mlx_terminate(data->mlx);
		return (FALSE);
	}
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) == -1)
	{
		printf("❌ Failed to display image\n");
		mlx_delete_image(data->mlx, data->image);
		mlx_terminate(data->mlx);
		return (FALSE);
	}
	printf("✅ MLX42 initialized successfully\n");
	return (TRUE);
}

int	init_player(t_data *data)
{
	printf("🎮 Initializing player...\n");
	setup_player_vectors(data);
	data->floor_color.hex = rgb_to_hex(data->floor_color.r, 
			data->floor_color.g, 
			data->floor_color.b);
	data->ceiling_color.hex = rgb_to_hex(data->ceiling_color.r, 
			data->ceiling_color.g, 
			data->ceiling_color.b);
	printf("✅ Player initialized successfully\n");
	return (TRUE);
}
