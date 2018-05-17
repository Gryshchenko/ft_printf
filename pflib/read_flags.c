/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:56:00 by vgryshch          #+#    #+#             */
/*   Updated: 2018/02/27 14:45:53 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	selection_flags(const char *s, int *i, t_flags *flags)
{
	while ((s[*i] == '-' || s[*i] == '+' || s[*i] == ' ' || s[*i] == '#'
				|| s[*i] == '0') && s[*i])
	{
		if (s[*i] == '-')
			flags->minus = 1;
		if (s[*i] == '+')
			flags->plus = 1;
		if (s[*i] == ' ')
			flags->space = 1;
		if (s[*i] == '#')
			flags->hash = 1;
		if (s[*i] == '0')
			flags->null = 1;
		(*i)++;
	}
}

void	selection_width(const char *s, int *i, t_flags *flags)
{
	int	width;

	width = 0;
	while (s[*i] && s[*i] >= '0' && s[*i] <= '9')
	{
		width = (width * 10) + (s[(*i)++] - '0');
		flags->width = width;
	}
	return ;
}

void	selection_precision(const char *s, int *i, t_flags *flags)
{
	int	precision;

	precision = 0;
	if (s[*i] == '.')
	{
		(*i)++;
		while (s[*i] && s[*i] >= '0' && s[*i] <= '9')
			precision = (precision * 10) + (s[(*i)++] - '0');
		flags->dot = 1;
		flags->precision = precision;
		return ;
	}
	return ;
}

void	selection_lenght_sec(const char *s, int *i, t_flags *flags)
{
	if (s[*i] == 'h')
	{
		(*i)++;
		if (s[*i] == 'h')
		{
			(*i)++;
			flags->length = 2;
		}
		else
			flags->length = 1;
	}
	else if (s[*i] == 'l')
	{
		(*i)++;
		if (s[*i] == 'l')
		{
			(*i)++;
			flags->length = 4;
		}
		else
			flags->length = 3;
	}
}

void	selection_lenght(const char *s, int *i, t_flags *flags)
{
	if (s[*i] == 'h' && flags->length == 1)
	{
		(*i)++;
		flags->length = 2;
	}
	else if (s[*i] == 'L')
	{
		(*i)++;
		flags->length = 5;
	}
	else if (s[*i] == 'z')
	{
		(*i)++;
		flags->length = 6;
	}
	else if (s[*i] == 'j')
	{
		(*i)++;
		flags->length = 7;
	}
	else if (s[*i] == 't')
	{
		(*i)++;
		flags->length = 8;
	}
}
