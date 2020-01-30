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

# define TINY 1
# define SMALL 2
# define LARGE 3
# define TINY_SIZE 128
# define SMALL_SIZE 1024
# define PAGE_SIZE sysconf(_SC_PAGESIZE)

typedef struct			s_piece
{
	size_t				size;
	void				*address;
	void                *memarea;
    int                 free;
	struct s_piece		*next;
}						t_piece;

typedef struct			s_memarea
{
	int					type;
	size_t				total_size;
	size_t				free_space;
	t_piece				*pieces;
	void				*address;
	struct s_memarea	*next;
}						t_memarea;

void					*malloc(size_t size);
void					free(void *ptr);
void					*realloc(void *ptr, size_t size);
void					show_alloc_mem();
t_piece					*initate_piece(void *address, size_t size, t_memarea *memarea);
t_piece					*add_piece(t_memarea *memarea, size_t size);
int						get_memory_type(size_t size);
void					*mem_mapping(t_memarea *memarea, size_t size);
t_piece		            *add_f(t_piece *piece, size_t size, t_memarea *memarea);
void					*g_memarea;

#endif
