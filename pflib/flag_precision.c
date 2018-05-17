/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:04:06 by vgryshch          #+#    #+#             */
/*   Updated: 2018/02/27 14:01:32 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	precision_no_minus(char ***str, char **newstr)
{
	if (ft_strchr(**str, '-') != (void*)0)
	{
		(*newstr)[0] = '-';
		***str = '0';
	}
}

void		print_precision(t_flags *flags, char **str)
{
	size_t	precision;
	char	*newstr;
	char	*temp;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(*str);
	if (ft_strchr(*str, '-') != (void*)0)
		len--;
	if ((size_t)flags->precision > len)
	{
		precision = flags->precision - len;
		newstr = ft_strnew(precision);
		while (i < precision)
		{
			newstr[i] = '0';
			i++;
		}
		temp = *str;
		precision_no_minus(&str, &newstr);
		*str = ft_strjoin(newstr, temp);
		ft_strdel(&newstr);
		ft_strdel(&temp);
	}
}
