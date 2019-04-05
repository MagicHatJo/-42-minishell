/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 00:02:54 by jochang           #+#    #+#             */
/*   Updated: 2018/05/17 16:15:36 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int n;
	int s;

	i = 0;
	n = 0;
	s = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		IF_TRUE(str[i] == '-', s = -1);
		i++;
	}
	while (IS_DIGIT(str[i]))
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n * s);
}
