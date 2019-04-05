/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_unsetenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 00:30:27 by jochang           #+#    #+#             */
/*   Updated: 2019/03/25 00:30:28 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	pop_index(int index)
{
	char	**new;
	int		i;
	int		k;
	int		len;

	i = -1;
	k = 0;
	len = 0;
	while (g_env[len])
		len++;
	if (!(new = (char**)ft_memalloc(sizeof(char*) * (len))))
	{
		ft_printf("unsetenv: Memory Error\n");
		return (0);
	}
	while (g_env[++i] && i < len)
		if (i != index)
			new[k++] = ft_strdup(g_env[i]);
	ft_arrfree(g_env);
	new[k] = NULL;
	g_env = new;
	return (1);
}

void		d_unsetenv(int ac, char **av)
{
	int		len;
	int		i;

	if (ac == 2)
	{
		i = -1;
		len = ft_strlen(av[1]);
		while (g_env[++i])
			if (ft_strnequ(g_env[i], av[1], len) && g_env[i][len] == '=')
			{
				pop_index(i);
				break ;
			}
	}
	else
		ft_putendl("unsetenv: invalid arguments");
}
