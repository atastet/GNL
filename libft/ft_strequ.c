/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_streau.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atastet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:00:21 by atastet           #+#    #+#             */
/*   Updated: 2018/04/20 16:18:24 by atastet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(const char *str1, const char *str2)
{
	int res;

	if (str1 == NULL || str2 == NULL)
		return (0);
	res = ft_strcmp(str1, str2);
	if (res == 0)
		return (1);
	else
		return (0);
}
