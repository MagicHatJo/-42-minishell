# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jochang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/19 01:31:43 by jochang           #+#    #+#              #
#    Updated: 2018/12/30 22:21:12 by jochang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CHK = chk/ft_isalnum.c \
	  chk/ft_isalpha.c \
	  chk/ft_isascii.c \
	  chk/ft_isdigit.c \
	  chk/ft_isdir.c \
	  chk/ft_isprint.c \
	  chk/ft_isspace.c \
	  chk/ft_placevalue.c \
	  chk/ft_wordcount.c \
	  chk/ft_wordlen.c \

CNV = cnv/ft_atoi.c \
	  cnv/ft_itoa.c \

BIT = bit/ft_swapendian.c \
	  bit/ft_swapnendian.c \
	  bit/ft_swapendian64.c \
	  bit/ft_swapnendian64.c \

GET = get/ft_getopt.c \
	  get/ft_getstdin.c \
	  get/ft_getnstdin.c \
	  get/ft_getwincols.c \
	  get/get_next_line.c \

LST = lst/ft_lstadd.c \
	  lst/ft_lstdel.c \
	  lst/ft_lstdelone.c \
	  lst/ft_lstiter.c \
	  lst/ft_lstmap.c \
	  lst/ft_lstnew.c \

MEM = mem/ft_bzero.c \
	  mem/ft_memalloc.c \
	  mem/ft_memccpy.c \
	  mem/ft_memchr.c \
	  mem/ft_memcmp.c \
	  mem/ft_memcpy.c \
	  mem/ft_memdel.c \
	  mem/ft_memmove.c \
	  mem/ft_memset.c \
	  mem/ft_realloc.c \

PUT = put/ft_putchar.c \
	  put/ft_putchar_fd.c \
	  put/ft_putendl.c \
	  put/ft_putendl_fd.c \
	  put/ft_putnbr.c \
	  put/ft_putnbr_fd.c \
	  put/ft_putstr.c \
	  put/ft_putstr_fd.c \
	  put/ft_printmemory.c \

STR = str/ft_strcat.c \
	  str/ft_strccpy.c \
	  str/ft_strcpy.c \
	  str/ft_strchr.c \
	  str/ft_strclr.c \
	  str/ft_strcmp.c \
	  str/ft_strdel.c \
	  str/ft_strdup.c \
	  str/ft_strequ.c \
	  str/ft_striter.c \
	  str/ft_striteri.c \
	  str/ft_strjoin.c \
	  str/ft_strlcat.c \
	  str/ft_strlen.c \
	  str/ft_strlower.c \
	  str/ft_strmap.c \
	  str/ft_strmapi.c \
	  str/ft_strncat.c \
	  str/ft_strncmp.c \
	  str/ft_strncpy.c \
	  str/ft_strndup.c \
	  str/ft_strnequ.c \
	  str/ft_strnew.c \
	  str/ft_strnstr.c \
	  str/ft_strrchr.c \
	  str/ft_strrev.c \
	  str/ft_strsplit.c \
	  str/ft_strstr.c \
	  str/ft_strsub.c \
	  str/ft_strtrim.c \
	  str/ft_strupper.c \
	  str/ft_tolower.c \
	  str/ft_toupper.c \

PRINTF = ft_printf/src/dispatch.c \
	ft_printf/src/ft_printf.c \
	ft_printf/src/get_opts.c \
	ft_printf/src/pt_itoa_abs.c \
	ft_printf/src/pt_itoh.c \
	ft_printf/src/pt_itoo.c \
	ft_printf/src/pt_putwchar.c \
	ft_printf/src/pt_putwstr.c \
	ft_printf/src/pt_uitoa.c \
	ft_printf/src/pt_upval.c \
	ft_printf/src/pt_wcslen.c \
	ft_printf/type/d_s.c \
	ft_printf/type/d_us.c \
	ft_printf/type/d_p.c \
	ft_printf/type/d_d.c \
	ft_printf/type/d_ud.c \
	ft_printf/type/d_o.c \
	ft_printf/type/d_uo.c \
	ft_printf/type/d_u.c \
	ft_printf/type/d_uu.c \
	ft_printf/type/d_x.c \
	ft_printf/type/d_ux.c \
	ft_printf/type/d_c.c \
	ft_printf/type/d_uc.c \
	ft_printf/type/d_percent.c \
	ft_printf/type/d_b.c \

SRC = $(CHK) $(CNV) $(BIT) $(GET) $(LST) $(MEM) $(PUT) $(STR) $(PRINTF)
INC = inc
OBJ = *.o

CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all
all: $(NAME)

$(NAME):
	@echo "\033[32mmaking libft...\033[0m"
	@$(CC) $(CFLAGS) -c $(SRC) -I $(INC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

.PHONY: clean
clean:
	@echo "\033[33mcleaning libft repository...\033[0m"
	@/bin/rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	@echo "\033[33mremoving libft library file...\033[0m"
	@/bin/rm -f $(NAME)

.PHONY: re
re: fclean all
