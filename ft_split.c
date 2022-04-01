/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:35:15 by aelissao          #+#    #+#             */
/*   Updated: 2022/07/30 13:13:31 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wordsnum(char const *s, char c)
{
	int	i;
	int	d;

	i = 0;
	d = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			i++;
		while (s[i] == c && s[i] != '\0')
		{
			while (s[i] == c)
				i++;
			if (s[i] != c)
				d += 1;
			i++;
		}
	}
	i = ft_strlen(s);
	if (s[i - 1] == c)
		d -= 1;
	return (d + 1);
}

int	length(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			break ;
		else
			i++;
	}
	return (i);
}

char	**ft_free(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	*ft_tab(char const *s, char c, int size)
{
	int		i;
	int		k;
	char	*tab;

	i = 0;
	k = 0;
	tab = (char *)malloc((size + 1) * sizeof(char));
	if (!tab)
		ft_free(&tab, size);
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		tab[k] = s[i];
		i++;
		k++;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		l;
	char	**tab;
	int		size;

	i = 0;
	l = 0;
	if (!s)
		return (NULL);
	tab = (char **)malloc((wordsnum(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (s[l] != '\0')
	{
		while (s[l] == c)
			l++;
		if (s[l] != '\0')
		{
			size = length(s + l, c);
			tab[i++] = ft_tab(s + l, c, size);
			l += size;
		}
	}
	tab[i] = NULL;
	return ((char **)tab);
}
