/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:47:52 by aelissao          #+#    #+#             */
/*   Updated: 2022/08/02 15:15:31 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_num_elements(t_map map, t_num *num)
{
	size_t	i;
	size_t	j;

	num->c = 0;
	num->e = 0;
	num->p = 0;
	i = 0;
	j = 0;
	while (i < map.hight)
	{
		j = 0;
		while (j < map.width)
		{
			if (map.data[i][j] == 'P')
			num->p++;
			else if (map.data[i][j] == 'E')
			num->e++;
			else if (map.data[i][j] == 'C')
			num->c++;
			j++;
		}
		i++;
	}
	if (num->c < 1 || num->e != 1 || num->p != 1)
		ft_num();
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dst;

	dst = (char *)malloc(ft_strlen(src) + 1);
	i = 0;
	if (dst == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dst[i] = ((char *)src)[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	check_ext_map(char *file_name)
{
	int	len;

	len = ft_strlen(file_name) - 1;
	if (file_name[len - 4])
	{
		if (!(file_name[len] == 'r' && file_name[len - 1] == 'e'
				&& file_name[len - 2] == 'b' && file_name[len - 3] == '.'))
		{
			ft_printf("error extention of map");
			exit(1);
		}
	}
}

void	ft_num(void)
{
	ft_printf("error in the number of elements");
	exit(1);
}
