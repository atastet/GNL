/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atastet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 12:21:22 by atastet           #+#    #+#             */
/*   Updated: 2018/05/24 14:01:29 by atastet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_lst	*fd_new(int fd, t_lst **lst)
{
	t_lst *new;
	t_lst *tmp;

	tmp = *lst;
	while (tmp  != NULL && tmp->next != NULL)
		tmp = tmp->next;
	if ((new = (t_lst*)malloc(sizeof(t_lst))) == NULL)
		return (NULL);
	new->fd = fd;
	new->next = NULL;
	new->txt = NULL;

}

int				get_next_line(const int fd, char **line)
{
	static t_lst	*lst = NULL;
	t_lst			*tmp;
	char			buf[BUF_SIZE + 1];
	
	tmp = lst;
	// possible de mettre ca dans le fd_new
	if (fd == NULL || line == NULL)
		return (-1);
	// Gestion Muti fd -- Comprendre comment si j'appelle fd = 1 puis 2 puis 1 ca fonctionne
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (tmp == NULL)
	{
		if ((tmp = fd_new(fd, &lst)) == NULL)
			return (-1);
	}
}
