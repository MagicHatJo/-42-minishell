/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_qs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 21:57:01 by jochang           #+#    #+#             */
/*   Updated: 2019/03/31 21:57:02 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		count_qs(char *cmd)
{
	int		i;
	int		count;
	uint8_t	quotes;

	i = -1;
	count = 0;
	quotes = 0;
	while (cmd[++i])
	{
		if (cmd[i] == '"')
			quotes ^= 1;
		if (!quotes && !ft_isspace(cmd[i]) &&
			(ft_isspace(cmd[i + 1]) || !cmd[i + 1]))
			count++;
	}
	return (count);
}
