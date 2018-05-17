/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchartostring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 12:12:38 by vgryshch          #+#    #+#             */
/*   Updated: 2018/02/27 12:54:26 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	*ft_one(wchar_t chr)
{
	unsigned char *a;

	a = (unsigned char *)ft_strnew(1);
	a[0] = chr;
	return (a);
}

unsigned char	*ft_two(wchar_t chr)
{
	unsigned char *a;

	a = (unsigned char *)ft_strnew(2);
	a[0] = (chr >> 6) + 0xC0;
	a[1] = (chr & 0x3F) + 0x80;
	return (a);
}

unsigned char	*ft_three(wchar_t chr)
{
	unsigned char *a;

	a = (unsigned char *)ft_strnew(3);
	a[0] = (chr >> 12) + 0xE0;
	a[1] = ((chr >> 6) & 0x3F) + 0x80;
	a[2] = (chr & 0x3F) + 0x80;
	return (a);
}

unsigned char	*ft_four(wchar_t chr)
{
	unsigned char *a;

	a = (unsigned char *)ft_strnew(4);
	a[0] = (chr >> 18) + 0xF0;
	a[1] = ((chr >> 12) & 0x3F) + 0x80;
	a[2] = ((chr >> 6) & 0x3F) + 0x80;
	a[3] = (chr & 0x3F) + 0x80;
	return (a);
}

unsigned char	*ft_wchartostring(wchar_t chr)
{
	if (chr <= 0x7F || MB_CUR_MAX == 1)
		return (ft_one(chr));
	else if (chr <= 0x7FF)
		return (ft_two(chr));
	else if (chr <= 0xFFFF)
		return (ft_three(chr));
	else if (chr <= 0x10FFFF)
		return (ft_four(chr));
	return (0);
}
