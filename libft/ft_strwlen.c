/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:15:21 by vgryshch          #+#    #+#             */
/*   Updated: 2018/02/27 11:13:07 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strwlen(const wchar_t *s)
{
	size_t	len;
	size_t	strlen;

	len = 0;
	strlen = 0;
	while (s[len] != '\0')
	{
		strlen += ft_wcslen(s[len]);
		len++;
	}
	return (strlen);
}
