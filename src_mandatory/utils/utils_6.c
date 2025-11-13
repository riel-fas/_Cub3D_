/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:20:23 by riel-fas          #+#    #+#             */
/*   Updated: 2025/10/28 18:31:06 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	skip_whitespace(char *line, int *index)
{
	if (!line || !index)
		return (FALSE);
	while (line[*index] && ft_isspace(line[*index]))
		(*index)++;
	return (TRUE);
}

int	count_words(char *str, char delimiter)
{
	int	count;
	int	in_word;
	int	x;

	count = 0;
	in_word = 0;
	x = 0;
	if (!str)
		return (0);
	while (str[x])
	{
		if (str[x] != delimiter && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (str[x] == delimiter)
			in_word = 0;
		x++;
	}
	return (count);
}

char	*ft_strncpy(char *dest, const char *src, int n)
{
	int	x;

	x = 0;
	while (x < n && src[x])
	{
		dest[x] = src[x];
		x++;
	}
	while (x < n)
	{
		dest[x] = '\0';
		x++;
	}
	return (dest);
}
