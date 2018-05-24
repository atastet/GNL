/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atastet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 13:27:39 by atastet           #+#    #+#             */
/*   Updated: 2018/05/24 10:50:55 by atastet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabdel(char ***tab)
{
	size_t	i;
	char	**erase;

	erase = NULL;
	if (!tab || !*tab)
		return ;
	i = 0;
	erase = *tab;
	while (erase[i])
	{
		ft_strdel(&erase[i]);
		i++;
	}
	free(*tab);
	*tab = NULL;
}
