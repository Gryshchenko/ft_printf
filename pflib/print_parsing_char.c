/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parsing_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 11:25:09 by vgryshch          #+#    #+#             */
/*   Updated: 2018/02/27 14:07:24 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				print_w_c_zs(t_flags *flags, char **newstr, int width)
{
	int				i;

	i = 0;
	if (flags->null && !flags->minus)
	{
		while (i < width)
		{
			(*newstr)[i] = '0';
			i++;
		}
	}
	else
	{
		while (i < width)
		{
			(*newstr)[i] = ' ';
			i++;
		}
	}
}

void				print_width_char(t_flags *flags, char **str)
{
	size_t			width;
	char			*newstr;
	char			*temp;

	if ((size_t)flags->width)
	{
		width = flags->width - 1;
		newstr = ft_strnew(width);
		print_w_c_zs(flags, &newstr, width);
		temp = *str;
		*str = ft_strjoin(newstr, temp);
		ft_strdel(&newstr);
		ft_strdel(&temp);
	}
}

void				flag_minus_char(t_flags *flags, char **str)
{
	char			*newstr;
	char			*del;
	size_t			len;
	size_t			i;

	i = 0;
	len = 0;
	if (flags->minus == 1)
	{
		del = *str;
		while (**str == ' ')
		{
			len++;
			*str += 1;
		}
		newstr = ft_strnew(len);
		while (i < len)
		{
			newstr[i] = ' ';
			i++;
		}
		*str = ft_strjoin(*str, newstr);
		ft_strdel(&newstr);
		ft_strdel(&del);
	}
}
