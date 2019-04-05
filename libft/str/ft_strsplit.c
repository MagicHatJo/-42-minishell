/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 02:22:30 by jochang           #+#    #+#             */
/*   Updated: 2018/07/04 07:56:40 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	int		numwords;
	int		wlen;

	numwords = ft_wordcount(s, c);
	NULL_CHECK(!(arr = (char**)ft_memalloc((numwords + 1) * sizeof(char*))));
	i = 0;
	while (numwords--)
	{
		while (*s == c && *s)
			s++;
		wlen = ft_wordlen(s, c);
		NULL_CHECK(!(arr[i] = ft_strsub(s, 0, wlen)));
		s += wlen;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
