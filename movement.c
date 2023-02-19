#include "so_long.h"

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


void	error_msg(int nb)
{
	if (nb == 1)
		printf("ERROR\nMAP IS NOT RECTANGULAR\n");
	else if (nb == 2)
		printf("ERROR\nMAP IS NOT SURROUNDED BY WALLS\n");
	else if (nb == 3)
		printf("ERROR\nMAP CONTAINS INVALID NUMBER OF GAME OBJECTS\n");
	else if (nb == 4)
		printf("ERROR\nMAP DOESN'T CONTAIN VALID PATH\n");
	exit (0);

}

t_map	map_init(t_map map)
{
	map.layout = NULL;
	(map.h) = 0;
	(map.w) = 0;
	(map.col) = 0;
	(map.ex) = 0;
	map.st = 0;
	map.pcoor.x = 0;
	map.pcoor.y = 0;
	map.ecoor.x = 0;
	map.ecoor.y = 0;
	map.encoor.y = 0;
	map.encoor.y = 0;
	return (map);
}
