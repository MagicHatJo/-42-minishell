/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 02:37:48 by jochang           #+#    #+#             */
/*   Updated: 2018/04/24 10:55:11 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordcount(char const *s, char const c)
{
	int		count;
	int		i;

	count = 0;
	i = -1;
	ZERO_CHECK(!s);
	if (c < 32)
		return (1);
	while (s[++i])
		IF_TRUE(s[i] != c && (i == 0 || s[i - 1] == c), count++);
	return (count);
}
