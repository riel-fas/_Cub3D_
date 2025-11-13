/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:00:00 by riel-fas          #+#    #+#             */
/*   Updated: 2025/10/28 14:46:23 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static void	allocate_door_states(t_data *data)
{
	int	x;

	data->door_states = malloc(sizeof(char *) * (data->map_height + 1));
	if (!data->door_states)
		error_exit(ERR_MALLOC);
	x = 0;
	while (x < data->map_height)
	{
		data->door_states[x] = malloc(sizeof(char) * (data->map_width + 1));
		if (!data->door_states[x])
		{
			while (--x >= 0)
				free(data->door_states[x]);
			free(data->door_states);
			error_exit(ERR_MALLOC);
		}
		x++;
	}
	data->door_states[x] = NULL;
}

void	init_door_states(t_data *data)
{
	int	y;
	int	x;

	allocate_door_states(data);
	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			data->door_states[y][x] = '0';
			x++;
		}
		data->door_states[y][x] = '\0';
		y++;
	}
}

static int	copy_door_pixels(t_texture *texture, mlx_texture_t *mlx_tex)
{
	int	y;
	int	x;

	y = 0;
	while (y < texture->height)
	{
		texture->pixels[y] = malloc(sizeof(uint32_t) * texture->width);
		if (!texture->pixels[y])
		{
			while (--y >= 0)
				free(texture->pixels[y]);
			free(texture->pixels);
			return (FALSE);
		}
		x = 0;
		while (x < texture->width)
		{
			texture->pixels[y][x] = ((uint32_t *)mlx_tex->pixels)
			[y * texture->width + x];
			x++;
		}
		y++;
	}
	return (TRUE);
}

int	load_door_texture(t_data *data)
{
	mlx_texture_t	*mlx_tex;

	mlx_tex = mlx_load_png("./textures/door/DOOR_4A.PNG");
	if (!mlx_tex)
	{
		printf("⚠️  Warning: Could not load door texture, using fallback\n");
		return (create_fallback_texture(&data->door_texture, 0x8B4513FF));
	}
	data->door_texture.mlx_texture = NULL;
	data->door_texture.width = mlx_tex->width;
	data->door_texture.height = mlx_tex->height;
	data->door_texture.pixels = malloc(sizeof(uint32_t *)
			* data->door_texture.height);
	if (!data->door_texture.pixels)
	{
		mlx_delete_texture(mlx_tex);
		return (FALSE);
	}
	if (!copy_door_pixels(&data->door_texture, mlx_tex))
	{
		mlx_delete_texture(mlx_tex);
		return (FALSE);
	}
	mlx_delete_texture(mlx_tex);
	return (TRUE);
}
