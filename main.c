/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <dlytvyn@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:26:08 by dlytvyn           #+#    #+#             */
/*   Updated: 2019/08/17 12:26:09 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/allocation.h"
#define SIZE 370000

int	test1(void)
{
//	system("leaks malloc-final-printf");
	char a[SIZE + 1];
	char *ptr;

	ft_putstr("\n================== TEST - 1 =======================\n");
	memset(a, 'A', SIZE);
	a[SIZE] = 0;
	ptr = malloc(SIZE + 1);
	strcpy(ptr, a);
	free(ptr);
	ptr = malloc(SIZE + 1);
	show_alloc_mem();
	memset(a, 'B', SIZE);
	a[SIZE] = 0;
	ptr = realloc(ptr, 2 * SIZE);
	strcat(ptr, a);
	show_alloc_mem();
	free(ptr);
	return (0);
}

int	test2(void)
{
	char	*a[100];
	int		i;

	ft_putstr("\n================== TEST - 2 =======================\n");
	i = 0;
	while (i < 100)
	{
		a[i] = malloc(i * 32 + 7);
		ft_memset(a[i], 'a', i * 32 + 6);
		i++;
	}
	show_alloc_mem();
	i = 0;
	while (i < 100)
	{
		free(a[i]);
		i++;
	}
	return (0);
}

int	test3(void)
{
	char *str;
	char *str1;
	char *str2;
	char *str3;

	ft_putstr("\n================== TEST - 3 =======================\n");
	str = malloc(sizeof(char) * 550);
	str1 = malloc(sizeof(char) * 1603);
	str2 = malloc(sizeof(char) * 2323);
	free(str2);
	str3 = malloc(sizeof(char) * 2342343);
	str1 = realloc(str2, 2040);
	show_alloc_mem();
	free(str);
	free(str1);
	free(str3);
	return (0);
}

int	test4(void)
{
	char a[SIZE + 1];
	char *ptr;

	ft_putstr("\n================== TEST - 4 =======================\n");
	memset(a, 'A', SIZE);
	a[SIZE] = 0;
	ptr = malloc(SIZE + 1);
	strcpy(ptr, a);
	show_alloc_mem();
	free(ptr);
	ptr = malloc(SIZE + 1);
	memset(a, 'B', SIZE);
	a[SIZE] = 0;
	ptr = realloc(ptr, 2 * SIZE);
	strcat(ptr, a);
	show_alloc_mem();
	free(ptr);
	return (0);
}

int	main(void)
{
	test1();
	test2();
	test3();
	test4();
	return (0);
}
