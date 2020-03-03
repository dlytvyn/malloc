/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 12:29:23 by dlytvyn           #+#    #+#             */
/*   Updated: 2017/11/02 12:29:24 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			is_neg(ssize_t n)
{
    if (n < 0)
        return (1);
    return (0);
}

int			numsize(size_t n)
{
    int		counter;

    counter = 0;
    if (is_neg(n) == 1)
    {
        n = -n;
        counter++;
    }
    if (n == 0)
        counter++;
    while (n > 0)
    {
        n = n / 10;
        counter++;
    }
    return (counter);
}

int			numsize_u(size_t n, int base)
{
    int		counter;

    counter = 0;
    if (n == 0)
        counter++;
    while (n > 0)
    {
        n = n / base;
        counter++;
    }
    return (counter);
}

char		*ft_itoa_base(size_t n, int base)
{
    size_t			num;
    char			*res;
    int				size;

    num = n;
    size = numsize_u(num, base);
    if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
        return (NULL);
    res[size--] = '\0';
    while (size >= 0)
    {
        res[size--] = num % base + (num % base > 9 ? ('a' - 10) : '0');
        num = num / base;
    }
    return (res);
}