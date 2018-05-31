/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fre_tmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atastet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 13:13:50 by atastet           #+#    #+#             */
/*   Updated: 2018/05/31 13:14:34 by atastet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	void		free_tmp(t_lst **lst, int fd)
{
	t_lst *lnk;
	t_lst *tmp;
	t_lst *tmp_fr;

	tmp = (*lst);
	if (tmp->next != NULL)
	{
		while (tmp->next->fd != fd)
			tmp = tmp->next;
	}
	if (tmp->next != NULL && tmp->next->next != NULL)
	{
		lnk = tmp->next->next;
		tmp_fr = tmp->next;
		tmp->next = lnk;
	}
	else
	{
		tmp_fr = tmp;
		tmp->next = NULL;
	}
	free(tmp_fr);
}
