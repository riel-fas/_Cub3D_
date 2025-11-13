/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 04:06:26 by riel-fas          #+#    #+#             */
/*   Updated: 2025/10/28 17:30:30 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	x;

	x = 0;
	if (!s1 || !s2 || n == 0)
		return (0);
	while (x < n && s1[x] && s2[x] && s1[x] == s2[x])
		x++;
	if (x == n)
		return (0);
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;
	int	x;

	result = 0;
	sign = 1;
	if (!str)
		return (0);
	x = 0;
	while (str[x] && (str[x] == ' ' || str[x] == '\t'))
		x++;
	if (str[x] == '-')
	{
		sign = -1;
		x++;
	}
	else if (str[x] == '+')
		x++;
	while (str[x] && ft_isdigit(str[x]))
	{
		result = result * 10 + (str[x] - '0');
		x++;
	}
	return (result * sign);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			x;

	ptr = (unsigned char *)s;
	x = 0;
	while (x < n)
	{
		ptr[x] = (unsigned char)c;
		x++;
	}
	return (s);
}
