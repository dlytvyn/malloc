/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <dlytvyn@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:18:07 by dlytvyn           #+#    #+#             */
/*   Updated: 2019/08/17 12:18:09 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/allocation.h"

int     is_valid_pointer(void *ptr)
{
    int     i;
    t_area  *area;
    t_piece *piece;
    t_piece *tmp_piece;

    if (ptr)
    {
        i = 0;
        tmp_piece = (t_piece*)(ptr - PIECE_META_BLOCK_SIZE);
        while (i < 3) {
            area = get_area(0) + i;
            piece = area->first_piece;
            while (piece && piece != tmp_piece)
                piece = piece->next;
            if (piece)
                return (1);
            i++;
        }
    }
    return (0);
}

void    add_pieces(t_piece *piece)
{
    t_piece *next;

    piece->is_free = 1;
    next = piece->next;
    while (next && next->is_free)
    {
        piece->size += next->size + PIECE_META_BLOCK_SIZE;
        piece->next = next->next;
        next = piece->next;
    }
}

void    release_piece(t_area *area, t_piece *piece)
{
    t_piece *piece_first;
    t_piece *piece_last;

    if (area->type != LARGE)
        add_pieces(piece);
    else
    {
        piece_first = area->first_piece;
        piece_last = piece_first;
        while (piece_first != piece)
        {
            piece_last = piece_first;
            piece_first = piece_first->next;
        }
        piece_last->next = piece_first->next;
        if (area->last_piece == piece_first)
            area->last_piece = piece_first != piece_last ? piece_last : NULL;
        if (area->first_piece == piece_first)
            area->first_piece = piece_first->next;
        munmap(piece, piece->size + PIECE_META_BLOCK_SIZE);
    }
}

void    free(void *ptr)
{
    t_piece *piece;

    if (is_valid_pointer(ptr))
    {
        piece = (t_piece*)(ptr - PIECE_META_BLOCK_SIZE);
        if (!piece->is_free)
            release_piece(get_area(piece->size), piece);
    }
}
