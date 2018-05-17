/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_16.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 17:11:24 by vgryshch          #+#    #+#             */
/*   Updated: 2018/02/15 17:29:33 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_16(unsigned long long nbr)
{
	char	*result;
	int		bits;
	int		len;
	int		i;
	char	arr[16];

	i = 0;
	bits = ft_counter_bits(nbr);
	len = (bits % 4 == 0) ? (bits / 4) : ((bits / 4) + 1);
	result = ft_strnew(len);
	ft_strcpy(arr, "0123456789abcdef");
	while (i < len)
	{
		result[i] = arr[(nbr % 16)];
		nbr >>= 4;
		i++;
	}
	return (ft_strrev(result));
}
