/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:47:22 by aelissao          #+#    #+#             */
/*   Updated: 2022/08/02 18:14:07 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exitgame(void)
{
	ft_printf("You Won The Game!");
	exit(1);
}

void	updatemap(t_map *map, t_dir dir, int i, int j)
{
	if (dir == UP)
	{
		if (map->data[i - 1][j] == 'C')
			map->collectible--;
		map->data[i - 1][j] = 'P';
	}
	else if (dir == DOWN)
	{
		if (map->data[i + 1][j] == 'C')
			map->collectible--;
			map->data[i + 1][j] = 'P';
	}
	else if (dir == RIGHT)
	{
		if (map->data[i][j + 1] == 'C')
					map->collectible--;
				map->data[i][j + 1] = 'P';
	}
	else if (dir == LEFT)
	{
		if (map->data[i][j - 1] == 'C')
			map->collectible--;
		map->data[i][j - 1] = 'P';
	}
}

void	put_img(t_game *s, void *img_ptr, size_t i, size_t j)
{
	mlx_put_image_to_window(s->mlx, s->mlx_win,
		img_ptr, j * 64, i * 64);
}

void	print_map(t_game	*s)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < s->map->hight)
	{
		j = 0;
		while (s->map->data[i][j] != '\n')
		{
			if (s->map->data[i][j] == '1')
				put_img(s, s->img->img_wall, i, j);
			if (s->map->data[i][j] == 'C')
				put_img(s, s->img->img_coins, i, j);
			if (s->map->data[i][j] == 'P')
				put_img(s, s->img->img_mario, i, j);
			if (s->map->data[i][j] == 'E')
				put_img(s, s->img->img_exit, i, j);
			if (s->map->data[i][j] == '0')
				put_img(s, s->img->img_zero, i, j);
			j++;
		}
		i++;
	}
}

void	*xpm_img(t_img	*s_img, t_game	so_long, char *path)
{
	if (!mlx_xpm_file_to_image(so_long.mlx, path,
			&s_img->img_width, &s_img->img_height))
	{
		ft_printf("xpm_img_empty");
		exit(1);
	}
	return (mlx_xpm_file_to_image(so_long.mlx, path,
			&s_img->img_width, &s_img->img_height));
}
