/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_setenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 00:30:13 by jochang           #+#    #+#             */
/*   Updated: 2019/03/25 00:30:13 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	name_exists(char *name)
{
	int		len;
	char	**tmp;

	tmp = g_env;
	len = ft_strlen(name);
	while (*tmp)
	{
		if (ft_strnequ(*tmp, name, len))
			if ((*tmp)[len] == '=')
				return (1);
		tmp++;
	}
	return (0);
}

static int	append_name(char *name)
{
	char	**new;
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (g_env[len])
		len++;
	if (!(new = (char**)ft_memalloc(sizeof(char*) * (len + 2))))
	{
		ft_printf("setenv: Memory Error\n");
		return (0);
	}
	while (g_env[++i] && i < len)
		new[i] = ft_strdup(g_env[i]);
	ft_arrfree(g_env);
	new[i] = ft_strjoin(name, "=");
	new[++i] = NULL;
	g_env = new;
	return (1);
}

static void	append_val(char *name, char *value)
{
	char	*tmp;
	int		i;
	int		len;

	i = -1;
	len = ft_strlen(name);
	while (g_env[++i])
		if (ft_strnequ(g_env[i], name, len) && g_env[i][len] == '=')
		{
			tmp = g_env[i];
			g_env[i] = ft_strjoin(name, "=");
			free(tmp);
			tmp = g_env[i];
			if (value)
			{
				g_env[i] = ft_strjoin(g_env[i], value);
				free(tmp);
			}
			return ;
		}
}

void		d_setenv(int ac, char **av)
{
	char	**nv;

	if (ac == 2)
	{
		nv = ft_strsplit(av[1], '=');
		if (!name_exists(nv[0]))
		{
			if (!(append_name(nv[0])))
				return ;
		}
		append_val(nv[0], nv[1]);
		free(nv[0]);
		free(nv[1]);
		free(nv);
	}
	else
		ft_putendl("setenv: invalid arguments");
}
