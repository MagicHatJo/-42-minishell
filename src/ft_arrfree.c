/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 21:38:42 by jochang           #+#    #+#             */
/*   Updated: 2019/03/24 21:38:42 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_arrfree(char **arr)
{
	int i;

	if (!arr)
		return ;
	i = -1;
	while (arr[++i])
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
	arr = NULL;
}
