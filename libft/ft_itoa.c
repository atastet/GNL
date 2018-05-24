/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atastet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 13:53:42 by atastet           #+#    #+#             */
/*   Updated: 2018/04/24 15:41:37 by atastet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int size;

	size = 1;
	if (n < 0)
		size++;
	while (n > 9 || n < -9)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	char			*str;
	unsigned int	tmp;
	int				len;

	len = ft_size(n);
	if ((str = (char*)malloc(sizeof(*str) * (len + 1))) == NULL)
		return (NULL);
	if (n < 0)
		tmp = -n;
	else
		tmp = n;
	str[len--] = '\0';
	while (tmp >= 10)
	{
		str[len] = (tmp % 10) + '0';
		tmp = tmp / 10;
		len--;
	}
	str[len] = (tmp % 10) + '0';
	len--;
	if (n < 0)
	{
		str[len] = '-';
	}
	return (str);
}
