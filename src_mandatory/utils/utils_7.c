/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:30:49 by riel-fas          #+#    #+#             */
/*   Updated: 2025/10/28 18:31:46 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static size_t	get_copy_size(size_t old_size, size_t new_size)
{
	if (old_size < new_size)
		return (old_size);
	return (new_size);
}

static void	copy_memory(void *new_ptr, void *old_ptr, size_t copy_size)
{
	size_t	x;

	x = 0;
	while (x < copy_size)
	{
		((unsigned char *)new_ptr)[x] = ((unsigned char *)old_ptr)[x];
		x++;
	}
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	copy_size;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (ptr)
	{
		copy_size = get_copy_size(old_size, new_size);
		copy_memory(new_ptr, ptr, copy_size);
		free(ptr);
	}
	return (new_ptr);
}
