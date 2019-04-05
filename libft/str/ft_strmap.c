/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 01:03:28 by jochang           #+#    #+#             */
/*   Updated: 2018/04/26 07:38:48 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		i;

	i = -1;
	if (s && f)
	{
		NULL_CHECK(!(new = (char*)ft_memalloc(ft_strlen(s) + 1)));
		while (s[++i])
			new[i] = f(s[i]);
		return (new);
	}
	return (NULL);
}
