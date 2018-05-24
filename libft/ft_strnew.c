/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atastet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:20:41 by atastet           #+#    #+#             */
/*   Updated: 2018/04/20 15:44:36 by atastet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *ptr;

	if ((ptr = (char*)malloc(sizeof(*ptr) * size + 1)) == NULL)
		return (NULL);
	ft_memset((void*)ptr, '\0', size + 1);
	return ((char *)ptr);
}
