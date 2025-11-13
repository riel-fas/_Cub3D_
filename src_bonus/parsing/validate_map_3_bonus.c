/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_3_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 23:34:37 by riel-fas          #+#    #+#             */
/*   Updated: 2025/10/28 16:53:39 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

int	check_horizontal_borders(t_data *data)
{
	int	x;
	int	top_len;
	int	bottom_len;

	top_len = ft_strlen(data->map[0]);
	x = 0;
	while (x < top_len)
	{
		if (data->map[0][x] != WALL && data->map[0][x] != ' ')
			return (FALSE);
		x++;
	}
	bottom_len = ft_strlen(data->map[data->map_height - 1]);
	x = 0;
	while (x < bottom_len)
	{
		if (data->map[data->map_height - 1][x] != WALL &&
			data->map[data->map_height - 1][x] != ' ')
			return (FALSE);
		x++;
	}
	return (TRUE);
}

int	check_vertical_borders(t_data *data)
{
	int	y;
	int	line_len;

	y = 0;
	while (y < data->map_height)
	{
		line_len = ft_strlen(data->map[y]);
		if (line_len == 0)
		{
			y++;
			continue ;
		}
		if (data->map[y][0] != WALL && data->map[y][0] != ' ')
			return (FALSE);
		if (data->map[y][line_len - 1] != WALL &&
			data->map[y][line_len - 1] != ' ')
			return (FALSE);
		y++;
	}
	return (TRUE);
}

int	check_map_borders(t_data *data)
{
	printf("🔒 Checking map borders...\n");
	if (!check_horizontal_borders(data))
		return (FALSE);
	if (!check_vertical_borders(data))
		return (FALSE);
	printf("✅ Map borders are properly closed\n");
	return (TRUE);
}

int	is_space_connecting_to_border(t_data *data, int x, int y)
{
	int	line_len;

	line_len = ft_strlen(data->map[y]);
	if (x == 0 || x == line_len - 1 || y == 0 || y == data->map_height - 1)
	{
		printf("❌ Empty space at border at (%d, %d)\n", x, y);
		return (TRUE);
	}
	if ((x > 0 && data->map[y][x - 1] == ' ')
		|| (x < line_len - 1 && data->map[y][x + 1] == ' ')
		|| (y > 0 && x < (int)ft_strlen(data->map[y - 1])
			&& data->map[y - 1][x] == ' ')
		|| (y < data->map_height - 1 && x < (int)ft_strlen(data->map[y + 1])
			&& data->map[y + 1][x] == ' '))
	{
		if (x <= 1 || x >= line_len - 2 || y <= 1 || y >= data->map_height - 2)
		{
			printf("❌ Empty space at (%d, %d)\n", x, y);
			return (TRUE);
		}
	}
	return (FALSE);
}

int	check_empty_spaces_near_borders(t_data *data)
{
	int	x;
	int	y;
	int	line_len;

	printf("🚧 Checking spaces near borders...\n");
	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		line_len = ft_strlen(data->map[y]);
		while (x < line_len)
		{
			if (data->map[y][x] == EMPTY || is_player_char(data->map[y][x]))
			{
				if (is_space_connecting_to_border(data, x, y))
					return (FALSE);
			}
			x++;
		}
		y++;
	}
	printf("✅ No empty spaces connect to borders\n");
	return (TRUE);
}
