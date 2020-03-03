///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   malloc_add.c                                       :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: dlytvyn <dlytvyn@student.unit.ua>          +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2019/08/17 13:13:29 by dlytvyn           #+#    #+#             */
///*   Updated: 2019/08/17 13:13:30 by dlytvyn          ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */

#include "../includes/allocation.h"

t_piece     *create_piece(t_area *area, size_t size)
{
    t_piece *piece;
    void    *mapped_memory;

    if (!(mapped_memory = mmap(NULL, size, PROT_READ | PROT_WRITE,
                               MAP_PRIVATE | MAP_ANONYMOUS, -1, 0)))
        return (NULL);
    piece = (t_piece*)mapped_memory;
    piece->size = size - PIECE_META_BLOCK_SIZE;
    piece->is_free = 1;
    piece->next = NULL;
    if (area->last_piece)
        area->last_piece->next = piece;
    if (!area->first_piece)
        area->first_piece = piece;
    area->last_piece = piece;
    return (piece);
}

t_piece      *create_area(t_area *area, int create)
{
    size_t necessary_size;

    necessary_size = getpagesize() * (area->type);
    necessary_size *= (create ? SIZE_COEFFICIENT : 1);
    return (create_piece(area, necessary_size));
}
