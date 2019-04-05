/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_uc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:39:17 by jochang           #+#    #+#             */
/*   Updated: 2018/08/22 18:26:54 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	error_check(t_opts opts)
{
	if (opts.flags.pound + opts.flags.zero +
		opts.flags.plus + opts.flags.space > 0)
	{
		ft_putstr("error: undefined behavior\n");
		exit(1);
	}
	if (opts.precision != -1)
	{
		ft_putstr("error: undefined behavior\n");
		exit(1);
	}
	if (opts.length != 0)
	{
		ft_putstr("error: undefined behavior");
		exit(1);
	}
}

static void	pt_putspaces(int size)
{
	int		i;

	i = 0;
	while (i++ < size)
		ft_putchar(' ');
}

static void	padding(char c, int size, int left_align)
{
	if (!left_align && size)
		pt_putspaces(size - 1);
	pt_putwchar(c);
	if (left_align && size)
		pt_putspaces(size - 1);
	return ;
}

int			d_uc(t_opts opts, va_list ap)
{
	wchar_t	c;

	error_check(opts);
	c = va_arg(ap, wchar_t);
	padding(c, opts.width, opts.flags.minus);
	return (opts.width > 1 ? opts.width : 1);
}
