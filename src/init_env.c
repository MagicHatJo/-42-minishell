/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 21:35:22 by jochang           #+#    #+#             */
/*   Updated: 2019/03/24 21:35:23 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**g_env;

static void	set_shlvl(int i, char **env)
{
	char	*tmp;

	g_env[i] = ft_strjoin("SHLVL=",
		tmp = ft_itoa(ft_atoi(&env[i][6]) + 1));
	free(tmp);
}

void		init_env(char **env)
{
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (env[len])
		len++;
	if (!(g_env = (char**)ft_memalloc(sizeof(char*) * (len + 1))))
	{
		ft_printf("Environment setup failed\n");
		exit(0);
	}
	while (env[++i])
	{
		if (ft_strnequ("SHLVL=", env[i], 6))
			set_shlvl(i, env);
		else if (ft_strnequ("SHELL=", env[i], 6))
			g_env[i] = ft_strdup("SHELL=minishell");
		else if (!(g_env[i] = ft_strdup(env[i])))
		{
			ft_printf("Environment setup failed\n");
			ft_arrfree(g_env);
			exit(0);
		}
	}
}
