/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atastet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:13:34 by atastet           #+#    #+#             */
/*   Updated: 2018/04/24 16:28:18 by atastet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	size_t	len;
	char	*map;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	if ((map = (char*)malloc(sizeof(*map) * (len + 1))) == NULL)
		return (NULL);
	while (s[i])
	{
		map[i] = (*f)((char)s[i]);
		i++;
	}
	map[i] = '\0';
	return (map);
}
