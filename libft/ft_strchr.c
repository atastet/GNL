/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atastet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:02:55 by atastet           #+#    #+#             */
/*   Updated: 2018/05/29 14:27:04 by atastet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	b;

	i = 0;
	b = (unsigned char)c;
	if (!s)
		return (NULL);
	while (s[i] != '\0' && s[i] != b)
		i++;
	if (s[i] == '\0' && b != '\0')
		return (NULL);
	return ((char *)(s + i));
}
