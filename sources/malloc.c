/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <dlytvyn@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:55:36 by dlytvyn           #+#    #+#             */
/*   Updated: 2019/08/17 12:55:37 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/allocation.h"

t_memarea	*initiate_memarea(t_memarea *memarea, size_t size)
{
	size_t	memarea_total_size;

	if (size <= TINY_SIZE)
		memarea_total_size = TINY_SIZE * 100 + sizeof(t_memarea);
	else if (size <= SMALL_SIZE)
		memarea_total_size = SMALL_SIZE * 100 + sizeof(t_memarea);
	else
		memarea_total_size = size + sizeof(t_memarea);

	if (memarea_total_size % PAGE_SIZE)
		memarea_total_size += PAGE_SIZE - (memarea_total_size % PAGE_SIZE);

    if (MAP_FAILED == (memarea = mem_mapping(memarea, memarea_total_size + PAGE_SIZE)))
        return (NULL);
	memarea->type = get_memory_type(size);
	memarea->total_size = memarea_total_size;
	memarea->free_space = memarea_total_size;
	memarea->pieces = initate_piece((void *)memarea +
		sizeof(t_memarea), size, memarea);
	memarea->address = (void *)memarea;
	memarea->next = NULL;
	return (memarea);
}

t_memarea	*add_memarea(t_memarea *memarea, size_t size)
{
	t_memarea	*tmp_memarea;

	tmp_memarea = memarea;
	while (tmp_memarea->next)
		tmp_memarea = tmp_memarea->next;
	tmp_memarea->next = initiate_memarea(tmp_memarea->next, size);
	tmp_memarea = tmp_memarea->next;
	return (tmp_memarea);
}

t_piece     *check_memarea(t_memarea *memarea, size_t size, int mem_type)
{
    t_piece     *tmp_piece;
    t_memarea   *tmp_memarea;

    tmp_memarea = memarea;
    tmp_piece = tmp_memarea->pieces;
    while (tmp_memarea)
    {
        if (tmp_memarea->type == mem_type)
        {
            while (tmp_piece)
            {
                if (tmp_piece->free && size <= tmp_piece->size && size + sizeof(t_piece) > tmp_piece->size)
                {
                    tmp_piece->size = size;
                    tmp_piece->free = 0;
                    return (tmp_piece);
                }
                if (tmp_piece->free && size + sizeof(t_piece) <= tmp_piece->size)
                    return (add_f(tmp_piece, size, tmp_memarea));
                tmp_piece = tmp_piece->next;
            }
            if (tmp_memarea->free_space >= size + sizeof(t_piece))
                return (add_piece(tmp_memarea, size));
            tmp_memarea = tmp_memarea->next;
        }
        tmp_memarea = tmp_memarea->next;
    }
    tmp_memarea = add_memarea(memarea, size);
    return tmp_memarea->pieces;
}

t_piece		*get_piece(size_t size)
{
	t_memarea	*memarea;
	int			mem_type;

	memarea = (t_memarea *)g_memarea;
	mem_type = get_memory_type(size);
	if (memarea)
        return (check_memarea(memarea, size, mem_type));
	else
	{
		memarea = initiate_memarea(memarea, size);
        memarea->free_space = memarea->free_space - (sizeof(t_piece) + size);
		g_memarea = memarea;
		return (memarea->pieces);
	}
}

void		*malloc(size_t size)
{
	t_piece	*piece;
	size_t	tmp;

	piece = NULL;
	tmp = 0;
	if (!size)
		return (NULL);
	if (size % 4 != 0)
    {
        tmp = size / 4;
        size = tmp * 4 + 4;
    }
	piece = get_piece(size);
	return (piece->address + sizeof(t_piece));
}
