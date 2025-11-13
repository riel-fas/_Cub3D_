/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 20:40:05 by riel-fas          #+#    #+#             */
/*   Updated: 2025/10/28 17:27:07 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

void	free_split(char **split)
{
	int	x;

	if (!split)
		return ;
	x = 0;
	while (split[x])
	{
		free(split[x]);
		x++;
	}
	free(split);
}

static void	free_texture_paths(t_data *data)
{
	int	x;

	x = 0;
	while (x < 4)
	{
		if (data->texture_paths[x])
		{
			free(data->texture_paths[x]);
			data->texture_paths[x] = NULL;
		}
		x++;
	}
}

static void	free_map_data(t_data *data)
{
	int	x;

	if (data->map)
	{
		x = 0;
		while (x < data->map_height && data->map[x])
		{
			free(data->map[x]);
			x++;
		}
		free(data->map);
		data->map = NULL;
	}
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	free_texture_paths(data);
	free_map_data(data);
	free_door_states(data);
	cleanup_animation(&data->zombie_anim);
	if (data->file_lines)
	{
		free_split(data->file_lines);
		data->file_lines = NULL;
	}
}
