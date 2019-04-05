/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_echo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 00:23:33 by jochang           #+#    #+#             */
/*   Updated: 2019/03/25 00:23:34 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	d_echo(int ac, char **av)
{
	int		i;
	int		n;

	if (ac == 1)
	{
		ft_putchar('\n');
		return ;
	}
	i = (ft_strequ(av[1], "-n") ? 1 : 0);
	n = i;
	while (++i < ac)
	{
		ft_putstr(av[i]);
		i < ac - 1 ? ft_putchar(' ') : 0;
	}
	ft_printf(n ? "%" : "\n");
}
