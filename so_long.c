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

void	tiles(t_win *prg)
{
	int	i;
	int	j;

	i = 0;
	while (prg->map.layout[i])
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

void	next_frame_extra(t_win *prg)
{
	if (prg->rng % 20000 == 0)
		enemy_move(prg);
	prg->rng++;
	if (prg->rng > 100000)
		prg->rng = 0;
	if (prg->map.pcoor.x == prg->map.encoor.x
		&& prg->map.pcoor.y == prg->map.encoor.y)
	{
		prg->map = get_map_info(prg->mapargv);
		prg->movec = 0;
	}
}

int	next_frame(t_win *prg)
{
	char	*moves;

	moves = ft_itoa(prg->movec);
	if (prg->rng % 100 == 0)
	{
		mlx_clear_window(prg->mlx_ptr, prg->win_ptr);
		tiles(prg);
		mlx_string_put(prg->mlx_ptr, prg->win_ptr, 20, 20, 1111111,
			moves);
	}
	free(moves);
	next_frame_extra(prg);
	if (prg->map.pcoor.x == prg->map.ecoor.x
		&& prg->map.pcoor.y == prg->map.ecoor.y)
	{
		mlx_string_put(prg->mlx_ptr, prg->win_ptr, prg->w / 2, prg->h / 2,
			1111111, "YOU WIN");
		prg->flag = 0;
	}
	return (1);
}

int	handle_keypress(int keysym, t_win *prg)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(prg->mlx_ptr, prg->win_ptr);
		mlx_destroy_display(prg->mlx_ptr);
		free_stuff(prg);
		exit(0);
	}
	else if (keysym == XK_w && prg->flag)
		move(prg, -1, 0);
	else if (keysym == XK_a && prg->flag)
		move(prg, 0, -1);
	else if (keysym == XK_d && prg->flag)
		move(prg, 0, 1);
	else if (keysym == XK_s && prg->flag)
		move(prg, 1, 0);
	ft_printf("Number of moves: %d\n", prg->movec);
	return (0);
}

int	main(int argc, char **argv)
{
	t_win	prg;

	check_arg(argc, argv, &prg);
	prg.map = get_map_info(prg.mapargv);
	prg.h = (prg.map.h) * 32;
	prg.w = (prg.map.w - 1) * 32;
	prg.mlx_ptr = mlx_init();
	prg.win_ptr = mlx_new_window(prg.mlx_ptr, prg.w, prg.h, "game");
	prg.rng = 0;
	prg.flag = 1;
	prg.enmv = 1;
	prg.movec = 0;
	sprites_init(&prg);
	mlx_loop_hook(prg.mlx_ptr, next_frame, &prg);
	mlx_hook(prg.win_ptr, 2, 1L << 2, handle_keypress, &prg);
	mlx_hook(prg.win_ptr, 17, 1L << 0, exit_prg, &prg);
	mlx_loop(prg.mlx_ptr);
}
