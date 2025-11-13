/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 03:37:37 by riel-fas          #+#    #+#             */
/*   Updated: 2025/10/28 17:28:08 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

int	count_words_internal(char *str, char delimiter)
{
	int	count;
	int	in_word;
	int	x;

	count = 0;
	in_word = 0;
	x = 0;
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

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\f' || c == '\v');
}

char	*ft_strchr(char *str, char c)
{
	int	x;

	x = 0;
	if (!str)
		return (NULL);
	while (str[x])
	{
		if (str[x] == c)
			return (&str[x]);
		x++;
	}
	if (c == '\0')
		return (&str[x]);
	return (NULL);
}
