/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:37:17 by vgryshch          #+#    #+#             */
/*   Updated: 2018/02/27 15:42:17 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long		ft_counter(long long *n, long long *negative)
{
	long long			tmp;
	long long			counter;

	tmp = *n;
	counter = 1;
	if (*n < 0)
	{
		*n = *n * -1;
		*negative = 1;
		counter++;
	}
	while (tmp /= 10)
		counter++;
	return (counter);
}

char					*ft_itoa_long(long long n)
{
	long long			len;
	unsigned long long	tmp;
	long long			negative;
	char				*newstr;

	negative = 0;
	tmp = n;
	len = ft_counter(&n, &negative);
	if (tmp == -9223372036854775808U)
		return (ft_strdup("-9223372036854775808"));
	if (!(newstr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	newstr[len] = '\0';
	while (len--)
	{
		newstr[len] = n % 10 + '0';
		n = n / 10;
	}
	if (negative)
		newstr[0] = '-';
	return (newstr);
}
