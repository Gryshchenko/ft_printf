/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_null.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 09:24:16 by vgryshch          #+#    #+#             */
/*   Updated: 2018/02/27 17:51:17 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		null_no_plus_minus(char ***str, char **new, int len)
{
	if (ft_strchr(**str, '-') != (void*)0 && ft_strchr(*new, '0') != (void*)0)
	{
		(*new)[0] = '-';
		***str = '0';
		len = ft_strlen(*new);
		(*new)[len - 1] = '0';
	}
	if (ft_strchr(**str, '+') != (void*)0 && ft_strchr(*new, '0') != (void*)0)
	{
		(*new)[0] = '+';
		***str = '0';
		len = ft_strlen(*new);
		if (len > 1)
			(*new)[len - 1] = '0';
	}
}

static size_t	null_to_space(char ***str, char **newstr, size_t len, size_t i)
{
	while (***str == ' ')
	{
		len++;
		**str += 1;
	}
	*newstr = ft_strnew(len);
	while (i < len)
	{
		(*newstr)[i] = '0';
		i++;
	}
	return (i);
}

static void		null_width_and_x(t_flags *flags, char ***str, int i)
{
	if (flags->null && flags->width)
	{
		while ((**str)[i] != '\0')
		{
			if ((**str)[i] == ' ')
				(**str)[i] = '0';
			i++;
		}
	}
	if ((flags->type == 'X' || flags->type == 'x') && flags->hash)
	{
		(**str)[0] = '0';
		if (flags->type == 'X')
			(**str)[1] = 'X';
		else
			(**str)[1] = 'x';
	}
	if (flags->space && flags->type == 'd')
		***str = ' ';
}

void			flag_null(t_flags *flags, char **str)
{
	char	*newstr;
	char	*del;
	char	*temp;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	if (!flags->minus && flags->null && flags->width)
	{
		if (flags->precision == 0)
		{
			del = *str;
			i = null_to_space(&str, &newstr, len, i);
			temp = *str;
			null_no_plus_minus(&str, &newstr, len);
			*str = ft_strjoin(newstr, temp);
			ft_strdel(&newstr);
			ft_strdel(&del);
			null_width_and_x(flags, &str, i);
		}
	}
}
