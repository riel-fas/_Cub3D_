/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:02:18 by riel-fas          #+#    #+#             */
/*   Updated: 2025/10/28 11:02:24 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static void	init_key_states(t_data *data)
{
	data->keys.w_pressed = 0;
	data->keys.a_pressed = 0;
	data->keys.s_pressed = 0;
	data->keys.d_pressed = 0;
	data->keys.left_pressed = 0;
	data->keys.right_pressed = 0;
}

static void	setup_game_hooks(t_data *data)
{
	mlx_key_hook(data->mlx, handle_input, data);
	mlx_cursor_hook(data->mlx, handle_mouse, data);
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
}

static int	init_game_components(t_data *data)
{
	if (!load_textures(data))
	{
		mlx_terminate(data->mlx);
		return (FALSE);
	}
	if (!init_zombie_animation(data))
	{
		cleanup_textures(data);
		mlx_terminate(data->mlx);
		return (FALSE);
	}
	if (!init_player(data))
	{
		cleanup_animation(&data->zombie_anim);
		cleanup_textures(data);
		mlx_terminate(data->mlx);
		return (FALSE);
	}
	return (TRUE);
}

static void	finalize_game_setup(t_data *data)
{
	init_door_system(data);
	printf("🗺️  Initializing minimap...\n");
	init_minimap(data);
	setup_game_hooks(data);
	data->game_running = TRUE;
	init_key_states(data);
	data->current_time = 0.0;
	printf("🎮 Use WASD to move\n");
	printf("🎮 Mouse to look\n");
	printf("🎮 F to open doors\n");
	printf("🎮 M to toggle minimap\n");
	printf("🎮 ESC to exit\n");
}

int	init_game(t_data *data)
{
	if (!init_mlx(data))
		return (FALSE);
	if (!init_game_components(data))
		return (FALSE);
	finalize_game_setup(data);
	return (TRUE);
}
