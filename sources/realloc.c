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

void        *realloc_add(void *ptr, size_t size)
{
    t_piece *piece;
    void    *memory;

    memory = NULL;
    piece = (t_piece*)(ptr - PIECE_META_BLOCK_SIZE);
    if (!piece->is_free)
    {
        if (piece->size >= size)
            return (ptr);
        else if ((memory = malloc(size)))
        {
            ft_memcpy(memory, ptr, piece->size);
            free(ptr);
        }
    }
    return (memory);
}

void		*realloc(void *ptr, size_t size)
{
    if (!ptr)
        return malloc(size);
    else if (!size)
    {
        free(ptr);
        ptr = NULL;
    }
    else
    {
        if (is_valid_pointer(ptr))
            ptr = realloc_add(ptr, size);
        else
            return NULL;
    }
    return (ptr);
}
