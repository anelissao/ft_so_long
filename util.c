/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:48:15 by aelissao          #+#    #+#             */
/*   Updated: 2022/08/02 17:41:08 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error_and_exit(char *error_msg)
{
	ft_printf("%s\n", error_msg);
	exit(1);
}

char	*read_map_as_a_line(char *file_name)
{
	int		fd;
	char	*tmp;
	char	*line;
	char	*map_in_line;

	map_in_line = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		print_error_and_exit("Error: map doesn't exist");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line && line[0] == '\n')
			exit(1);
		tmp = ft_strjoin(map_in_line, line);
		free(line);
		map_in_line = tmp;
	}
	close(fd);
	return (map_in_line);
}

void	store_map(t_map *map, char *file_name)
{
	char	*map_in_line;
	int		line_num;

	map_in_line = read_map_as_a_line(file_name);
	if (map_in_line == NULL)
		print_error_and_exit("Error: map empty");
	map->data = ft_split(map_in_line, '\n');
	map->width = ft_strlen(map->data[FIRST_LINE]);
	line_num = FIRST_LINE;
	while (map->data[++line_num] != NULL)
	{
		if (ft_strlen(map->data[line_num]) != map->width)
			print_error_and_exit("Error: map width");
	}
	map->hight = line_num;
	map->num_mov = 0;
	map->collectible = 0;
}

void	check_hight_walls(t_map *map)
{
	size_t	j;

	j = 0;
	while (j < map->width)
	{
		if (map->data[0][j] != '1')
		{
			ft_printf("error in height walls");
			exit(1);
		}
		j++;
	}
	j = 0;
	while (map->data[map->hight - 1][j] != '\n'
	&& map->data[map->hight - 1][j] != '\0')
	{
		if (map->data[map->hight - 1][j] != '1')
		{
			ft_printf("error in width walls");
			exit(1);
		}
		j++;
	}
}

void	check_width_walls(t_map *map)
{
	int	i;

	i = 1;
	while (map->data[i] != map->data[map->hight])
	{
		if (map->data[i][0] != '1' || map->data[i][map->width - 1] != '1')
		{
			ft_printf ("error in width walls");
			exit(1);
		}
		i++;
	}
}
