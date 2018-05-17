# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 15:52:48 by vgryshch          #+#    #+#              #
#    Updated: 2018/02/27 17:39:02 by vgryshch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OBJECTS_LIB_PATH = ./libft/
OBJECTS_PFPATH = ./pflib/

SRC_PRINTF = ft_printf.c \
		ft_putchar_printf.c \
		ft_putstr_printf.c \
		flag_hash.c\
		flag_plus.c\
		flag_null.c\
		flag_precision.c\
		print_parsing_char.c \
		print_char.c \
		print_decimal.c \
		print_octal.c \
		print_unsigned.c \
		print_string.c \
		print_parsing_string.c\
		print_pointer.c \
		read_flags.c \
		processing_flags.c\
		print_hexadecimal.c\
		print_hexadecimal_up.c\
		hex_arg_to_str.c\
		hex_up_arg_to_str.c\
		print_percent.c\

SRC_LIBFT = ft_atoi.c \
        ft_itoa_base.c \
        ft_strrev.c \
		ft_bzero.c \
		ft_counter_int.c \
		ft_free.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_itoa_long.c \
		ft_itoa_unsigned_long.c \
		ft_itoa_unsigned.c \
		ft_listlast.c \
		ft_listlen.c \
		ft_listprint.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putwstr.c \
		ft_putwchar.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strwlen.c \
		ft_wcslen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strrev.c \
		ft_counter_bits.c \
		ft_itoa_base_16.c \
		ft_itoa_base_up_16.c \
		ft_itoa_base_8.c \
		ft_wchartostring.c \

OBJECTS_LIB = $(addprefix $(OBJECTS_LIB_PATH), $(SRC_LIBFT:.c=.o))

OBJECTS_PRINTF = $(addprefix $(OBJECTS_PFPATH), $(SRC_PRINTF:.c=.o))

CFLAGS = -Wall -Wextra

.PHONY: all
all: $(NAME)

$(NAME): $(OBJECTS_LIB) $(OBJECTS_PRINTF)
	@ar rc $(NAME) $(OBJECTS_LIB) $(OBJECTS_PRINTF)
	@ranlib $(NAME)
	@echo made

.c.o:
	@gcc $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	@echo cleaned
	@/bin/rm -f $(OBJECTS_LIB)
	@/bin/rm -f $(OBJECTS_PRINTF)

.PHONY: fclean
fclean: clean
	@echo fcleaned
	@/bin/rm -f ./libft/libft.a
	@/bin/rm -f $(NAME)

.PHONY: re
re: fclean all
