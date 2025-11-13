/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:03:51 by riel-fas          #+#    #+#             */
/*   Updated: 2025/10/28 14:52:38 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static int	allocate_pixel_arrays(t_texture *texture)
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
			texture->pixels = NULL;
			return (FALSE);
		}
		x++;
	}
	return (TRUE);
}

static void	convert_pixel_row(t_texture *texture, int y)
{
	int	x;
	int	index;

	x = 0;
	while (x < texture->width)
	{
		index = (y * texture->width + x) * 4;
		texture->pixels[y][x] = 
			(texture->mlx_texture->pixels[index] << 24) 
			| (texture->mlx_texture->pixels[index + 1] << 16) 
			| (texture->mlx_texture->pixels[index + 2] << 8) 
			| texture->mlx_texture->pixels[index + 3];
		x++;
	}
}

void	convert_texture_pixels(t_texture *texture)
{
	int	x;

	if (!allocate_pixel_arrays(texture))
		return ;
	x = 0;
	while (x < texture->height)
	{
		convert_pixel_row(texture, x);
		x++;
	}
}
