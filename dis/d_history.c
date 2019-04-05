/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_history.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 04:30:04 by jochang           #+#    #+#             */
/*   Updated: 2019/04/02 04:30:04 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	d_history(int ac, char **av)
{
	HISTORY_STATE	*history;
	HIST_ENTRY		*get;
	int				i;

	(void)ac;
	(void)av;
	i = 0;
	history = history_get_history_state();
	ft_printf("\n** Session History **\n\n");
	while (i < history->length)
	{
		get = history_get(i);
		if (get)
			ft_printf("%-5d %s\n", i, get->line);
		i++;
	}
	ft_putchar('\n');
	free(history);
}
