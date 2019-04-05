/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_b.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 19:14:25 by jochang           #+#    #+#             */
/*   Updated: 2018/08/22 21:25:09 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		error_check(t_opts opts)
{
	(void)opts;
}

static uint64_t	get_num(uint32_t length, va_list ap)
{
	uint64_t	n;

	n = 0;
	if (length == 0 || length == 104 || length == 208 || length == 108)
		n = va_arg(ap, uint32_t);
	else if (length == 216)
		n = va_arg(ap, uint64_t);
	else if (length == 106)
		n = va_arg(ap, uintmax_t);
	else if (length == 122)
		n = va_arg(ap, size_t);
	return (n);
}

static char		*pt_itob(uint64_t n)
{
	int		i;
	char	*s;

	NULL_CHECK(!(s = (char*)ft_strnew(32)));
	i = (n == 0 ? 1 : 0);
	if (n == 0)
		s[0] = '0';
	while (n)
	{
		s[i] = (n & 1) + '0';
		n >>= 1;
		i++;
	}
	ft_strrev(s);
	return (s);
}

static char		*padding(char *s, int len, t_opts opts)
{
	char	*str;

	NULL_CHECK(!(str = (char*)ft_strnew(opts.width)));
	ft_memset(str, ' ', opts.width);
	if (opts.flags.minus)
		ft_strncpy(str, s, len);
	else
		ft_strncpy(&str[opts.width - len], s, len);
	free(s);
	return (str);
}

int				d_b(t_opts opts, va_list ap)
{
	uint64_t	n;
	char		*s;
	int			len;

	error_check(opts);
	n = get_num(opts.length, ap);
	s = pt_itob(n);
	len = ft_strlen(s);
	if (opts.width > (uint32_t)len)
		s = padding(s, len, opts);
	ft_putstr(s);
	len = ft_strlen(s);
	free(s);
	return (len);
}
