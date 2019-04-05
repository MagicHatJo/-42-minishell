/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 01:07:02 by jochang           #+#    #+#             */
/*   Updated: 2018/04/20 23:13:34 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (!*to_find)
		return ((char*)str);
	while (str[i])
	{
		k = 0;
		while (to_find[k] == str[i + k])
			if (!to_find[++k])
				return ((char*)(&str[i]));
		i++;
	}
	return (NULL);
}
