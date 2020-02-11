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

t_piece		*create_piece(t_piece *pieces_head, size_t size, t_area *area)
{
    t_piece	*piece;
    t_piece *current;

    current = pieces_head;
    if (current)
        while (current->next)
            current = current->next;
    ft_putstr("it is somewhere here\n");
    if (!current)
        piece = (t_piece*)(area + 1);
    else
        piece = (t_piece*)((current + 1) + current->size);
    ft_putstr("it is somewhere in the middle\n");
    if (!piece)
        ft_putstr("in if\n");
    else
        ft_putstr("in else\n");
    piece->size = size;
    ft_putstr("it is somewhere here in the middle 2\n");
    piece->is_free = 0;
    piece->area = area;
    piece->next = NULL;
    piece->prev = NULL;
    ft_putstr(" after somewhere here\n");
    printf("Size %d\n", piece->size);
    printf("Area free space %d\n", piece->area->free_space);

    if (current)
    {
        current->next = piece;
        piece->prev = current;
    }
    if (!area->pieces)
        area->pieces = piece;
    return piece;
}


t_piece		*search_free_piece(t_piece *last_piece, size_t size)
{
    t_piece *current;

    current = last_piece;
    while (current && !(current->is_free && current->size >= size))
    {
//        *last_piece = current;
        current = current->next;
    }
    return current;
}

t_area		*create_area(t_area *current, size_t size, int type)
{
    t_area	*area;
//    t_area	*area_check;

//    if (!current)
//        area = sbrk(0);
//    else
//    area = sbrk(size + AREA_META_BLOCK_SIZE);
//    if (area_check == (void*) - 1)
//        return NULL;
    if (current)
        area = mmap(current + 1 + current->total_size, size + AREA_META_BLOCK_SIZE, PROT_READ |
                               PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    else
        area = mmap(NULL, size + AREA_META_BLOCK_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (current)
        current->next = area;
    area->total_size = size;
    area->free_space = size;
    area->pieces = NULL;
    area->type = type;
    area->next =NULL;
    return area;  // hz about this
}

int         get_area_type(size_t size)
{
    int type;

    if (size <= TINY_SIZE)
        type = TINY;
    else if (size <= SMALL_SIZE)
        type = SMALL;
    else
        type = LARGE;
    return type;
}

t_area		*search_free_area(t_area **last_area, size_t size, int type)
{
    t_area *current;

    current = g_pointer;
    while (current && (current->free_space < size + PIECE_META_BLOCK_SIZE || current->type != type))
    {
        *last_area = current;
        current = current->next;
    }
    return current;
}

t_area  *area_creation_manager(t_area *current, size_t size)
{
    int     type;
    size_t  area_size;

    if (size <= TINY_SIZE)
    {
        type = TINY;
        area_size = (TINY_SIZE + PIECE_META_BLOCK_SIZE) * SIZE_COEFFICIENT;
    }
    else if (size <= SMALL_SIZE)
    {
        type = SMALL;
        area_size = (SMALL_SIZE + PIECE_META_BLOCK_SIZE) * SIZE_COEFFICIENT;
    }
    else
    {
        type = LARGE;
        area_size = size + PIECE_META_BLOCK_SIZE;
    }
    return create_area(current, area_size, type);
}

void		*ft_malloc(size_t size)
{
	t_piece	*piece;
	t_area  *area;
	t_area	*current_area;


	if (size == 455)
	    printf("kkk");
    current_area = (t_area*)g_pointer;
	if (!size)
		return (NULL);
	if (!current_area)
    {
	    if (!(area = area_creation_manager(current_area, size)))
            return NULL;
	    g_pointer = area;
	    piece = create_piece(NULL, size, area);
        area->free_space -= size + PIECE_META_BLOCK_SIZE;
    }
	else
    {
	    area = search_free_area(&current_area, size, get_area_type(size));
	    if (!area)
        {
            if (!(area = area_creation_manager(current_area, size)))
                return NULL;
        }
        if (!(piece = search_free_piece(area->pieces, size)))
        {
            piece = create_piece(area->pieces, size, area);
            area->free_space -= size + PIECE_META_BLOCK_SIZE;

        }
        else
        {
            printf("Fuck off creation\n");
            piece->is_free = 0;
            piece->size = size;
            area->free_space -= size;
        }
    }
	printf("Finishing MALLOC\n");
	return (piece + 1);
}






//int main( int argc, const char* argv[] )
//{
//    char *array[100];
//    char *text;
//
//    int i = 1;
//    while (i < 101)
//    {
//        array[i - 1] = ft_malloc(i * 5);
//        ft_memset(array[i - 1], 'a', i * 5 - 1);
//        array[i - 1][i * 5 - 1] = '\n';
//        array[i - 1][i * 5] = '\0';
//        ft_putstr(array[i - 1]);
//        i++;
//    }
//    i = 0;
//    while (i < 100)
//    {
//        ft_free(array[i]);
//        i++;
//    }
//
//
//    i = 1;
//    while (i < 101)
//    {
//        array[i - 1] = ft_malloc(i * 5);
//        ft_memset(array[i - 1], 'a', i * 5 - 1);
//        array[i - 1][i * 5 - 1] = '\n';
//        array[i - 1][i * 5] = '\0';
//        ft_putstr(array[i - 1]);
//        i++;
//    }
//    i = 0;
//    while (i < 100)
//    {
//        ft_free(array[i]);
//        i++;
//    }
//
//
//    return 0;
//}

//int main()
//{
//    char *addr;
//
//    addr = ft_malloc(16);
//    ft_free(NULL);
//    ft_free((void *)addr + 5);
//    if (ft_realloc((void *)addr + 5, 10) == NULL)
//        ft_putstr("Bonjour\n");
//}