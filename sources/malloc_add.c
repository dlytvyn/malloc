/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <dlytvyn@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 13:13:29 by dlytvyn           #+#    #+#             */
/*   Updated: 2019/08/17 13:13:30 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/allocation.h"

void		*mem_mapping(t_memarea *memarea, size_t size)
{
	return (mmap(memarea, size, PROT_READ |
		PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0));
}

int			get_memory_type(size_t size)
{
	if (size <= TINY_SIZE)
		return (TINY);
	else if (size <= SMALL_SIZE)
		return (SMALL);
	else
		return (LARGE);
}

t_piece		*initate_piece(void *address, size_t size, t_memarea *memarea)
{
	t_piece	*piece;

	piece = (t_piece *)address;
	piece->size = size;
	piece->address = address;
	piece->memarea = memarea;
	piece->free = 0;
	piece->next = NULL;
	return (piece);
}

t_piece		*add_f(t_piece *piece, size_t size, t_memarea *memarea)
{
    t_piece	*new_piece;

    new_piece = initate_piece(
            piece->address + piece->size + sizeof(t_piece), size, memarea);
    new_piece->next = piece->next;
    piece->next = new_piece;
    piece->size -= size + sizeof(t_piece);
    return (new_piece->next);

}

t_piece		*add_piece(t_memarea *memarea, size_t size)
{
	t_piece	*piece;

	piece = memarea->pieces;
	if (piece)
    {
        while (piece->next)
            piece = piece->next;
        piece->next = initate_piece(
                piece->address + piece->size + sizeof(t_piece), size, memarea);
        memarea->free_space = memarea->free_space - (sizeof(t_piece) + size);
        return (piece->next);
    }
	else
    {
	    piece = initate_piece(
                memarea->address + sizeof(t_memarea), size, memarea);
        return (piece);
    }
}
