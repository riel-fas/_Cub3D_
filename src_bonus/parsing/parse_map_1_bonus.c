/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 02:58:58 by riel-fas          #+#    #+#             */
/*   Updated: 2025/10/28 15:00:25 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

int	process_map_line_index(t_data *data, int file_index, int *map_index)
{
	char	*trimmed_line;

	trimmed_line = process_map_line(data->file_lines[file_index]);
	if (trimmed_line == (char *)-1)
		return (FALSE);
	if (trimmed_line == NULL)
		return (TRUE);
	if (!add_line_to_map(data, trimmed_line, *map_index))
	{
		free(trimmed_line);
		return (FALSE);
	}
	free(trimmed_line);
	(*map_index)++;
	return (TRUE);
}

int	populate_map_data(t_data *data, int map_start)
{
	int	x;
	int	map_index;

	x = map_start;
	map_index = 0;
	while (x < data->line_count && map_index < data->map_height)
	{
		if (!process_map_line_index(data, x, &map_index))
			return (FALSE);
		x++;
	}
	data->map[map_index] = NULL;
	return (TRUE);
}

int	parse_map(t_data *data)
{
	int	map_start;

	if (!initialize_map_data(data, &map_start))
		return (FALSE);
	if (!allocate_map_memory(data))
		return (FALSE);
	if (!populate_map_data(data, map_start))
		return (FALSE);
	printf("✅ Map parsing completed\n");
	return (TRUE);
}
