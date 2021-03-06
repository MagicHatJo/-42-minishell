/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 00:41:07 by jochang           #+#    #+#             */
/*   Updated: 2019/03/25 00:41:07 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	d_exit(int ac, char **av)
{
	(void)ac;
	ft_arrfree(av);
	ft_arrfree(g_env);
	ft_arrfree(g_auto);
	exit(0);
}
