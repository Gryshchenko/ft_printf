/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parsing_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:44:16 by vgryshch          #+#    #+#             */
/*   Updated: 2018/02/27 15:29:35 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				wchar_pars_pre(t_flags *f, wchar_t **s, unsigned char **r)
{
	unsigned char	*newstr;
	unsigned char	*temp;
	size_t			i;
	size_t			len;

	i = 0;
	len = 0;
	while ((*s)[i] && len < f->precision)
	{
		newstr = ft_wchartostring((*s)[i]);
		if ((len += ft_wcslen((*s)[i])) > f->precision)
		{
			free(newstr);
			break ;
		}
		temp = *r;
		*r = (unsigned char *)ft_strjoin((char *)*r, (char *)newstr);
		free(newstr);
		free(temp);
		i++;
	}
}

unsigned char		*creat_wchar_string(t_flags *flags, wchar_t *str)
{
	unsigned char	*new;
	unsigned char	*res;
	unsigned char	*temp;
	size_t			i;
	size_t			len;

	i = 0;
	len = 0;
	res = (unsigned char *)ft_strnew(1);
	if (flags->precision)
		wchar_pars_pre(flags, &str, &res);
	else
	{
		while (str[i])
		{
			new = ft_wchartostring((str)[i]);
			temp = res;
			res = (unsigned char *)ft_strjoin((char *)res, (char *)new);
			free(new);
			free(temp);
			i++;
		}
	}
	return (res);
}

void				print_width_string(t_flags *flags, char **str)
{
	size_t			width;
	char			*newstr;
	char			*temp;
	size_t			len;
	size_t			i;

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
		*str = ft_strjoin(newstr, temp);
		ft_strdel(&newstr);
		ft_strdel(&temp);
	}
}

void				print_precision_string(t_flags *flags, char **str)
{
	size_t			precision;

	precision = (size_t)flags->precision;
	if (precision && precision < ft_strlen(*str))
	{
		(*str)[precision] = '\0';
		return ;
	}
	if (flags->dot && flags->precision == 0)
		(*str)[0] = '\0';
}

void				flag_minus_string(t_flags *flags, char **str)
{
	char			*newstr;
	char			*del;
	char			*temp;
	int				len;
	int				i;

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
