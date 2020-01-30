/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <dlytvyn@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 13:02:42 by dlytvyn           #+#    #+#             */
/*   Updated: 2019/08/17 13:02:43 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/allocation.h"

t_piece		*get_necessary_memarea(void *to_find)
{
	t_memarea	*tmp_memarea;
	t_piece		*tmp_piece;

	tmp_memarea = g_memarea;
	tmp_piece = NULL;
	while (tmp_memarea)
	{
		tmp_piece = tmp_memarea->pieces;
		while (tmp_piece)
		{
			if (tmp_piece->address == to_find - sizeof(t_piece))
				return (tmp_piece);
			tmp_piece = tmp_piece->next;
		}
		tmp_memarea = tmp_memarea->next;
	}
	return (tmp_piece);
}

t_piece     *get_necessary_piece(t_piece *to_find, t_memarea *memarea)
{
    t_piece     *tmp_piece;

    tmp_piece = memarea->pieces;
    while (tmp_piece)
    {
        if (tmp_piece->address == to_find - sizeof(t_piece))
            return (tmp_piece);
        tmp_piece = tmp_piece->next;
    }
    return (NULL);
}

int			is_free_space(t_memarea *memarea, size_t size)
{
	if (memarea->free_space >= size + sizeof(t_piece))
		return (1);
	return (0);
}

void		*reallocate(void *ptr, size_t size, size_t previous_size)
{
	void	*new_ptr;
	size_t	new_size;

	new_size = size <= previous_size ? previous_size : size;
	if ((new_ptr = malloc(size)))
	{
		ft_memmove(new_ptr, ptr, previous_size < new_size ? previous_size : new_size);
		free(ptr);
	}
	return (new_ptr);
}

void		*realloc(void *ptr, size_t size)
{
	t_piece		*piece;
//	t_memarea	*memarea;

	if (!ptr && size != 0)
		return (malloc(size));
	if (!size)
		free(ptr);
	else if ((piece = get_necessary_memarea(ptr)))
	{
//	    piece = get_necessary_piece(ptr, memarea);
		if (piece->size + sizeof(t_piece) >= size ||
			(is_free_space(piece->memarea, size) && !piece->next))
		{
//			memarea->free_space -= size + sizeof(t_piece) - piece->size;
			piece->size = size + sizeof(t_piece);
			return (ptr);
		}
		return (reallocate(ptr, size, piece->size));
	}
	return (NULL);
}
