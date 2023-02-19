/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:40:29 by ehasalu           #+#    #+#             */
/*   Updated: 2023/02/15 13:41:59 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood(t_map *map, int y, int x)
{
	if ((*map).layouttest[y][x] == '1' || (*map).layouttest[y][x] == 'F')
		return (0);
	if ((*map).layouttest[y][x] == 'C')
		(*map).coltest -= 1;
	if ((*map).layouttest[y][x] == 'E')
		(*map).extest -= 1;
	(*map).layouttest[y][x] = 'F';
	flood(map, y + 1, x);
	flood(map, y - 1, x);
	flood(map, y, x - 1);
	flood(map, y, x + 1);
}

int	check_path(t_map map)
{
	int	i;

	map.coltest = map.col;
	map.extest = map.ex;
	i = 0;
	flood(&map, map.pcoor.y, map.pcoor.x);
	if (map.extest != 0 || map.coltest != 0)
	{
		return (0);
	}
	return (1);
}

void	check_map_lines(char **layout, t_map *map, int i, int l)
{
	if (i == 0 || i == (*map).h - 1 || l == 0 || l == (*map).w - 1)
	{
		if (layout[i][l] != '1')
			error_msg(2);
	}
	else if (layout[i][l] == 'E')
	{
		(*map).ex++;
		(*map).ecoor.x = l;
		(*map).ecoor.y = i;
	}
	else if (layout[i][l] == 'P')
	{
		(*map).st++;
		(*map).pcoor.x = l;
		(*map).pcoor.y = i;
	}
	else if (layout[i][l] == 'S')
	{
		(*map).encoor.x = l;
		(*map).encoor.y = i;
	}
	else if (layout[i][l] == 'C')
		(*map).col++;
}

int	check_map_req(char **layout, t_map *map)
{
	int	i;
	int	l;

	i = 0;
	while (layout[i])
	{
		l = 0;
		if (strlen(layout[0]) != strlen(layout[i]))
			error_msg(1);
		while (layout[i][l])
		{
			check_map_lines(layout, map, i, l);
			l++;
		}
		i++;
	}
	if ((*map).ex != 1 || (*map).st != 1 || (*map).col < 1)
		error_msg(3);
	if (!check_path(*map))
		error_msg(4);
}

t_map	get_map_info(char *map_file)
{
	t_map	map1;
	int		fd;
	char	*layout;
	char	*line;
	char	**map_split;

	fd = open(map_file, O_RDONLY);
	layout = ft_strdup_GNL("");
	line = get_next_line(fd);
	map1 = map_init(map1);
	while (line != NULL)
	{
		layout = ft_strjoin_GNL(layout, line);
		free(line);
		line = get_next_line(fd);
		map1.h++;
	}
	map1.layout = ft_split(layout, '\n');
	map1.layouttest = ft_split(layout, '\n');
	if (map1.layout[0])
		map1.w = ft_strlen(map1.layout[0]);
	check_map_req(map1.layout, &map1);
	free(layout);
	free(line);
	close(fd);
	return (map1);
}
