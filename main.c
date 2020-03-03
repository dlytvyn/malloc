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
#define SIZE 370

int	test1(void)
{
//	system("leaks malloc-final-printf");
	char a[SIZE + 1];
	char *ptr;

	ft_putstr("\n================== TEST - 1 =======================\n");
	ft_memset(a, 'A', SIZE);
	a[SIZE] = 0;
	ptr = malloc(SIZE + 1);
	ft_strcpy(ptr, a);
	free(ptr);
	ptr = malloc(SIZE + 1);
	show_alloc_mem();
	ft_memset(a, 'B', SIZE);
	a[SIZE] = 0;
	ptr = realloc(ptr, 2 * SIZE);
	ft_strcat(ptr, a);
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
	while (i < 50)
	{
        if (i == 90)
            ft_putstr("FOUND\n");
		a[i] = malloc(i * 32 + 7);
		ft_memset(a[i], 'a', i * 32 + 6);
		i++;
	}


	show_alloc_mem();
	i = 0;
	while (i < 50)
	{
		free(a[i]);
		i++;
	}
//    printf("after free spacdrgehrscter6hyrty6e\n");

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

int test5(void)
{
    int i;
    char *addr;

    ft_putstr("\n================== TEST - 5 =======================\n");
    i = 0;
    while (i < 1024)
    {
        addr = (char*)malloc(1024);
        addr[0] = 42;
        i++;
    }
    return (0);
}

int test6(void)
{
    int i;
    char *addr;

    ft_putstr("\n================== TEST - 6 =======================\n");

    i = 0;
    while (i < 1024)
    {
        addr = (char*)malloc(1024);
        addr[0] = 42;
        free(addr);
        i++;
    }
    return (0);
}

int test7()
{
    char *addr1;
    char *addr3;

    ft_putstr("\n================== TEST - 7 =======================\n");

    int M = 10;

    addr1 = (char*)malloc(16*M);
    strcpy(addr1, "Bonjour\n");
    ft_putstr(addr1);
    addr3 = (char*)realloc(addr1, 128*M);
    addr3[127*M] = 42;
    ft_putstr(addr3);
    return (0);
}

int test8()
{
    char *addr1;
    char *addr2;
    char *addr3;

    int M = 16;

    ft_putstr("\n================== TEST - 8 =======================\n");
    addr1 = (char*)malloc(16*M);
    strcpy(addr1, "Bonjour\n");
    ft_putstr(addr1);
    addr2 = (char*)malloc(16*M);
    addr3 = (char*)realloc(addr1, 128*M);
    addr3[127*M] = 42;
    ft_putstr(addr3);
    return (0);
}

int test9()
{
    char *addr;

    ft_putstr("\n================== TEST - 9 =======================\n");
    addr = malloc(16);
    free(NULL);
    free((void *)addr + 5);
    if (realloc((void *)addr + 5, 10) == NULL)
        ft_putstr("Bonjour\n");
    return (0);
}

int test10()
{
    ft_putstr("\n================== TEST - 10 =======================\n");

    malloc(1024);
    malloc(1024 * 32);
    malloc(1024 * 1024);
    malloc(1024 * 1024 * 16);
    malloc(1024 * 1024 * 128);
    show_alloc_mem();
    return (0);
}


int	main(void)
{
//	test1();
//	test2();
//	test3();
//	test4();
//	test5();
//	test6();
//	test7();
//	test8();
//	test9();
	test10();
	return (0);
}
