/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atastet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:09:39 by atastet           #+#    #+#             */
/*   Updated: 2018/04/27 10:11:42 by atastet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*next_lst;

	lst = *alst;
	while (lst)
	{
		next_lst = lst->next;
		(*del)(lst->content, lst->content_size);
		free(lst);
		lst = next_lst;
	}
	*alst = NULL;
}
