/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:57:40 by ehasalu           #+#    #+#             */
/*   Updated: 2023/02/15 13:50:22 by ehasalu          ###   ########.fr       */
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

int	move(t_win *prg, int dir)
{
	if (dir == 1)
	{
		if (((*prg).map.layout[(*prg).map.pcoor.y + 1][(*prg).map.pcoor.x] != '1')
		&& ((*prg).map.layout[(*prg).map.pcoor.y + 1][(*prg).map.pcoor.x] != 'E'))
		{
			if ((*prg).map.layout[(*prg).map.pcoor.y + 1][(*prg).map.pcoor.x] == 'C')
				(*prg).map.col--;
			if ((*prg).map.layout[(*prg).map.pcoor.y + 1][(*prg).map.pcoor.x] == 'X')
			{
				printf("U WONNERED");	
			}
			(*prg).map.layout[(*prg).map.pcoor.y][(*prg).map.pcoor.x] = '0';
			(*prg).map.layout[(*prg).map.pcoor.y + 1][(*prg).map.pcoor.x] = 'P';
			(*prg).map.pcoor.y++;
		}
	}
	else if (dir == 2)
	{
		if (((*prg).map.layout[(*prg).map.pcoor.y][(*prg).map.pcoor.x - 1] != '1')
		&& ((*prg).map.layout[(*prg).map.pcoor.y][(*prg).map.pcoor.x - 1] != 'E'))
		{
			if ((*prg).map.layout[(*prg).map.pcoor.y][(*prg).map.pcoor.x - 1] == 'C')
				(*prg).map.col--;
			if ((*prg).map.layout[(*prg).map.pcoor.y][(*prg).map.pcoor.x - 1] == 'X')
				printf("U WONNERED");	
			(*prg).map.layout[(*prg).map.pcoor.y][(*prg).map.pcoor.x] = '0';
			(*prg).map.layout[(*prg).map.pcoor.y][(*prg).map.pcoor.x - 1] = 'P';
			(*prg).map.pcoor.x--;
		}
	}
	else if (dir == 3)
	{
		if (((*prg).map.layout[(*prg).map.pcoor.y - 1][(*prg).map.pcoor.x] != '1')
		&&  ((*prg).map.layout[(*prg).map.pcoor.y - 1][(*prg).map.pcoor.x] != 'E'))
		{
			if ((*prg).map.layout[(*prg).map.pcoor.y - 1][(*prg).map.pcoor.x] == 'C')
				(*prg).map.col--;
			if ((*prg).map.layout[(*prg).map.pcoor.y - 1][(*prg).map.pcoor.x] == 'X')
				printf("U WONNERED");
			(*prg).map.layout[(*prg).map.pcoor.y][(*prg).map.pcoor.x] = '0';
			(*prg).map.layout[(*prg).map.pcoor.y - 1][(*prg).map.pcoor.x] = 'P';
			(*prg).map.pcoor.y--;
		}
	}
	else if (dir == 4)
	{
		if (((*prg).map.layout[(*prg).map.pcoor.y][(*prg).map.pcoor.x + 1] != '1')
		&& (*prg).map.layout[(*prg).map.pcoor.y][(*prg).map.pcoor.x + 1] != 'E')
		{
			if ((*prg).map.layout[(*prg).map.pcoor.y][(*prg).map.pcoor.x + 1] == 'C')
				(*prg).map.col--;
			if ((*prg).map.layout[(*prg).map.pcoor.y][(*prg).map.pcoor.x + 1] == 'X')
				printf("U WONNERED");
			(*prg).map.layout[(*prg).map.pcoor.y][(*prg).map.pcoor.x] = '0';
			(*prg).map.layout[(*prg).map.pcoor.y][(*prg).map.pcoor.x + 1] = 'P';
			(*prg).map.pcoor.x++;
		}
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
				mlx_put_image_to_window(prg->mlx_ptr, prg->win_ptr, prg->wall.ptr, (prg->width/prg->map.w)*j, 
				(prg->height/prg->map.h)*i);
			}
			if (prg->map.layout[i][j] == 'P')
			{
				mlx_put_image_to_window(prg->mlx_ptr, prg->win_ptr, prg->wall.ptr, (prg->width/prg->map.w) * prg->map.pcoor.x, 
				(prg->height/prg->map.h) * prg->map.pcoor.y);
			}
			j++;
		}
		i++;
	}
}

int	next_frame(t_win *prg)
{
	mlx_clear_window(prg->mlx_ptr, prg->win_ptr);
	tiles(prg);
}

int	handle_keypress(int keysym, t_win *prg)
{
	if (keysym == XK_Escape)
		exit_prg(prg->win_ptr);		
	else if (keysym == XK_w)
		move(prg, 3);
	else if (keysym == XK_a)
		move(prg, 2);
	else if (keysym == XK_d)
		move(prg, 4);
	else if (keysym == XK_s)
	{
		move(prg, 1);
	}
	//printf("Dog: %d\n", keysym);
	print_map(prg);
	return (0);
}


void	sprites_init(t_win *prg)
{
	prg->wall.ptr = mlx_xpm_file_to_image(prg->mlx_ptr, "wall.xpm", &(prg->wall.w), &(prg->wall.h));
}


int	main(void)
{
	t_win	prg;
	

	prg.height = 600;
	prg.width = 900;
	prg.map = get_map_info("map.ber");
	
	prg.mlx_ptr = mlx_init();
	prg.win_ptr = mlx_new_window(prg.mlx_ptr, prg.width, prg.height, "test");
	
	sprites_init(&prg);
	
	
	mlx_loop_hook(prg.mlx_ptr, next_frame, &prg);
	mlx_hook(prg.win_ptr, 2, 1L<<2, handle_keypress, &prg);	
	mlx_hook(prg.win_ptr, 17, 1L<<0, exit_prg, &prg);
	mlx_loop(prg.mlx_ptr);
	mlx_destroy_display(prg.mlx_ptr);
	free(prg.mlx_ptr);
}
