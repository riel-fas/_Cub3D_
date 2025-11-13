/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 21:48:54 by riel-fas          #+#    #+#             */
/*   Updated: 2025/10/29 13:39:25 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	assign_rgb_values(t_color *color, int values[3])
{
	color->r = values[0];
	color->g = values[1];
	color->b = values[2];
}

static int	parse_single_rgb_value(char *rgb_str, int *value)
{
	char	*trimmed;

	trimmed = ft_strtrim(rgb_str);
	if (!trimmed)
		return (FALSE);
	*value = ft_atoi(trimmed);
	free(trimmed);
	if (*value < 0 || *value > 255)
		return (FALSE);
	return (TRUE);
}

static int	validate_rgb_count(char **rgb_split)
{
	int	x;

	x = 0;
	while (rgb_split[x])
		x++;
	return (x == 3);
}

int	parse_rgb_values(char *rgb_str, t_color *color)
{
	char	**rgb_split;
	int		values[3];
	int		x;

	rgb_split = ft_split(rgb_str, ',');
	if (!rgb_split)
		return (FALSE);
	if (!validate_rgb_count(rgb_split))
	{
		free_split(rgb_split);
		return (FALSE);
	}
	x = 0;
	while (x < 3)
	{
		if (!parse_single_rgb_value(rgb_split[x], &values[x]))
		{
			free_split(rgb_split);
			return (FALSE);
		}
		x++;
	}
	assign_rgb_values(color, values);
	free_split(rgb_split);
	return (TRUE);
}
