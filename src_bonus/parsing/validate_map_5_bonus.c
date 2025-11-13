/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_5_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:10:00 by riel-fas          #+#    #+#             */
/*   Updated: 2025/10/28 17:18:44 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

int	check_directions_ver(t_data *data, int x, int y)
{
	if (y - 1 >= 0 && x >= (int)ft_strlen(data->map[y - 1]))
		return (FALSE);
	else if (y + 1 < data->map_height
		&& x >= (int)ft_strlen(data->map[y + 1]))
		return (FALSE);
	else if (y - 1 >= 0
		&& x < (int)ft_strlen(data->map[y - 1])
		&& data->map[y - 1][x] != '0'
		&& data->map[y - 1][x] != '1'
		&& data->map[y - 1][x] != DOOR
		&& !is_player_char(data->map[y - 1][x]))
		return (FALSE);
	else if (y + 1 < data->map_height
		&& x < (int)ft_strlen(data->map[y + 1])
		&& data->map[y + 1][x] != '0'
		&& data->map[y + 1][x] != '1'
		&& data->map[y + 1][x] != DOOR
		&& !is_player_char(data->map[y + 1][x]))
		return (FALSE);
	else if (y + 1 == data->map_height || y - 1 < 0)
		return (FALSE);
	return (TRUE);
}

int	check_directions_hor(t_data *data, int x, int y)
{
	int	line_len;

	line_len = ft_strlen(data->map[y]);
	if (x - 1 >= 0 && data->map[y][x - 1] != '0'
		&& data->map[y][x - 1] != '1'
		&& data->map[y][x - 1] != DOOR
		&& !is_player_char(data->map[y][x - 1]))
		return (FALSE);
	else if (x + 1 < line_len
		&& data->map[y][x + 1] != '0'
		&& data->map[y][x + 1] != '1'
		&& data->map[y][x + 1] != DOOR
		&& !is_player_char(data->map[y][x + 1]))
		return (FALSE);
	else if (x + 1 == line_len)
		return (FALSE);
	return (TRUE);
}

int	check_line(t_data *data, int y)
{
	int	x;
	int	line_len;

	x = 0;
	line_len = ft_strlen(data->map[y]);
	while (x < line_len)
	{
		if ((y == 0 || x == 0)
			&& (data->map[y][x] == '0' || is_player_char(data->map[y][x])
				|| data->map[y][x] == DOOR))
			return (FALSE);
		if (data->map[y][x] == '1' || data->map[y][x] == ' ')
			x++;
		else
		{
			if (!check_directions_hor(data, x, y))
				return (FALSE);
			else if (!check_directions_ver(data, x, y))
				return (FALSE);
			else
				x++;
		}
	}
	return (TRUE);
}

int	validate_map_boundaries(t_data *data)
{
	int	x;

	x = 0;
	printf("🧱 Validating map boundaries (reference-style)...\n");
	while (x < data->map_height)
	{
		if (!check_line(data, x))
		{
			printf("❌ Map boundary validation failed at line %d\n", x);
			return (FALSE);
		}
		x++;
	}
	printf("✅ Map boundaries are valid\n");
	return (TRUE);
}
