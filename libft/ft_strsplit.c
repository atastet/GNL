/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atastet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 10:26:36 by atastet           #+#    #+#             */
/*   Updated: 2018/04/24 17:38:39 by atastet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_cnt_str(const char *s, char c)
{
	int		cnt;
	int		bi;
	int		i;

	bi = 0;
	cnt = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (bi == 1 && s[i] == c)
			bi = 0;
		if (bi == 0 && s[i] != c)
		{
			bi = 1;
			cnt++;
		}
		i++;
	}
	return (cnt);
}

static int		ft_len_to_c(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nb_str;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	nb_str = ft_cnt_str(s, c);
	if ((tab = (char **)malloc(sizeof(char *) * (nb_str + 1))) == NULL)
		return (NULL);
	while (nb_str > 0)
	{
		nb_str--;
		while (s[j] == c && s[j] != '\0')
			j++;
		if ((tab[i] = ft_strsub(s, j, ft_len_to_c(s + j, c))) == NULL)
			return (NULL);
		j += ft_len_to_c(s + j, c);
		i++;
		tab[i] = 0;
	}
	tab[i] = NULL;
	return (tab);
}
