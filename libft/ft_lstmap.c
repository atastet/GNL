/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atastet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 10:16:37 by atastet           #+#    #+#             */
/*   Updated: 2018/04/27 10:58:48 by atastet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*map;
	t_list	*start;
	t_list	*tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	tmp = (*f)(lst);
	if ((map = ft_lstnew(tmp->content, tmp->content_size)) == NULL)
		return (NULL);
	start = map;
	lst = lst->next;
	while (lst != NULL)
	{
		tmp = (*f)(lst);
		if ((map->next = ft_lstnew(tmp->content, tmp->content_size)) == NULL)
			return (NULL);
		lst = lst->next;
		map = map->next;
	}
	return (start);
}
