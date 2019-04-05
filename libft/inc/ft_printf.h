/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 19:52:29 by jochang           #+#    #+#             */
/*   Updated: 2018/08/22 21:20:04 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "macro.h"
# include "libft.h"

# define SPEC_COUNT 16

typedef struct	s_flags
{
	uint32_t	pound:1;
	uint32_t	zero:1;
	uint32_t	minus:1;
	uint32_t	plus:1;
	uint32_t	space:1;
}				t_flags;

typedef struct	s_opts
{
	t_flags		flags;
	uint32_t	width;
	int32_t		precision;
	uint32_t	length;
}				t_opts;

int				d_s(t_opts opts, va_list ap);
int				d_us(t_opts opts, va_list ap);
int				d_p(t_opts opts, va_list ap);
int				d_d(t_opts opts, va_list ap);
int				d_ud(t_opts opts, va_list ap);
int				d_o(t_opts opts, va_list ap);
int				d_uo(t_opts opts, va_list ap);
int				d_u(t_opts opts, va_list ap);
int				d_uu(t_opts opts, va_list ap);
int				d_x(t_opts opts, va_list ap);
int				d_ux(t_opts opts, va_list ap);
int				d_c(t_opts opts, va_list ap);
int				d_uc(t_opts opts, va_list ap);
int				d_percent(t_opts opts, va_list ap);
int				d_b(t_opts opts, va_list ap);

typedef int		(*t_spec) (t_opts, va_list);
typedef struct	s_dispatch
{
	char		op;
	t_spec		s;
}				t_dispatch;
extern const t_dispatch g_select[];

int				ft_printf(char *str, ...);
t_opts			get_opts(char **str, va_list ap);
char			*pt_itoa_abs(int64_t n);
char			*pt_itoh(uint64_t n, int caps);
char			*pt_itoo(uint64_t n);
void			pt_putwchar(wchar_t c);
void			pt_putwstr(wchar_t *s);
char			*pt_uitoa(uint64_t n);
int				pt_upval(uint64_t n);
size_t			pt_wcslen(wchar_t *s);

#endif
