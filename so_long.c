/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:19:04 by aelissao          #+#    #+#             */
/*   Updated: 2022/08/02 18:12:02 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	images(t_img	*s_img, t_game	so_long)
{
		s_img->relative_path = "./photos/wall1.xpm";
		s_img->img_wall = xpm_img(s_img, so_long, PATH);
		s_img->relative_path1 = "./photos/output-onlinepngtools_1_.xpm";
		s_img->img_coins = xpm_img(s_img, so_long, PATH1);
		s_img->relative_path2 = "./photos/mario.xpm";
		s_img->img_mario = xpm_img(s_img, so_long, PATH2);
		s_img->relative_path3 = "./photos/exit.xpm";
		s_img->img_exit = xpm_img(s_img, so_long, PATH3);
		s_img->relative_path4 = "./photos/floor.xpm";
		s_img->img_zero = xpm_img(s_img, so_long, PATH4);
}

void	hooks(t_game *so_long)
{
	mlx_hook(so_long->mlx_win, 02, 0, key_handler, so_long);
	mlx_hook(so_long->mlx_win, 17, 0, ft_close, NULL);
}

void	checkers(t_map *map)
{
	check_hight_walls(map);
	check_width_walls(map);
	if (map->width == map->hight)
	{
		ft_printf("Error: The map must be rectangular");
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	t_game	so_long;
	t_img	s_img;
	t_map	map;
	t_num	num;

	so_long.mlx = mlx_init();
	if (argc == 2 && argv[1])
	{
		check_ext_map(argv[1]);
		store_map(&map, argv[1]);
		checkers(&map);
		check_elements(&map);
		check_num_elements(map, &num);
		so_long.map = &map;
		so_long.mlx_win = mlx_new_window(so_long.mlx,
				map.width * 64, map.hight * 64, "So_long");
		images(&s_img, so_long);
		so_long.img = &s_img;
		ft_printf("map has stored\n");
		print_map(&so_long);
		hooks(&so_long);
		mlx_loop(so_long.mlx);
	}
	else
		ft_printf("Invalid args.\n");
}
