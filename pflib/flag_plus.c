/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_plus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 09:18:23 by vgryshch          #+#    #+#             */
/*   Updated: 2018/02/27 10:24:07 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		flag_plus_char(t_flags *flags, char **str)
{
	char	*newstr;
	char	*temp;

	if (flags->plus == 1 && **str == '0')
	{
		newstr = ft_strnew(1);
		newstr[0] = '+';
		temp = *str;
		*str = ft_strjoin(newstr, temp);
		ft_strdel(&newstr);
		ft_strdel(&temp);
	}
}

void		flag_plus(t_flags *flags, char **str, long long c)
{
	char	*newstr;
	char	*temp;

	if (flags->plus == 1 && c >= 0 && flags->type != 'u'
			&& flags->type != 'U' && flags->type != 'o'
			&& flags->type != 'O' && flags->type != 'X'
			&& flags->type != 'x')
	{
		newstr = ft_strnew(1);
		newstr[0] = '+';
		temp = *str;
		*str = ft_strjoin(newstr, temp);
		ft_strdel(&newstr);
		ft_strdel(&temp);
	}
}

void		flag_unsigned_plus(t_flags *flags, char **str)
{
	char	*newstr;
	char	*temp;

	if (flags->plus == 1)
	{
		newstr = ft_strnew(1);
		newstr[0] = '+';
		temp = *str;
		*str = ft_strjoin(newstr, temp);
		ft_strdel(&newstr);
		ft_strdel(&temp);
	}
}
