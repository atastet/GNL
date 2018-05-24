/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atastet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 12:04:05 by atastet           #+#    #+#             */
/*   Updated: 2018/04/17 14:12:05 by atastet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		i;
	size_t		pos;
	size_t		len;

	i = 0;
	len = ft_strlen(needle);
	if (len == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		pos = 0;
		while (needle[pos] == haystack[pos + i])
		{
			if (pos == len - 1)
				return ((char *)haystack + i);
			pos++;
		}
		i++;
	}
	return (NULL);
}
