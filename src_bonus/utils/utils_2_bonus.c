/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 04:05:04 by riel-fas          #+#    #+#             */
/*   Updated: 2025/10/28 17:28:52 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

static int	find_trim_start(char *str)
{
	int	start;

	start = 0;
	while (str[start] && is_whitespace(str[start]))
		start++;
	return (start);
}

static int	find_trim_end(char *str, int start)
{
	int	end;

	end = ft_strlen(str) - 1;
	while (end >= start && is_whitespace(str[end]))
		end--;
	return (end);
}

static char	*create_trimmed_string(char *str, int start, int len)
{
	char	*trimmed;
	int		x;

	if (len <= 0)
	{
		trimmed = malloc(1);
		if (trimmed)
			trimmed[0] = '\0';
		return (trimmed);
	}
	trimmed = malloc(len + 1);
	if (!trimmed)
		return (NULL);
	x = 0;
	while (x < len)
	{
		trimmed[x] = str[start + x];
		x++;
	}
	trimmed[x] = '\0';
	return (trimmed);
}

char	*ft_strtrim(char *str)
{
	int	start;
	int	end;
	int	len;

	if (!str)
		return (NULL);
	start = find_trim_start(str);
	end = find_trim_end(str, start);
	len = end - start + 1;
	return (create_trimmed_string(str, start, len));
}
