/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:32:39 by riel-fas          #+#    #+#             */
/*   Updated: 2025/10/29 13:47:20 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	load_textures(t_data *data)
{
	int	x;

	x = 0;
	printf("🎨 Loading textures...\n");
	while (x < 4)
	{
		data->textures[x].mlx_texture = NULL;
		data->textures[x].pixels = NULL;
		data->textures[x].width = 0;
		data->textures[x].height = 0;
		x++;
	}
	x = 0;
	while (x < 4)
	{
		if (!load_single_texture(data, x))
		{
			cleanup_textures(data);
			return (FALSE);
		}
		x++;
	}
	printf("✅ All textures loaded successfully\n");
	return (TRUE);
}

static void	cleanup_single_texture(t_texture *texture)
{
	int	x;

	if (texture->pixels)
	{
		x = 0;
		while (x < texture->height)
		{
			if (texture->pixels[x])
				free(texture->pixels[x]);
			x++;
		}
		free(texture->pixels);
		texture->pixels = NULL;
	}
	if (texture->mlx_texture)
	{
		mlx_delete_texture(texture->mlx_texture);
		texture->mlx_texture = NULL;
	}
}

void	cleanup_textures(t_data *data)
{
	int	x;

	x = 0;
	while (x < 4)
	{
		cleanup_single_texture(&data->textures[x]);
		x++;
	}
}

void	init_fallback_texture_properties(t_texture *texture)
{
	texture->width = TEXTURE_SIZE;
	texture->height = TEXTURE_SIZE;
	texture->mlx_texture = NULL;
}

int	allocate_fallback_pixel_arrays(t_texture *texture)
{
	int	x;

	texture->pixels = malloc(sizeof(uint32_t *) * texture->height);
	if (!texture->pixels)
		return (FALSE);
	x = 0;
	while (x < texture->height)
	{
		texture->pixels[x] = malloc(sizeof(uint32_t) * texture->width);
		if (!texture->pixels[x])
		{
			while (--x >= 0)
				free(texture->pixels[x]);
			free(texture->pixels);
			return (FALSE);
		}
		x++;
	}
	return (TRUE);
}
