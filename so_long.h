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

#include <mlx.h>
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <string.h>
#include <fcntl.h>
#include <X11/keysym.h>
#include "get_next_line.h"
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
	char	**layout;
	int	h;
	int	w;
	int	col;
	int	ex;
	int	st;
}	t_map;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		h;
	int		w;
	int		rng;
	t_map	map;
	t_spr	wall;
	t_spr	floor;
	t_spr	player;
	t_spr	player2;
	t_spr	col;
	t_spr	ex;
	t_spr	open;
	
}		t_win;

typedef struct s_img
{
	t_win	win;
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}		t_img;


t_map	map_init(t_map map);
int	check_map_req(char **layout, t_map *map);
t_map	get_map_info(char *map_file);

#endif
