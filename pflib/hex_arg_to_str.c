/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hext_arg_to_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:10:52 by vgryshch          #+#    #+#             */
/*   Updated: 2018/02/26 13:27:00 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	hex_arg_to_str_signed(char **str, unsigned char c)
{
	if (c == 0)
		*str = ft_strdup("0");
	else
		*str = ft_itoa_base_16(c);
}

void	hex_arg_to_str_short(char **str, unsigned short int c)
{
	if (c == 0)
		*str = ft_strdup("0");
	else
		*str = ft_itoa_base_16(c);
}

void	hex_arg_to_str_long(char **str, long long c)
{
	if (c == 0)
		*str = ft_strdup("0");
	else
		*str = ft_itoa_base_16(c);
}

void	hex_arg_to_str_unsigned(char **str, unsigned int c)
{
	if (c == 0)
		*str = ft_strdup("0");
	else
		*str = ft_itoa_base_16(c);
}
