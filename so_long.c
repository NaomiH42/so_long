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
	}
	if ((*prg).map.col == 0)
	{
		(*prg).map.layout[(*prg).map.ecoor.y][(*prg).map.ecoor.x] = 'X';
	}
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
			if (prg->map.layout[i][j] == '1')
			{
				mlx_put_image_to_window(prg->mlx_ptr, prg->win_ptr, prg->wall.ptr, (prg->w/prg->map.w)*j, 
				(prg->h/prg->map.h)*i);
			}
			if (prg->map.layout[i][j] == '0')
			{	
				mlx_put_image_to_window(prg->mlx_ptr, prg->win_ptr, prg->floor.ptr, (prg->w/prg->map.w)*j, 
				(prg->h/prg->map.h)*i);
			}
			if (prg->map.layout[i][j] == 'E')
			{
				mlx_put_image_to_window(prg->mlx_ptr, prg->win_ptr, prg->ex.ptr, (prg->w/prg->map.w)*j, 
				(prg->h/prg->map.h)*i);
			}
			if (prg->map.layout[i][j] == 'X')
			{
				mlx_put_image_to_window(prg->mlx_ptr, prg->win_ptr, prg->open.ptr, (prg->w/prg->map.w)*j, 
				(prg->h/prg->map.h)*i);
			}
			if (prg->map.layout[i][j] == 'P')
			{
				if (prg->rng % 2 == 0)
					mlx_put_image_to_window(prg->mlx_ptr, prg->win_ptr, prg->player.ptr, (prg->w/prg->map.w) * prg->map.pcoor.x, (prg->h/prg->map.h) * prg->map.pcoor.y);
				else
					mlx_put_image_to_window(prg->mlx_ptr, prg->win_ptr, prg->player2.ptr, (prg->w/prg->map.w) * prg->map.pcoor.x, (prg->h/prg->map.h) * prg->map.pcoor.y);

			}
			j++;
		}
		i++;
	}
}

int	next_frame(t_win *prg)
{
	mlx_clear_window(prg->mlx_ptr, prg->win_ptr);
	prg->rng++;
	tiles(prg);
}

int	handle_keypress(int keysym, t_win *prg)
{
	if (keysym == XK_Escape)
		exit_prg(prg->win_ptr);		
	else if (keysym == XK_w)
		move(prg, -1, 0);
	else if (keysym == XK_a)
		move(prg, 0, -1);
	else if (keysym == XK_d)
		move(prg, 0, 1);
	else if (keysym == XK_s)
		move(prg, 1, 0);
	print_map(prg);
	return (0);
}


void	sprites_init(t_win *prg)
{
	prg->wall.ptr = mlx_xpm_file_to_image(prg->mlx_ptr, "./sprites/wall.xpm", &(prg->wall.w), &(prg->wall.h));
	prg->player.ptr = mlx_xpm_file_to_image(prg->mlx_ptr, "./sprites/player.xpm", &(prg->player.w), &(prg->player.h));
	prg->player2.ptr = mlx_xpm_file_to_image(prg->mlx_ptr, "./sprites/player.xpm", &(prg->player2.w), &(prg->player2.h));
	prg->floor.ptr = mlx_xpm_file_to_image(prg->mlx_ptr, "./sprites/floor.xpm", &(prg->floor.w), &(prg->floor.h));
	prg->ex.ptr = mlx_xpm_file_to_image(prg->mlx_ptr, "./sprites/exit.xpm", &(prg->ex.w), &(prg->ex.h));
	prg->open.ptr = mlx_xpm_file_to_image(prg->mlx_ptr, "./sprites/open.xpm", &(prg->open.w), &(prg->open.h));
	prg->col.ptr = mlx_xpm_file_to_image(prg->mlx_ptr, "./sprites/collectible.xpm", &(prg->col.w), &(prg->col.h));
}


int	main(void)
{
	t_win	prg;
	

	prg.map = get_map_info("map.ber");
	prg.h = (prg.map.h -1) * 32;
	prg.w = (prg.map.w-1) * 32;

	prg.mlx_ptr = mlx_init();
	prg.win_ptr = mlx_new_window(prg.mlx_ptr, prg.w, prg.h, "test");
	prg.rng = 0;
	sprites_init(&prg);
	
	
	mlx_loop_hook(prg.mlx_ptr, next_frame, &prg);
	mlx_hook(prg.win_ptr, 2, 1L<<2, handle_keypress, &prg);	
	mlx_hook(prg.win_ptr, 17, 1L<<0, exit_prg, &prg);
	mlx_loop(prg.mlx_ptr);
	mlx_destroy_display(prg.mlx_ptr);
	free(prg.mlx_ptr);
}
