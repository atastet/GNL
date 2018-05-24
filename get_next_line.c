/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atastet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 12:21:22 by atastet           #+#    #+#             */
/*   Updated: 2018/05/24 19:06:55 by atastet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char		*write_line(t_lst *tmp)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp_rd;
	int		ret;
	//char	*new;
	//int		i;

	//i = 0;
	dprintf(1, "W1\n");
	while ((ret = read(tmp->fd, buf, BUFF_SIZE)) > 0 && ft_strchr(buf, '\n') == NULL)
	{
		buf[ret] = '\0';
		dprintf(1, "buf >> %s\n", buf);
		tmp_rd = tmp->txt;
		tmp->txt = ft_strjoin(tmp_rd, buf);
		dprintf(1, "W2>> %d\n", ret);
		dprintf(1, "tmp ->txt >> %s\n", tmp->txt);
		free(tmp_rd);
	}
	dprintf(1, "W3\n");
	if (ret == -1)
		return (NULL);
	dprintf(1, "W4\n");
	/*while (tmp->txt && tmp->txt[i] != '\n' && tmp->txt[i] != '\0')
		i++;
	if ((new = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	if (tmp->txt)
		new = ft_strncpy(new, tmp->txt, (size_t)i);
	new[i] = '\0';*/
	return (tmp->txt);
}

static t_lst	*fd_new(int fd, t_lst **lst)
{
	t_lst *new;
	t_lst *tmp;

	tmp = (*lst);
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
	char			*tmptxt;

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
	dprintf(1, "t4\n");
	if ((*line = write_line(tmp)) == NULL)
		return (-1);
	dprintf(1, "t5\n");
	tmptxt = tmp->txt;
	tmp->txt = ft_strsub(tmptxt, (ft_strlen(*line) + 1), ft_strlen(tmp->txt));
	return (1);
}
