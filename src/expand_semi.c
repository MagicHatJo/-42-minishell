/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_semi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 03:59:00 by jochang           #+#    #+#             */
/*   Updated: 2019/04/02 03:59:00 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_oac(char *cmd)
{
	int		i;
	int		count;
	uint8_t	quotes;

	count = 1;
	quotes = 0;
	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] == '"')
			quotes ^= 1;
		else if (cmd[i] == ';' && !quotes)
			count++;
	}
	return (count);
}

char		**expand_semi(char *cmd)
{
	int		i;
	int		k;
	int		oac;
	char	**oav;
	uint8_t	quotes;

	oac = get_oac(cmd);
	oav = (char**)ft_memalloc(sizeof(char*) * (oac + 1));
	i = -1;
	k = -1;
	while (++i < oac)
	{
		k++;
		oav[i] = ft_strcdup(&cmd[k], ';');
		while (cmd[k] && cmd[k] != ';')
			k++;
	}
	quotes = 0;
	return (oav);
}
