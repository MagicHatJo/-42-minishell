/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 20:48:17 by jochang           #+#    #+#             */
/*   Updated: 2019/03/31 20:48:18 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		dispatch_exec(char **av)
{
	pid_t	cpid;
	int		c;

	c = -1;
	cpid = fork();
	g_sigstatus = 1;
	if (cpid == 0)
	{
		if (!check_rights(av[0]))
			exit(0);
		execve(av[0], av, g_env);
		exit(1);
	}
	else
		wait(&c);
	g_sigstatus = 0;
	return ((c / 255) ^ 1);
}
