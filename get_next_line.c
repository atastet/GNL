/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atastet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 12:21:22 by atastet           #+#    #+#             */
/*   Updated: 2018/05/24 15:33:37 by atastet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*write_line(t_lst *tmp)
{
	char	buf[BUF_SIZE + 1];
	int		i;
	char	*tmp_rd;
	int		ret;
	
	i = 0;
	while ((ret = (read(tmp->fd, buf, BUF_SIZE)) > 0) &&
		ft_strchr(tmp->txt, '\n') == NULL)
	{
		buf[ret] = '\0';
		tmp_rd = tmp->txt;
		tmp->txt = ft_strjoin(tmp_rd, buf);
		free(tmp_rd);
	}
	if (ret < 0)
		return (NULL);
	return (tmp->txt);
}

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
	// si c'est la premiere fois qu'on lance GNL
	if ((*lst) == NULL)
		(*lst) = new;
	else 
		tmp->next = new;
	return (new);
}

int				get_next_line(const int fd, char **line)
{
	static t_lst	*lst = NULL;
	t_lst			*tmp;
	
	tmp = lst;
	// possible de mettre ca dans le fd_new
	if (fd < 0 || line == NULL)
		return (-1);
	// Gestion Muti fd -- Comprendre comment si j'appelle fd = 1 puis 2 puis 1 ca fonctionne
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (tmp ==NULL)
	{
		if ((tmp = fd_new(fd, &lst)) == NULL)
			return (-1);
	}
	if ((*line = write_line(tmp)) == NULL)
		return (-1);
	return (0);
}
