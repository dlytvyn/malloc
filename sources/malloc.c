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

int         get_area_type(size_t size)
{
    if (size < TINY_SIZE)
        return (TINY - 1);
    else if (size < SMALL_SIZE)
        return (SMALL - 1);
    else
        return (LARGE - 1);
}

//static int		check_size(const size_t size)
//{
//    struct rlimit limit;
//
//    if (size == 0)
//        return (0);
//    else if (getrlimit(RLIMIT_AS, &limit) == -1 || limit.rlim_cur < size)
//        return (0);
//    else if (getrlimit(RLIMIT_DATA, &limit) == -1 || limit.rlim_cur < size)
//        return (0);
//    else
//        return (1);
//}

t_piece     *create_piece(t_area *area, size_t size)
{
    t_piece *piece;
    void    *mapped_memory;

//    if (!check_size(size))
//        return (NULL);
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

t_area      *get_area(size_t size)
{
    static  t_area areas[3] = {
            {TINY, NULL, NULL, NULL},
            {SMALL, NULL, NULL, NULL},
            {LARGE, NULL, NULL, NULL}
    };

    if (!areas[0].first_piece)
        create_area(&areas[0], 1);
    if (!areas[1].first_piece)
        create_area(&areas[1], 1);
    return (areas + get_area_type(size));
}


void        devide_piece(t_piece *piece, size_t size)
{
    t_piece *new_piece;
    size_t  specified_value;

    specified_value = size + PIECE_META_BLOCK_SIZE * 2;
    if (piece->size >= specified_value)
    {
        new_piece = (void*)piece + specified_value;
        new_piece->size = piece->size - specified_value;
        new_piece->is_free = 1;
        new_piece->next = piece->next;
        piece->size = size;
        piece->next = new_piece;
    }
}

t_piece     *get_piece(size_t size)
{
    t_area  *area;
    t_piece *piece;

    area = get_area(size);
    if (area->type == LARGE)
        return (create_piece(area, size));
    piece = area->first_piece;
    while (piece && !(piece->is_free && piece->size >= size))
        piece = piece->next;
    if (!piece)
        piece = create_area(area, 0);
    if (piece->size > size)
        devide_piece(piece, size);
    return piece;
}

void		*ft_malloc(size_t size)
{
    t_piece *piece;

    if (!size)
        return (NULL);

    piece = get_piece(size);
    if (piece) {
        piece->is_free = 0;
        return ((void *) piece + PIECE_META_BLOCK_SIZE);
    }
    else
        return (NULL);
}