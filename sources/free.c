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

void ft_free(void *ptr)
{
    t_piece *previous;

    previous = NULL;
    if (!ptr)
        return ;
    t_piece *necessary_piece = (t_piece*)ptr - 1;
    necessary_piece->is_free = 1;
//    necessary_piece->area->free_space += necessary_piece->size;

    if (necessary_piece->prev && necessary_piece->prev->is_free)
    {
        previous = necessary_piece->prev;
        previous->size += necessary_piece->size + PIECE_META_BLOCK_SIZE;
        previous->next = necessary_piece->next;
        if (necessary_piece->next)
            necessary_piece->next->prev = previous;
        necessary_piece->area->free_space += necessary_piece->size + PIECE_META_BLOCK_SIZE;
    }
    else
        necessary_piece->area->free_space += necessary_piece->size;
}