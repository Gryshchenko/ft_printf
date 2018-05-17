/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 14:28:03 by vgryshch          #+#    #+#             */
/*   Updated: 2018/02/26 13:48:50 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			print_percent(t_flags *flags)
{
	char	c;
	char	*str;
	int		len;

	len = 0;
	c = 0;
	c = flags->type;
	str = ft_strnew(1);
	str[0] = c;
	print_width_char(flags, &str);
	flag_minus_char(flags, &str);
	ft_putstr(str);
	len += ft_strlen(str);
	ft_strdel(&str);
	return (len);
}
