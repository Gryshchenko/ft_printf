/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:37:17 by vgryshch          #+#    #+#             */
/*   Updated: 2018/02/27 11:11:00 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int					ft_counter(unsigned long long *n)
{
	unsigned long long		tmp;
	unsigned long long		counter;

	counter = 1;
	tmp = *n;
	while (tmp /= 10)
		counter++;
	return (counter);
}

char						*ft_itoa_unsigned_long(unsigned long long n)
{
	unsigned long long		len;
	char					*newstr;

	len = ft_counter(&n);
	if (!(newstr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	newstr[len] = '\0';
	while (len--)
	{
		newstr[len] = n % 10 + '0';
		n = n / 10;
	}
	return (newstr);
}
