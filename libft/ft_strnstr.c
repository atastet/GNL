/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atastet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 13:58:37 by atastet           #+#    #+#             */
/*   Updated: 2018/04/24 17:12:15 by atastet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t		i;
	char		*ndl;
	char		*hst;
	size_t		len;

	if (*needle == '\0')
		return ((char *)haystack);
	hst = (char *)haystack;
	ndl = (char *)needle;
	len = ft_strlen(ndl);
	i = 0;
	while (hst[i] != '\0' && (i + len) <= n)
	{
		if (ft_strncmp(haystack + i, needle, len) == 0)
		{
			return (hst + i);
		}
		i++;
	}
	return (NULL);
}
