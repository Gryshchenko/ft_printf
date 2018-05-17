/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 17:44:13 by vgryshch          #+#    #+#             */
/*   Updated: 2018/02/27 11:07:52 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base_8(unsigned long long nbr)
{
	char	*result;
	int		bits;
	int		len;
	int		i;

	i = 0;
	bits = ft_counter_bits(nbr);
	len = (bits % 3 == 0) ? (bits / 3) : ((bits / 3) + 1);
	result = ft_strnew(len);
	while (i < len)
	{
		result[i] = (nbr & 7) + '0';
		nbr >>= 3;
		i++;
	}
	return (ft_strrev(result));
}
