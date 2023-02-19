/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <ehasalu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:39:23 by ehasalu           #+#    #+#             */
/*   Updated: 2023/02/15 20:09:28 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <string.h>
#include <fcntl.h>
#include <X11/keysym.h>
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

typedef struct	s_coor
{
	int	x;
	int	y;
}	t_coor;

typedef struct s_spr
{
	void	*ptr;
	int		h;
	int		w;
}	t_spr;


typedef struct	s_map
{
	t_coor	pcoor;
	t_coor	ecoor;
	t_coor	encoor;
	char	**layout;
	char	**layouttest;
	int	h;
	int	w;
	int	col;
	int	ex;
	int	st;
	int	coltest;
	int	extest;
}	t_map;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		h;
	int		w;
	int		rng;
	int		enmv;
	int		movec;
	int		dog;
	char	*mapargv;
	t_map	map;
	t_spr	wall;
	t_spr	floor;
	t_spr	player;
	t_spr	player2;
	t_spr	col;
	t_spr	col2;
	t_spr	ex;
	t_spr	open;
	t_spr	en;
	t_spr	en2;
}		t_win;

t_map	map_init(t_map map);
int		check_map_req(char **layout, t_map *map);
t_map	get_map_info(char *map_file);
void	show_img(t_win *prg, char idf, int i, int j);
void	sprites_init(t_win *prg);
int		move(t_win *prg, int yc, int xc);
void	enemy_move(t_win *prg);
int		flood(t_map *map, int y, int x);
int		check_path(t_map map);
void	error_msg(int nb);
t_map	map_init(t_map map);
int		exit_prg(t_win *window);
void	dog_check(char *str, t_win *prg);
void	check_arg(int argc, char **argv, t_win *prg);
void	free_stuff(t_win *prg);
void	free_imgs(t_win *prg);

#endif
