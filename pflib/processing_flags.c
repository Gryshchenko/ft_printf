/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 18:23:52 by vgryshch          #+#    #+#             */
/*   Updated: 2018/02/27 17:34:22 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		flag_minus(t_flags *flags, char **str)
{
	char	*newstr;
	char	*del;
	char	*temp;
	int		len;
	int		i;

	i = -1;
	len = 0;
	if (flags->minus == 1 && (flags->precision < flags->width))
	{
		del = *str;
		while (**str == ' ')
		{
			len++;
			*str += 1;
		}
		newstr = ft_strnew(len);
		while (++i < len)
			newstr[i] = ' ';
		temp = *str;
		*str = ft_strjoin(temp, newstr);
		ft_strdel(&newstr);
		ft_strdel(&del);
	}
}

void		flag_space(t_flags *flags, char **str)
{
	char	*newstr;
	char	*temp;

	if (flags->plus == 0 && flags->space == 1 && flags->type != 'u'
			&& flags->type != 'U' && flags->type != 'o'
			&& flags->type != 'O' && flags->type != 'X'
			&& flags->type != 'x' && flags->width < ft_strlen(*str))
	{
		newstr = ft_strnew(1);
		newstr[0] = ' ';
		temp = *str;
		*str = ft_strjoin(newstr, temp);
		ft_strdel(&newstr);
		ft_strdel(&temp);
	}
}

void		print_width(t_flags *flags, char **str)
{
	size_t	width;
	char	*newstr;
	char	*temp;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(*str);
	if ((size_t)flags->width > len)
	{
		width = flags->width - len;
		newstr = ft_strnew(width);
		while (i < width)
		{
			newstr[i] = ' ';
			i++;
		}
		temp = *str;
		if (**str == '0' && (size_t)flags->precision == 0 && !flags->type)
			**str = ' ';
		*str = ft_strjoin(newstr, temp);
		ft_strdel(&newstr);
		ft_strdel(&temp);
	}
}

void		check_null_end(t_flags *flags, char **str, int c_copy)
{
	size_t	search_null;

	search_null = ft_strlen(*str);
	if ((*str)[search_null - 1] == '0' && flags->width && !flags->null
			&& c_copy == 0 && flags->type != 'd' && flags->type != 'i'
			&& flags->type != 'D' && flags->type != 'U' && flags->type != 'o'
			&& flags->type != 'O' && flags->type != 'X' && flags->type != 'x'
			&& flags->type != 'u' && flags->type != 'p')
		(*str)[search_null - 1] = ' ';
	if ((*str)[search_null - 1] == '0' && flags->hash && (flags->type == 'o'
				|| flags->type == 'O'))
		return ;
	if ((*str)[search_null - 1] == '0' && !flags->width && !flags->precision
			&& c_copy == 0 && flags->dot)
		(*str)[search_null - 1] = '\0';
	if ((*str)[search_null - 1] == '0' && flags->dot && flags->width
			&& !flags->precision && flags->type != 'p' && flags->type != 'O')
		(*str)[search_null - 1] = ' ';
}
