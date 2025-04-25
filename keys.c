/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:48:42 by aelissao          #+#    #+#             */
/*   Updated: 2022/08/02 14:48:44 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int keycode, t_game *so_long)
{
	ft_printf("Key pressed: %d\n", keycode);
	
	mlx_clear_window(so_long->mlx, so_long->mlx_win);
	// WASD keys
	if (keycode == 119 || keycode == 65362) // W or Up Arrow
		go_up(so_long->map);
	if (keycode == 115 || keycode == 65364) // S or Down Arrow
		go_down(so_long->map);
	if (keycode == 97 || keycode == 65361)  // A or Left Arrow
		go_left(so_long->map);
	if (keycode == 100 || keycode == 65363) // D or Right Arrow
		go_right(so_long->map);
	if (keycode == 65307) // ESC key
	{
		ft_printf("you closed the game");
		exit(0);
	}
	print_map(so_long);
	return (0);
}

int	ft_close(t_game *so_long)
{
	(void)so_long;
	ft_printf("you closed the game");
	exit(0);
}

void	check_elements(t_map *map)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	while (++i < map->hight)
	{
		j = 0;
		while (j < map->width)
		{
			if ((map->data[i][j] == '1' || map->data[i][j] == 'E')
				|| (map->data[i][j] == '0'
				|| map->data[i][j] == 'P') || map->data[i][j] == 'C')
			{
				if (map->data[i][j] == 'C')
					map->collectible++;
				j++;
			}
			else
			{
				ft_printf("error in elements\n");
				exit(1);
			}
		}
	}
}
