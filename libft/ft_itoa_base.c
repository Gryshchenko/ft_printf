/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:28:03 by vgryshch          #+#    #+#             */
/*   Updated: 2018/02/15 10:21:43 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_value(int *base, long *nb, int *sing, long *length)
{
	if (*base < 2 || *base > 16)
		return (1);
	if (*base != 10 && *nb < 0)
		return (1);
	if (*base == 10 && *nb < 0)
	{
		*sing = -1;
		*nb = -(*nb);
	}
	else
		*sing = 1;
	*length = 1;
	return (0);
}

static int		ft_recursive(long n, long pow)
{
	if (pow == 0)
		return (1);
	return (n * ft_recursive(n, pow - 1));
}

char			*ft_itoa_base(int value, int base)
{
	long		nb;
	long		length;
	char		*result;
	int			sing;
	int			i;

	nb = (long)value;
	if (ft_check_value(&base, &nb, &sing, &length) == 1)
		return ((void*)0);
	while (ft_recursive(base, length) <= nb)
		length++;
	result = (char *)malloc(sizeof(char) * (length + 2));
	i = -1;
	while (++i < length)
	{
		if (base <= 10 || (base > 10 && (nb % base) < 10))
			result[i] = (nb % base) + 48;
		else
			result[i] = (nb % base) - 10 + 65;
		nb /= base;
	}
	if (sing < 0)
		result[i++] = '-';
	result[i] = '\0';
	return (ft_strrev(result));
}
