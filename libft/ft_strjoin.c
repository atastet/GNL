/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atastet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 19:03:56 by atastet           #+#    #+#             */
/*   Updated: 2018/05/29 15:29:03 by atastet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size1;
	size_t	size2;
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if ((new = (char *)malloc(sizeof(char) * (size1 + size2 + 1))) == NULL)
		return (0);
	while (s1 && s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}
