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

t_map	map_init(t_map map)
{
	map.layout = NULL;
	(map.h) = 0;
	(map.w) = 0;
	(map.col) = 0;
	(map.ex) = 0;
	map.st = 0;
	map.pcoor.x = 0;
	map.pcoor.y = 0;
	map.ecoor.x = 0;
	map.ecoor.y = 0;
	return (map);
}

int	flood(t_map *map, int y, int x)
{
	if ((*map).layout[y][x] == '1' || (*map).layout[y][x] == 'F')
		return(0);
	if ((*map).layout[y][x] == 'C')
		(*map).col--;
	if ((*map).layout[y][x] == 'E')
		(*map).ex--;
	(*map).layout[y][x] = 'F';
	flood(map, y + 1, x);
	flood(map, y - 1, x);
	flood(map, y, x - 1);
	flood(map, y, x + 1);
}

int	check_path(t_map map)
{
	t_map	maptest;
	int	i;

	i = 0;
	ft_memcpy(&maptest, &map, (sizeof (t_map)));
	
	flood(&maptest, maptest.pcoor.y, maptest.pcoor.x);
	if (maptest.ex != 0 || maptest.col != 0)
	{
		return (0);
	}
	return (1);
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
		{	
			printf("ERROR\nMAP IS NOT RECTANGULAR\n");
			exit(0);
		}
		while (layout[i][l])
		{
			if (i == 0 || i == (*map).h - 1 || l == 0 || l == (*map).w - 1)
			{
				if(layout[i][l] != '1')
				{
					printf("ERROR\nMAP IS NOT SURROUNDED BY WALLS\n");
					exit(0);
				}
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
			else if (layout[i][l] == 'C')
				(*map).col++;
			l++;
		}
		i++;
	}
	if ((*map).ex != 1 || (*map).st != 1 || (*map).col < 1)
	{
		printf("ERROR\nMAP CONTAINS INVALID NUMBER OF GAME OBJECTS\n");
		exit(0);
	}
	if (!check_path(*map))
	{
		printf("ERROR\nMAP DOESN'T CONTAIN VALID PATH\n");
		exit(0);	
	}
}

t_map	get_map_info(char *map_file)
{
	t_map	map1;
	int	fd;
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
		line = get_next_line(fd);
		map1.h++;
	}
	map1.layout = ft_split(layout, '\n');
	map1.w = ft_strlen(map1.layout[0]);
	check_map_req(map1.layout, &map1);
	return (map1);
}
