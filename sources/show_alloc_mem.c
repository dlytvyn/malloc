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

void	show_memarea_info(t_memarea *memarea)
{
	if (memarea->type == 1)
		ft_printf("TINY : %p\n", (long)memarea->address);
	else if (memarea->type == 2)
		ft_printf("SMALL : %p\n", (long)memarea->address);
	else
		ft_printf("LARGE : %p\n", (long)memarea->address);
}

int		show_piece_info(t_piece *piece)
{
	int		total_bytes;

	total_bytes = 0;
	while (piece)
	{
	    if (piece->free == 0)
        {
            ft_printf("%p - %p : %d bytes\n", (long)piece->address,
                      (long)piece->address + piece->size, (int)piece->size);
            total_bytes += piece->size;
        }
        piece = piece->next;

    }
	return (total_bytes);
}

void	show_alloc_mem(void)
{
	t_memarea	*memarea;
	t_piece		*piece;
	int			total_bytes;

	total_bytes = 0;
	memarea = (t_memarea *)g_memarea;
	while (memarea)
	{
		piece = memarea->pieces;
		show_memarea_info(memarea);
		total_bytes += show_piece_info(piece);
		memarea = memarea->next;
	}
	ft_printf("Total : %d bytes\n",total_bytes);
}
