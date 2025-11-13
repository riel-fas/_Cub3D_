/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:31:20 by riel-fas          #+#    #+#             */
/*   Updated: 2025/10/28 17:33:24 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

int	ft_strlen(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *str)
{
	char	*dup;
	int		len;
	int		x;

	len = ft_strlen(str);
	dup = malloc(len + 1);
	if (!str)
		return (NULL);
	if (!dup)
		return (NULL);
	x = 0;
	while (x < len)
	{
		dup[x] = str[x];
		x++;
	}
	dup[x] = '\0';
	return (dup);
}

char	*ft_strcat(char *dest, const char *src)
{
	int	x;
	int	y;

	if (!dest || !src)
		return (dest);
	x = 0;
	while (dest[x])
		x++;
	y = 0;
	while (src[y])
	{
		dest[x + y] = src[y];
		y++;
	}
	dest[x + y] = '\0';
	return (dest);
}
