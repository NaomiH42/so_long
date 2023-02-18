/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <ehasalu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:57:40 by ehasalu           #+#    #+#             */
/*   Updated: 2023/02/15 20:11:29 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	handle_no_event(void *prg)
{
	return (0);
}

int     exit_prg(t_win *window)
{
	if (window)
		mlx_destroy_window (window->mlx_ptr, window->win_ptr);
	exit(EXIT_SUCCESS);
}

void	print_map(t_win *prg)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((*prg).map.layout[i])
	{
			printf("%s\n", (*prg).map.layout[i]);
			i++;
	}
	printf("\n");
}

void	enemy_move(t_win *prg)
{
	if (((*prg).map.layout[(*prg).map.encoor.y + (*prg).enmv][(*prg).map.encoor.x] != '1'))
	{
		(*prg).map.layout[(*prg).map.encoor.y][(*prg).map.encoor.x] = '0';
		(*prg).map.layout[(*prg).map.encoor.y + (*prg).enmv][(*prg).map.encoor.x] = 'S';
		(*prg).map.encoor.y += (*prg).enmv;
	}
	else
		(*prg).enmv *= -1;
}

int	move(t_win *prg, int yc, int xc)
{
	if (((*prg).map.layout[(*prg).map.pcoor.y + yc][(*prg).map.pcoor.x + xc] != '1')
	&& ((*prg).map.layout[(*prg).map.pcoor.y + yc][(*prg).map.pcoor.x + xc] != 'E'))
	{
		if ((*prg).map.layout[(*prg).map.pcoor.y + yc][(*prg).map.pcoor.x + xc] == 'C')
			(*prg).map.col--;
		if ((*prg).map.layout[(*prg).map.pcoor.y + yc][(*prg).map.pcoor.x + yc] == 'X')
		{
			printf("U WONNERED");
		}
		(*prg).map.layout[(*prg).map.pcoor.y][(*prg).map.pcoor.x] = '0';
		(*prg).map.layout[(*prg).map.pcoor.y + yc][(*prg).map.pcoor.x + xc] = 'P';
		(*prg).map.pcoor.y += yc;
		(*prg).map.pcoor.x += xc;
		(*prg).movec++;
	}
	if ((*prg).map.col == 0)
	{
		(*prg).map.layout[(*prg).map.ecoor.y][(*prg).map.ecoor.x] = 'X';
	}
}

void	show_img(t_win *prg, char idf, int i, int j)
{
	if (idf == 'C' && prg->rng > 5000)
		mlx_put_image_to_window(prg->mlx_ptr, prg->win_ptr, prg->col.ptr, (prg->w/prg->map.w)*j, (prg->h/prg->map.h)*i);
	else if (idf == 'C')
		mlx_put_image_to_window(prg->mlx_ptr, prg->win_ptr, prg->col2.ptr, (prg->w/prg->map.w)*j, (prg->h/prg->map.h)*i);
	else if (idf == '1')
		mlx_put_image_to_window(prg->mlx_ptr, prg->win_ptr, prg->wall.ptr, (prg->w/prg->map.w)*j, (prg->h/prg->map.h)*i);
	else if (idf == '0')
		mlx_put_image_to_window(prg->mlx_ptr, prg->win_ptr, prg->floor.ptr, (prg->w/prg->map.w)*j, (prg->h/prg->map.h)*i);
	else if (idf == 'E')
		mlx_put_image_to_window(prg->mlx_ptr, prg->win_ptr, prg->ex.ptr, (prg->w/prg->map.w)*j, (prg->h/prg->map.h)*i);
	else if (idf == 'X')
		mlx_put_image_to_window(prg->mlx_ptr, prg->win_ptr, prg->open.ptr, (prg->w/prg->map.w)*j, (prg->h/prg->map.h)*i);
	else if (idf == 'P' && prg->rng > 5000)
		mlx_put_image_to_window(prg->mlx_ptr, prg->win_ptr, prg->player.ptr, (prg->w/prg->map.w) * prg->map.pcoor.x, (prg->h/prg->map.h) * prg->map.pcoor.y);
	else if (idf == 'P')
		mlx_put_image_to_window(prg->mlx_ptr, prg->win_ptr, prg->player2.ptr, (prg->w/prg->map.w) * prg->map.pcoor.x, (prg->h/prg->map.h) * prg->map.pcoor.y);
	else if (idf == 'S' && prg->rng > 50000)
		mlx_put_image_to_window(prg->mlx_ptr, prg->win_ptr, prg->en.ptr, (prg->w/prg->map.w) * prg->map.encoor.x, (prg->h/prg->map.h) * prg->map.encoor.y);
	else if (idf == 'S')
		mlx_put_image_to_window(prg->mlx_ptr, prg->win_ptr, prg->en2.ptr, (prg->w/prg->map.w) * prg->map.encoor.x, (prg->h/prg->map.h) * prg->map.encoor.y);
}

int	tiles(t_win *prg)
{
	int	i;
	int	j;

	i = 0;
	while(prg->map.layout[i])
	{
		j = 0;
		while (prg->map.layout[i][j])
		{
			show_img(prg, prg->map.layout[i][j], i, j);
			j++;
		}
		i++;
	}
}

int	next_frame(t_win *prg)
{
	if (prg->rng % 100 == 0)
	{
		mlx_clear_window(prg->mlx_ptr, prg->win_ptr);
		tiles(prg);
		mlx_string_put(prg->mlx_ptr, prg->win_ptr, 20, 20, 1111111, ft_itoa(prg->movec));
	}
	if (prg->rng % 20000 == 0)
		enemy_move(prg);
	prg->rng++;
	if (prg->rng > 100000)
		prg->rng = 0;
	if (prg->map.pcoor.x == prg->map.encoor.x && prg->map.pcoor.y == prg->map.encoor.y)
	{
		prg->map = get_map_info("map.ber");
		prg->movec = 0;
	}
	if (prg->map.pcoor.x == prg->map.ecoor.x && prg->map.pcoor.y == prg->map.ecoor.y)
		mlx_string_put(prg->mlx_ptr, prg->win_ptr, prg->w / 2, prg->h / 2, 1111111, "YOU WIN");
}

int	handle_keypress(int keysym, t_win *prg)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window (prg->mlx_ptr, prg->win_ptr);
		exit(0);
	}
	else if (keysym == XK_w)
		move(prg, -1, 0);
	else if (keysym == XK_a)
		move(prg, 0, -1);
	else if (keysym == XK_d)
		move(prg, 0, 1);
	else if (keysym == XK_s)
		move(prg, 1, 0);
	//print_map(prg);
	printf("Number of moves: %d\n", prg->movec);
	return (0);
}


void	sprites_init(t_win *prg)
{
	prg->wall.ptr = mlx_xpm_file_to_image(prg->mlx_ptr, "./sprites/wall.xpm",
	&(prg->wall.w), &(prg->wall.h));
	prg->player.ptr = mlx_xpm_file_to_image(prg->mlx_ptr, "./sprites/player.xpm",
	&(prg->player.w), &(prg->player.h));
	prg->player2.ptr = mlx_xpm_file_to_image(prg->mlx_ptr, "./sprites/player2.xpm",
	&(prg->player2.w), &(prg->player2.h));
	prg->floor.ptr = mlx_xpm_file_to_image(prg->mlx_ptr, "./sprites/floor.xpm",
	&(prg->floor.w), &(prg->floor.h));
	prg->ex.ptr = mlx_xpm_file_to_image(prg->mlx_ptr, "./sprites/exit.xpm",
	&(prg->ex.w), &(prg->ex.h));
	prg->open.ptr = mlx_xpm_file_to_image(prg->mlx_ptr, "./sprites/open.xpm",
	&(prg->open.w), &(prg->open.h));
	prg->col.ptr = mlx_xpm_file_to_image(prg->mlx_ptr, "./sprites/collectible.xpm",
	&(prg->col.w), &(prg->col.h));
	prg->col2.ptr = mlx_xpm_file_to_image(prg->mlx_ptr, "./sprites/collectible2.xpm",
	&(prg->col2.w), &(prg->col2.h));
	prg->en.ptr = mlx_xpm_file_to_image(prg->mlx_ptr, "./sprites/enemy.xpm",
	&(prg->en.w), &(prg->en.h));
	prg->en2.ptr = mlx_xpm_file_to_image(prg->mlx_ptr, "./sprites/enemy1.xpm",
	&(prg->en2.w), &(prg->en2.h));
}


int	main(void)
{
	t_win	prg;

	prg.map = get_map_info("map.ber");
	prg.h = (prg.map.h ) * 32;
	prg.w = (prg.map.w-1) * 32;
	prg.mlx_ptr = mlx_init();
	prg.win_ptr = mlx_new_window(prg.mlx_ptr, prg.w, prg.h, "game");
	prg.rng = 0;
	prg.enmv = 1;
	prg.movec = 0;
	sprites_init(&prg);
	mlx_loop_hook(prg.mlx_ptr, next_frame, &prg);
	mlx_hook(prg.win_ptr, 2, 1L << 2, handle_keypress, &prg);
	mlx_hook(prg.win_ptr, 17, 1L << 0, exit_prg, &prg);
	mlx_loop(prg.mlx_ptr);
	mlx_destroy_display(prg.mlx_ptr);
	free(prg.mlx_ptr);
}
