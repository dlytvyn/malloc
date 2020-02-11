/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <dlytvyn@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 13:20:28 by dlytvyn           #+#    #+#             */
/*   Updated: 2019/08/17 13:20:29 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATION_H
# define ALLOCATION_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <sys/mman.h>
# include "../ft_printf/src/print.h"

# define SIZE_COEFFICIENT 100
# define TINY 1
# define SMALL 2
# define LARGE 3
# define TINY_SIZE 1024
# define SMALL_SIZE 8192
# define PIECE_META_BLOCK_SIZE sizeof(struct s_piece)
# define AREA_META_BLOCK_SIZE sizeof(struct s_area)

typedef struct			s_piece
{
	size_t				size;
    int                 is_free;
//    struct s_area       *area;
	struct s_piece		*next;
//	struct s_piece		*prev;
}						t_piece;

typedef struct			s_area
{
	int					type;
	size_t				total_size;
	t_piece				*first_piece;
	t_piece				*last_piece;
	struct s_area	    *next;
}						t_area;

void					*ft_malloc(size_t size);
void					ft_free(void *ptr);
void					*ft_realloc(void *ptr, size_t size);
t_area                  *get_area(size_t size);
int                     is_valid(void *ptr);
void					show_alloc_mem();
//t_piece					*initate_piece(void *address, size_t size, t_area *memarea);
//t_piece					*add_piece(t_area *memarea, size_t size);
//int						get_memory_type(size_t size);
//void					*mem_mapping(t_area *memarea, size_t size);
//t_piece		            *add_f(t_piece *piece, size_t size, t_area *memarea);
void					*g_pointer;

#endif
