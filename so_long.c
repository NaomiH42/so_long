/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:57:40 by ehasalu           #+#    #+#             */
/*   Updated: 2023/02/12 18:44:35 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/keysym.h>
#include <X11/X.h>

typedef struct	s_prg
{
	void	*mlx;
	void	*win;
}	t_prg;

typedef struct	s_image
{
	void	*pointer;
	int	size_x;
	int	size_y;
	char	*pixels;
	int	bits_per_pixel;
	int	line_size;
	int	endian;
}	t_image;

t_image	new_sprite(void *prg, char *path)
{
	t_image	img;

	img.pointer = mlx_xpm_file_to_image(prg, path, &img.size_x, &img.size_y);
	img.pixels = mlx_get_data_addr(img.pointer, & img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}

int	handle_no_event(void *prg)
{
	return (0);
}

int	handle_keypress(int keysym, t_prg prg)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(prg.mlx, prg.win);
	else if (keysym == XK_w)
		printf("up");
	else if (keysym == XK_a)
		printf("left");
	else if (keysym == XK_d)
		printf("right");
	else if (keysym == XK_s)
		printf("down");
	printf("Keypress: %d\n", keysym);
	return (0);
}

int	main(void)
{
	t_prg	prg;

	prg.mlx = mlx_init();
	prg.win = mlx_new_window(prg.mlx, 500, 500, "test");
	mlx_loop_hook(prg.mlx, &handle_no_event, &prg);
	mlx_hook(prg.win, KeyPress, KeyPressMask, &handle_keypress, &prg);	


	mlx_loop(prg.mlx);
	mlx_destroy_display(prg.mlx);
	free(prg.mlx);
}
