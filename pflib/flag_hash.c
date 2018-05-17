/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 09:12:27 by vgryshch          #+#    #+#             */
/*   Updated: 2018/02/27 09:19:01 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		flag_hash(t_flags *flags, char **str)
{
	char	*newstr;
	char	*temp;

	if (flags->hash && **str != '0')
	{
		newstr = ft_strnew(1);
		newstr[0] = '0';
		temp = *str;
		*str = ft_strjoin(newstr, temp);
		ft_strdel(&newstr);
		ft_strdel(&temp);
	}
}

void		flag_hash_octal(t_flags *flags, char **str)
{
	char	*newstr;
	char	*temp;

	if (flags->hash && **str != '0')
	{
		newstr = ft_strnew(1);
		newstr[0] = '0';
		temp = *str;
		*str = ft_strjoin(newstr, temp);
		ft_strdel(&newstr);
		ft_strdel(&temp);
	}
}

void		flag_hash_hexadecimal(t_flags *flags, char **str, int c)
{
	char	*newstr;
	char	*temp;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (flags->hash && c != 0 && flags->null && !flags->precision
			&& !flags->dot && !flags->minus && flags->width > ft_strlen(*str))
		return ;
	if ((flags->hash && c != 0) || (flags->hash && c != 0 && flags->precision))
	{
		while ((*str)[i] == ' ' && (*str)[i])
			i++;
		newstr = ft_strnew(2);
		newstr[0] = '0';
		newstr[1] = 'x';
		temp = *str;
		*str = ft_strjoin(newstr, temp);
		ft_strdel(&newstr);
		ft_strdel(&temp);
	}
}

void		flag_hash_pointer(t_flags *flags, char **str)
{
	char	*newstr;
	char	*temp;

	if (flags->type == 'p')
	{
		newstr = ft_strnew(2);
		newstr[0] = '0';
		newstr[1] = 'x';
		temp = *str;
		*str = ft_strjoin(newstr, temp);
		ft_strdel(&newstr);
		ft_strdel(&temp);
	}
}

void		flag_hash_hexadecimal_up(t_flags *flags, char **str, int c)
{
	char	*newstr;
	char	*temp;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (flags->hash && c != 0 && flags->null && !flags->precision
			&& !flags->dot && !flags->minus && flags->width > ft_strlen(*str))
		return ;
	if ((flags->hash && c != 0) || (flags->hash && c != 0 && flags->precision))
	{
		while ((*str)[i] == ' ' && (*str)[i])
			i++;
		newstr = ft_strnew(2);
		newstr[0] = '0';
		newstr[1] = 'X';
		temp = *str;
		*str = ft_strjoin(newstr, temp);
		ft_strdel(&newstr);
		ft_strdel(&temp);
	}
}
