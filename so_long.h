/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:46:31 by aelissao          #+#    #+#             */
/*   Updated: 2022/08/02 15:13:14 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# include "./ft_printf.h"

# define BUFFER_SIZE 1024
# define FIRST_LINE 0

# define PATH  "./photos/wall1.xpm"
# define PATH1 "./photos/output-onlinepngtools_1_.xpm"
# define PATH2 "./photos/mario.xpm"
# define PATH3 "./photos/exit.xpm"
# define PATH4 "./photos/floor.xpm"

typedef enum sdf { UP, DOWN, LEFT, RIGHT }	t_dir;

typedef struct s_img
{
	int		img_width;
	int		img_height;
	char	*relative_path;
	void	*img_wall;
	char	*relative_path1;
	void	*img_coins;
	char	*relative_path2;
	void	*img_mario;
	char	*relative_path3;
	void	*img_exit;
	void	*relative_path4;
	void	*img_zero;
}	t_img;

typedef struct s_map {
	char	**data;
	size_t	width;
	size_t	hight;
	int		num_mov;
	int		collectible;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	t_map	*map;
	t_img	*img;
}	t_game;

typedef struct elements_num
{
	int	p;
	int	c;
	int	e;
}	t_num;

char	*ft_strchr(const char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
void	check_hight_walls(t_map *map);
void	store_map(t_map *map, char *file_name);
void	check_width_walls(t_map *map);
void	check_elements(t_map *map);
void	check_num_elements(t_map map, t_num *num);
int		key_handler(int keycode, t_game *so_long);
int		go_up(t_map *map);
int		go_down(t_map *map);
int		go_left(t_map *map);
int		go_right(t_map *map);
void	print_map(t_game	*s);
int		ft_close(t_game *so_long);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *src);
void	check_ext_map(char *file_name);
void	checkers(t_map *map);
void	exitgame(void);
void	updatemap(t_map *map, t_dir dir, int i, int j);
void	put_img(t_game *s, void *img_ptr, size_t i, size_t j);
void	*xpm_img(t_img	*s_img, t_game	so_long, char *path);
void	ft_num(void);

#endif