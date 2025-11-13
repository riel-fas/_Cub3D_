/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_5_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:28:34 by riel-fas          #+#    #+#             */
/*   Updated: 2025/10/28 14:40:38 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

int	allocate_animation_frames(t_animation *anim)
{
	int	x;

	printf("🎬 Loading %d animation frames...\n", anim->frame_count);
	anim->frames = malloc(sizeof(t_anim_frame) * anim->frame_count);
	if (!anim->frames)
	{
		printf("❌ Failed to allocate memory for animation frames\n");
		return (FALSE);
	}
	x = 0;
	while (x < anim->frame_count)
	{
		anim->frames[x].texture.mlx_texture = NULL;
		anim->frames[x].texture.pixels = NULL;
		anim->frames[x].texture.width = 0;
		anim->frames[x].texture.height = 0;
		anim->frames[x].frame_number = 0;
		x++;
	}
	return (TRUE);
}

void	cleanup_partial_frames(t_animation *anim, int loaded_count)
{
	int	x;

	x = 0;
	while (x < loaded_count)
	{
		cleanup_frame_texture(&anim->frames[x].texture);
		x++;
	}
	free(anim->frames);
	anim->frames = NULL;
}

int	load_all_frames(t_animation *anim)
{
	int	x;

	x = 0;
	while (x < anim->frame_count)
	{
		if (!load_single_frame(anim, x))
		{
			cleanup_partial_frames(anim, x);
			return (FALSE);
		}
		x++;
	}
	return (TRUE);
}
