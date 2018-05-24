/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atastet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:52:54 by atastet           #+#    #+#             */
/*   Updated: 2018/04/20 17:54:23 by atastet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*src2;
	unsigned char	*dst2;

	i = 0;
	dst2 = (unsigned char*)dst;
	src2 = (unsigned char*)src;
	if (dst > src)
	{
		while (len > i)
		{
			dst2[len - 1] = src2[len - 1];
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			dst2[i] = src2[i];
			i++;
		}
	}
	return (dst);
}
