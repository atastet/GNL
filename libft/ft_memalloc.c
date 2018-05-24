/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atastet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:45:11 by atastet           #+#    #+#             */
/*   Updated: 2018/04/24 17:49:02 by atastet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *mem_fr;

	if ((mem_fr = (void *)malloc(sizeof(*mem_fr) * size)) == NULL)
		return (NULL);
	ft_memset(mem_fr, 0, size);
	return (mem_fr);
}
