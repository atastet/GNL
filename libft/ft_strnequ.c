/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atastet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:58:07 by atastet           #+#    #+#             */
/*   Updated: 2018/04/20 17:23:34 by atastet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(const char *str1, const char *str2, size_t n)
{
	int res;

	if (str1 == NULL || str2 == NULL)
		return (0);
	res = ft_strncmp(str1, str2, n);
	if (res == 0)
		return (1);
	else
		return (0);
}
