/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:48:33 by aelissao          #+#    #+#             */
/*   Updated: 2022/08/02 14:48:35 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	go_up(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->data[i])
	{
		j = 0;
		while (map->data[i][j])
		{
			if (map->data[i][j] == 'P' && (map->data[i - 1][j] == '0' ||
			map->data[i - 1][j] == 'C'))
			{
				updatemap(map, UP, i, j);
				map->data[i][j] = '0';
				map->num_mov++;
				return (ft_printf("num of moves %d\n", map->num_mov));
			}
			else if (map->data[i][j] == 'P' && (map->data[i - 1][j] == 'E') &&
			map->collectible == 0)
				exitgame();
			j++;
		}
		i++;
	}
	return (0);
}

int	go_down(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->data[i])
	{
		j = 0;
		while (map->data[i][j])
		{
			if (map->data[i][j] == 'P' && (map->data[i + 1][j] == '0' ||
			map->data[i + 1][j] == 'C'))
			{
				updatemap(map, DOWN, i, j);
				map->data[i][j] = '0';
				map->num_mov++;
				return (ft_printf("num of moves %d\n", map->num_mov));
			}
			else if (map->data[i][j] == 'P' && (map->data[i + 1][j] == 'E') &&
			map->collectible == 0)
				exitgame();
			j++;
		}
		i++;
	}
	return (0);
}

int	go_left(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->data[i])
	{
		j = 0;
		while (map->data[i][j])
		{
			if (map->data[i][j] == 'P' && (map->data[i][j - 1] == '0' ||
			map->data[i][j - 1] == 'C'))
			{
				updatemap(map, LEFT, i, j);
				map->data[i][j] = '0';
				map->num_mov++;
				return (ft_printf("num of moves %d\n", map->num_mov));
			}
			else if (map->data[i][j] == 'P' && (map->data[i][j - 1] == 'E') &&
			map->collectible == 0)
				exitgame();
			j++;
		}
		i++;
	}
	return (0);
}

int	go_right(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->data[i])
	{
		j = 0;
		while (map->data[i][j])
		{
			if (map->data[i][j] == 'P' && (map->data[i][j + 1] == '0' ||
			map->data[i][j + 1] == 'C'))
			{
				updatemap(map, RIGHT, i, j);
				map->data[i][j] = '0';
				map->num_mov++;
				return (ft_printf("num of moves %d\n", map->num_mov));
			}
			else if (map->data[i][j] == 'P' && (map->data[i][j + 1] == 'E') &&
			map->collectible == 0)
				exitgame();
			j++;
		}
		i++;
	}
	return (0);
}
