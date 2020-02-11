/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <dlytvyn@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 13:04:58 by dlytvyn           #+#    #+#             */
/*   Updated: 2019/08/17 13:04:59 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/allocation.h"

char    *area_type_name(int area_index)
{
    if (area_index == TINY)
        return ("TINY");
    else if (area_index == SMALL)
        return ("SMALL");
    else
        return ("LARGE");
}

int		show_area_info(int area_index)
{
	size_t		total_bytes;
    t_area      *area;
    t_piece     *piece;

	total_bytes = 0;
	area = get_area(0) + area_index;
	piece = area->first_piece;
//	if (area->first_piece)
//    	ft_printf("Area start : %p", area->first_piece);
//    else
//        ft_printf("Area start : Not allocated.");
	while (piece)
	{
	    if (!piece->is_free)
        {
            ft_printf("%p - %p : %d bytes.", (void*)piece + PIECE_META_BLOCK_SIZE,
                      (void*)piece + PIECE_META_BLOCK_SIZE + piece->size, piece->size);
            total_bytes += piece->size;
        }
        piece = piece->next;
    }
	return (total_bytes);
}

void	show_alloc_mem(void)
{
	int		i;
	size_t	total_bytes;

	i = 0;
	total_bytes = 0;
	while (i < 3)
	{
		total_bytes += show_area_info(i);
		i++;
	}
	ft_printf("Total : %d bytes\n",total_bytes);
}
