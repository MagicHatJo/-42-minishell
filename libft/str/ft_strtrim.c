/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 02:00:33 by jochang           #+#    #+#             */
/*   Updated: 2018/05/17 16:50:32 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	int		i;
	int		len;
	int		j;

	NULL_CHECK(!s);
	i = 0;
	len = ft_strlen(s);
	while (ft_isspace(s[i]))
		i++;
	while (ft_isspace(s[len - 1]))
		len--;
	NULL_CHECK(!(new = (char*)ft_memalloc(len - i >= 0 ? len - i + 1 : 1)));
	j = -1;
	while (++j < len - i)
		new[j] = s[i + j];
	new[j] = '\0';
	return (new);
}
