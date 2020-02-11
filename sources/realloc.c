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
            memory = ptr;
        else if ((memory = ft_malloc(size)))
        {
            ft_memcpy(memory, ptr, piece->size);
            ft_free(ptr);
        }
    }
    return (memory);
}

void		*ft_realloc(void *ptr, size_t size)
{
    if (!ptr)
        return ft_malloc(size);
    else if (!size)
    {
        ft_free(ptr);
        ptr = NULL;
    }
    else
    {
        if (is_valid(ptr))
            ptr = realloc_add(ptr, size);
        else
            return NULL;
    }
    return (ptr);
}
