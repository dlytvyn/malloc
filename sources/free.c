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

void	delete_piece(t_piece *piece_to_delete, t_memarea *memarea)
{
	t_piece	*tmp_piece;
	t_piece	*previous;

	tmp_piece = memarea->pieces;
	previous = NULL;
	while (tmp_piece)
	{
		if (tmp_piece == piece_to_delete)
		{
		    tmp_piece->free = 1;
//			if (previous)
//				previous->next = piece_to_delete->next;
//			else
//				memarea->pieces = piece_to_delete->next;
            return ;
		}
		previous = tmp_piece;
		tmp_piece = tmp_piece->next;
	}
}

void	delete_memarea(t_memarea *memarea_to_delete)
{
	t_memarea *tmp_memarea;
	t_memarea *previous;

	tmp_memarea = (t_memarea *)g_memarea;
	previous = NULL;
	while (tmp_memarea)
	{
		if (tmp_memarea == memarea_to_delete)
		{
			if (previous)
				previous->next = memarea_to_delete->next;
			else
				g_memarea = memarea_to_delete->next;
		}
		previous = tmp_memarea;
		tmp_memarea = tmp_memarea->next;
	}
}

#include <stdio.h>

void	free(void *ptr)
{
	t_memarea	*tmp_memarea;
	t_piece		*tmp_piece;

	tmp_memarea = (t_memarea *)g_memarea;
	if (ptr && g_memarea)
	{
		while (tmp_memarea)
		{
			tmp_piece = tmp_memarea->pieces;
			while (tmp_piece && tmp_piece->address != ptr - sizeof(t_piece))
				tmp_piece = tmp_piece->next;
			if (tmp_piece)
			{

				delete_piece(tmp_piece, tmp_memarea);
//				tmp_memarea->free_space += tmp_piece->size + sizeof(t_piece);
//				if (tmp_memarea->free_space == tmp_memarea->total_size)
//				{
//					delete_memarea(tmp_memarea);
//					return ;
//				}
			}
			tmp_memarea = tmp_memarea->next;
		}
	}
}
