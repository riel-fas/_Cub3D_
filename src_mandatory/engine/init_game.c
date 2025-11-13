/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:08:54 by riel-fas          #+#    #+#             */
/*   Updated: 2025/10/28 11:08:59 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

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
}

static int	init_game_components(t_data *data)
{
	if (!load_textures(data))
	{
		mlx_terminate(data->mlx);
		return (FALSE);
	}
	if (!init_player(data))
	{
		cleanup_textures(data);
		mlx_terminate(data->mlx);
		return (FALSE);
	}
	return (TRUE);
}

static void	finalize_game_setup(t_data *data)
{
	setup_game_hooks(data);
	data->game_running = TRUE;
	init_key_states(data);
	printf("🎮 Use WASD to move\n");
	printf("🎮 Arrow keys to rotate\n");
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
