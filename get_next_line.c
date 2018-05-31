/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atastet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 12:21:22 by atastet           #+#    #+#             */
/*   Updated: 2018/05/31 13:35:27 by atastet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*
** Read BUF_SiZE and Chekc if there is a \n o \0 inside, if not it continues
** reading. If a \n is found the i first cararcters are copied to new line.
** and return;
*/

static char			*extract_line(t_lst *lst)
{
	int		i;
	char	*new_line;
	char	buff[BUFF_SIZE + 1];
	int		ret;
	char	*tmptxt;

	i = 0;
	while (ft_strchr(lst->txt, '\n') == NULL &&
			(ret = read(lst->fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmptxt = lst->txt;
		lst->txt = ft_strjoin(tmptxt, buff);
		free(tmptxt);
	}
	if (ret == -1)
		return (NULL);
	while (lst->txt[i] != '\n' && lst->txt[i] != '\0')
		i++;
	if ((new_line = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	new_line = ft_strncpy(new_line, lst->txt, (size_t)i);
	new_line[i] = '\0';
	return (new_line);
}

/*
** Creates a new link in the lst if another fd is open;
*/

static t_lst		*fd_new(t_lst **lst, int fd)
{
	t_lst	*new;
	t_lst	*tmp;

	tmp = (*lst);
	if (fd < 0)
		return (NULL);
	while (tmp && tmp->next != NULL)
		tmp = tmp->next;
	if ((new = (t_lst *)malloc(sizeof(t_lst))) == NULL)
		return (NULL);
	new->fd = fd;
	new->txt = NULL;
	new->next = NULL;
	if ((*lst) == NULL)
		(*lst) = new;
	else
		tmp->next = new;
	return (new);
}

int					get_next_line(int fd, char **line)
{
	static t_lst	*lst = NULL;
	t_lst			*tmp;
	char			*tmp_txt;

	tmp = lst;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (tmp == NULL)
	{
		if ((tmp = fd_new(&lst, fd)) == NULL)
			return (-1);
	}
	if (!(line) || (*line = extract_line(tmp)) == NULL)
		return (-1);
	if (!(ft_strcmp(tmp->txt, "\0")))
		return (0);
	tmp_txt = tmp->txt;
	tmp->txt = ft_strsub(tmp_txt, (ft_strlen(*line) + 1), ft_strlen(tmp->txt));
	free(tmp_txt);
	return (1);
}
