/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atastet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 10:55:29 by atastet           #+#    #+#             */
/*   Updated: 2018/04/17 14:07:40 by atastet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*cpy;
	int		j;

	j = 0;
	i = ft_strlen(str);
	if ((cpy = (char *)malloc(sizeof(*cpy) * (i + 1))) == NULL)
		return (NULL);
	while (str[j])
	{
		cpy[j] = str[j];
		j++;
	}
	cpy[j] = '\0';
	return (cpy);
}
