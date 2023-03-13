/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:25:35 by ehasalu           #+#    #+#             */
/*   Updated: 2023/02/20 13:25:37 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dog_check(char *str, t_win *prg)
{
	if (str[0] && str[0] == 'd')
	{
		if (str[1] && str[1] == 'o')
		{
			if (str[2] && str[2] == 'g' && !str[3])
			{
				prg->dog = 1;
			}
		}
	}
	else
		prg->dog = 0;
}

int	ber_check(char *str)
{
	int	len;
	int	res;

	res = 1;
	len = ft_strlen(str);
	if (str[len - 1] != 'r')
		res = 0;
	if (str[len - 2] != 'e')
		res = 0;
	if (str[len - 3] != 'b')
		res = 0;
	if (str[len - 4] != '.')
		res = 0;
	return (res);
}

void	free_imgs(t_win *prg)
{
	free(prg->wall.ptr);
	free(prg->player.ptr);
	free(prg->player2.ptr);
	free(prg->floor.ptr);
	free(prg->open.ptr);
	free(prg->ex.ptr);
	free(prg->col.ptr);
	free(prg->col2.ptr);
	free(prg->en.ptr);
	free(prg->en2.ptr);
}

void	free_stuff(t_win *prg)
{
	int	i;

	i = 0;
	free(prg->mlx_ptr);
	while (prg->map.layout[i])
	{
		free(prg->map.layout[i]);
		free(prg->map.layouttest[i]);
		i++;
	}
	free(prg->map.layout[i]);
	free(prg->map.layouttest[i]);
	free(prg->map.layout);
	free(prg->map.layouttest);
	free_imgs(prg);
}

void	check_arg(int argc, char **argv, t_win *prg)
{
	prg->dog = 0;
	if (argc > 2)
	{
		ft_printf("Only the first argument will be taken into account\n");
		dog_check(argv[2], prg);
	}
	if (argc == 1)
	{
		ft_printf("You need to input a map file.\n");
		exit(0);
	}
	if (ber_check(argv[1]) == 0)
	{
		ft_printf("File is not correct .ber format\n");
		exit(0);
	}
	prg->mapargv = argv[1];
}
