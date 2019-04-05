/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 23:58:21 by jochang           #+#    #+#             */
/*   Updated: 2019/03/24 23:58:22 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dispatch_cmd(int ac, char **av)
{
	int			i;
	const t_dis	g_sel[] = {
		{"cd", &d_cd},
		{"echo", &d_echo},
		{"env", &d_env},
		{"exit", &d_exit},
		{"history", &d_history},
		{"setenv", &d_setenv},
		{"unsetenv", &d_unsetenv}
	};

	RETURN_CHECK(!av[0]);
	i = -1;
	while (++i < OPT_COUNT)
		if (ft_strequ(av[0], g_sel[i].op))
		{
			g_sel[i].s(ac, av);
			return ;
		}
	RETURN_CHECK(dispatch_exec(av));
	RETURN_CHECK(dispatch_bin(av));
	RETURN_CHECK(ac == 1 && dispatch_folder(av[0]));
	ft_printf("%s: command not found\n", av[0]);
}
