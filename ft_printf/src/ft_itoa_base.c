/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:22:55 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/09 11:26:30 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

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

int			help(t_sp *spec)
{
	if (spec->x || spec->p)
		return ('a' - 10);
	else
		return ('A' - 10);
}

char		*ft_ib(size_t n, int base, t_sp *spec)
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
		res[size--] = num % base + (num % base > 9 ? help(spec) : '0');
		num = num / base;
	}
	return (res);
}
