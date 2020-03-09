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

void    print_piece_address(t_piece *piece)
{
    char *start;
    char *end;

    start = ft_itoa_base((uint64_t)(void*)piece + PIECE_META_BLOCK_SIZE, 16);
    end = ft_itoa_base((uint64_t)(void*)piece + PIECE_META_BLOCK_SIZE + piece->size, 16);
    ft_putstr("0x");
    ft_putstr(start);
    ft_putstr(" - ");
    ft_putstr("0x");
    ft_putstr(end);
    ft_putstr(" : ");
    ft_putnbr(piece->size);
    ft_putendl(" bytes.");
    free(start);
    free(end);
}

void    area_type_name(int area_index)
{
    if (area_index == TINY)
        ft_putstr("TINY");
    else if (area_index == SMALL)
        ft_putstr("SMALL");
    else
        ft_putstr("LARGE");
}

int		show_area_info(int area_index)
{
	size_t		total_bytes;
    t_area      *area;
    t_piece     *piece;
    char        *adress;

	total_bytes = 0;
	area = get_area(0) + area_index;
	piece = area->first_piece;
	area_type_name(area_index);
    adress = ft_itoa_base((uint64_t)(void*)area + AREA_META_BLOCK_SIZE, 16);
	ft_putstr(" : 0x");
    ft_putendl(adress);
    free(adress);
    if (area->first_piece && area->first_piece->is_free)
        ft_putendl("Area start : Not allocated.");
	while (piece)
	{
	    if (!piece->is_free)
        {
            print_piece_address(piece);
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
	ft_putstr("Total : ");
	ft_putnbr(total_bytes);
	ft_putstr(" bytes.\n");
}
