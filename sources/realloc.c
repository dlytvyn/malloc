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

void		*ft_realloc(void *ptr, size_t size)
{
    void *reallocated_ptr;

    reallocated_ptr = NULL;
    if (!ptr)
        return ft_malloc(size);
    t_piece *piece = (t_piece*)ptr - 1;
    if (piece->size >= size)
        return ptr;
    if (!(reallocated_ptr = ft_malloc(size)))
        return NULL;
    ft_memcpy(reallocated_ptr, ptr, piece->size);
    ft_free(ptr);
    return reallocated_ptr;
}