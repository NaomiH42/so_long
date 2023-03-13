/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:27:08 by ehasalu           #+#    #+#             */
/*   Updated: 2023/02/20 13:27:09 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_prg(t_win *prg)
{
	if (prg)
	{
		mlx_destroy_window(prg->mlx_ptr, prg->win_ptr);
		mlx_destroy_display(prg->mlx_ptr);
		free_stuff(prg);
	}
	exit(0);
}

void	function_that_does_stuff(t_map *map, int i, int l)
{
	(*map).ex++;
	(*map).ecoor.x = l;
	(*map).ecoor.y = i;
}
