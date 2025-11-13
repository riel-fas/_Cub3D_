/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_2_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 19:27:25 by riel-fas          #+#    #+#             */
/*   Updated: 2025/10/28 11:03:32 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static void	step_ray_horizontal(t_ray *ray)
{
	ray->side_dist.x += ray->delta_dist.x;
	ray->map_x += ray->step.x;
	ray->side = 0;
}

static void	step_ray_vertical(t_ray *ray)
{
	ray->side_dist.y += ray->delta_dist.y;
	ray->map_y += ray->step.y;
	ray->side = 1;
}

static int	check_hit(t_data *data, t_ray *ray)
{
	if (ray->map_x < 0 || ray->map_x >= data->map_width
		|| ray->map_y < 0 || ray->map_y >= data->map_height)
	{
		return (1);
	}
	if (data->map[ray->map_y][ray->map_x] == '1')
	{
		return (1);
	}
	if (data->map[ray->map_y][ray->map_x] == DOOR
		&& !is_door_open(data, ray->map_x, ray->map_y))
	{
		ray->is_door = 1;
		return (1);
	}
	return (0);
}

void	perform_dda(t_data *data, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
			step_ray_horizontal(ray);
		else
			step_ray_vertical(ray);
		ray->hit = check_hit(data, ray);
	}
}
