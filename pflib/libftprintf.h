/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 10:35:00 by vgryshch          #+#    #+#             */
/*   Updated: 2018/03/31 13:38:23 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct		s_flags
{
	unsigned int	minus:1;
	unsigned int	plus:1;
	unsigned int	space:1;
	unsigned int	hash:1;
	unsigned int	null:1;
	unsigned int	dot:1;
	size_t			precision;
	size_t			width;
	size_t			length;
	char			type;
}					t_flags;

int					ft_printf(const char *format, ...);
int					ft_putchar_printf(char c);
int					ft_putstr_printf(char const *s);
void				clean_flags(t_flags *flags);
void				selection_flags(const char *s, int *i, t_flags *flags);
void				selection_width(const char *s, int *i, t_flags *flags);
void				selection_precision(const char *s, int *i, t_flags *flags);
void				selection_lenght(const char *s, int *i, t_flags *flags);
void				selection_lenght_sec(const char *s, int *i, t_flags *flags);
void				print_width(t_flags *flags, char **str);
void				print_width_unicode(t_flags *flags, char **str, int len);
void				print_width_char(t_flags *flags, char **str);
void				print_precision(t_flags *flags, char **str);
void				wchar_pars_pre(t_flags *f, wchar_t **s, unsigned char **r);
unsigned char		*creat_wchar_string(t_flags *flags, wchar_t *str);
void				print_width_string(t_flags *flags, char **str);
void				flag_minus_string(t_flags *flags, char **str);
void				print_precision_string(t_flags *flags, char **str);
void				flag_null(t_flags *flags, char **str);
void				flag_space(t_flags *flags, char **str);
void				flag_plus(t_flags *flags, char **str, long long c);
void				flag_plus_char(t_flags *flags, char **str);
void				flag_unsigned_plus(t_flags *flags, char **str);
void				flag_minus(t_flags *flags, char **str);
void				flag_hash(t_flags *flags, char **str);
void				flag_hash_octal(t_flags *flags, char **str);
void				flag_minus_char(t_flags *flags, char **str);
void				flag_hash_hexadecimal(t_flags *flags, char **str, int c);
void				flag_hash_hexadecimal_up(t_flags *flags, char **str, int c);
void				flag_hash_pointer(t_flags *flags, char **str);
void				flag_minus_char(t_flags *flags, char **str);
void				check_null_end(t_flags *flags, char **str, int c_copy);
int					check_null_no_flags(t_flags *flags, int c);
int					print_decimal(va_list ap, t_flags *flags);
int					print_unsigned(va_list ap, t_flags *flags);
int					print_char(va_list ap, t_flags *flags);
int					print_char_c(va_list ap, t_flags *flags);
void				print_width_char(t_flags *flags, char **str);
void				print_w_c_zs(t_flags *flags, char **newstr, int width);
int					print_char_unicode(va_list ap, t_flags *flags);
int					print_string_s(va_list ap, t_flags *flags);
int					print_string(va_list ap, t_flags *flags);
int					print_string_unicode(t_flags *flags, va_list ap);
int					print_octal(va_list ap, t_flags *flags);
int					print_hexadecimal(va_list ap, t_flags *flags);
int					print_hexadecimal_up(va_list ap, t_flags *flags);
void				hex_arg_to_str_signed(char **str, unsigned char c);
void				hex_arg_to_str_short(char **str, unsigned short int c);
void				hex_arg_to_str_long(char **str, long long c);
void				hex_arg_to_str_unsigned(char **str, unsigned int c);
void				hex_up_arg_to_str_signed(char **str, unsigned char c);
void				hex_up_arg_to_str_short(char **str, unsigned short int c);
void				hex_up_arg_to_str_long(char **str, long long c);
void				hex_up_arg_to_str_unsigned(char **str, unsigned int c);
int					print_percent(t_flags *flags);
int					print_pointer(va_list ap, t_flags *flags);
int					print_decimal_long(t_flags *flags, va_list ap);
int					print_decimal_int(t_flags *flags, va_list ap);
int					print_decimal_signed(t_flags *flags, va_list ap);
int					print_decimal_short(t_flags *flags, va_list ap);
int					print_hexadecimal_signed(t_flags *flags, va_list ap);
int					print_hexadecimal_short(t_flags *flags, va_list ap);
int					print_hexadecimal_long(t_flags *flags, va_list ap);
int					print_hexadecimal_int(t_flags *flags, va_list ap);
int					print_string_s(va_list ap, t_flags *flags);
int					print_string_unicode(t_flags *flags, va_list ap);
#endif
