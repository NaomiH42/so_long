/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:30:44 by ehasalu           #+#    #+#             */
/*   Updated: 2023/02/20 13:30:47 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_img2(t_win *prg, char idf)
{
	if (idf == 'P' && prg->rng > 5000)
		mlx_put_image_to_window(prg->mlx_ptr, prg->win_ptr, prg->player.ptr,
			(prg->w / prg->map.w) * prg->map.pcoor.x,
			(prg->h / prg->map.h) * prg->map.pcoor.y);
	else if (idf == 'P')
		mlx_put_image_to_window(prg->mlx_ptr, prg->win_ptr, prg->player2.ptr,
			(prg->w / prg->map.w) * prg->map.pcoor.x, (prg->h / prg->map.h)
			* prg->map.pcoor.y);
	else if (idf == 'S' && prg->rng > 50000)
		mlx_put_image_to_window(prg->mlx_ptr, prg->win_ptr, prg->en.ptr,
			(prg->w / prg->map.w) * prg->map.encoor.x,
			(prg->h / prg->map.h) * prg->map.encoor.y);
	else if (idf == 'S')
		mlx_put_image_to_window(prg->mlx_ptr, prg->win_ptr,
			prg->en2.ptr, (prg->w / prg->map.w) * prg->map.encoor.x,
			(prg->h / prg->map.h) * prg->map.encoor.y);
}

void	show_img(t_win *prg, char idf, int i, int j)
{
	if (idf == 'C' && prg->rng > 5000)
		mlx_put_image_to_window(prg->mlx_ptr, prg->win_ptr, prg->col.ptr,
			(prg->w / prg->map.w) * j, (prg->h / prg->map.h) * i);
	else if (idf == 'C')
		mlx_put_image_to_window(prg->mlx_ptr, prg->win_ptr, prg->col2.ptr,
			(prg->w / prg->map.w) * j, (prg->h / prg->map.h) * i);
	else if (idf == '1')
		mlx_put_image_to_window(prg->mlx_ptr, prg->win_ptr, prg->wall.ptr,
			(prg->w / prg->map.w) * j, (prg->h / prg->map.h) * i);
	else if (idf == '0')
		mlx_put_image_to_window(prg->mlx_ptr, prg->win_ptr, prg->floor.ptr,
			(prg->w / prg->map.w) * j, (prg->h / prg->map.h) * i);
	else if (idf == 'E')
		mlx_put_image_to_window(prg->mlx_ptr, prg->win_ptr, prg->ex.ptr,
			(prg->w / prg->map.w) * j, (prg->h / prg->map.h) * i);
	else if (idf == 'X')
		mlx_put_image_to_window(prg->mlx_ptr, prg->win_ptr, prg->open.ptr,
			(prg->w / prg->map.w) * j, (prg->h / prg->map.h) * i);
	show_img2(prg, idf);
}

void	dog_or_not_dog(t_win *prg)
{
	if (prg->dog == 1)
	{
		prg->player.ptr = mlx_xpm_file_to_image(prg->mlx_ptr,
				"./sprites/dog.xpm", &(prg->player.w), &(prg->player.h));
		prg->player2.ptr = mlx_xpm_file_to_image(prg->mlx_ptr,
				"./sprites/dog.xpm", &(prg->player.w), &(prg->player.h));
	}
	else
	{
		prg->player.ptr = mlx_xpm_file_to_image(prg->mlx_ptr,
				"./sprites/player.xpm",
				&(prg->player.w), &(prg->player.h));
		prg->player2.ptr = mlx_xpm_file_to_image(prg->mlx_ptr,
				"./sprites/player2.xpm", &(prg->player2.w), &(prg->player2.h));
	}
}

void	sprites_init(t_win *prg)
{
	prg->wall.ptr = mlx_xpm_file_to_image(prg->mlx_ptr, "./sprites/wall.xpm",
			&(prg->wall.w), &(prg->wall.h));
	dog_or_not_dog(prg);
	prg->floor.ptr = mlx_xpm_file_to_image(prg->mlx_ptr, "./sprites/floor.xpm",
			&(prg->floor.w), &(prg->floor.h));
	prg->ex.ptr = mlx_xpm_file_to_image(prg->mlx_ptr, "./sprites/exit.xpm",
			&(prg->ex.w), &(prg->ex.h));
	prg->open.ptr = mlx_xpm_file_to_image(prg->mlx_ptr, "./sprites/open.xpm",
			&(prg->open.w), &(prg->open.h));
	prg->col.ptr = mlx_xpm_file_to_image(prg->mlx_ptr,
			"./sprites/collectible.xpm",
			&(prg->col.w), &(prg->col.h));
	prg->col2.ptr = mlx_xpm_file_to_image(prg->mlx_ptr,
			"./sprites/collectible2.xpm",
			&(prg->col2.w), &(prg->col2.h));
	prg->en.ptr = mlx_xpm_file_to_image(prg->mlx_ptr, "./sprites/enemy.xpm",
			&(prg->en.w), &(prg->en.h));
	prg->en2.ptr = mlx_xpm_file_to_image(prg->mlx_ptr, "./sprites/enemy1.xpm",
			&(prg->en2.w), &(prg->en2.h));
}
