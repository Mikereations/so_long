/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 01:25:37 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/04/21 03:12:26 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	line_cutter(t_game_master *gm, t_point *p, t_point *pos)
{
	t_point	ps;

	ps = gm->player.pos;
	if (gm->map.map[p->y][p->x - 1] == '0'
	|| (p->y == ps.y && p->x - 1 == ps.x))
		pos->x = p->x - 1;
	else if (gm->map.map[p->y - 1][p->x] == '0'
	|| (p->y - 1 == ps.x && p->y == ps.x))
		pos->y = p->y - 1;
	else if (gm->map.map[p->y][p->x + 1] == '0'
	|| (p->y == ps.y && p->x + 1 == ps.x))
		pos->x = p->x + 1;
	else if (gm->map.map[p->y + 1][p->x] == '0'
	|| (p->y + 1 == ps.y && p->x == ps.x))
		pos->y = p->y + 1;
}

int	check_mate(t_game_master *gm, int *i, int *j, t_point *pos)
{
	t_point	p;

	if (gm->map.map[*i][*j] == 'A')
	{
		p.x = *j;
		p.y = *i;
		line_cutter(gm, &p, pos);
		*i = p.y;
		*j = p.x;
		if (pos->y == gm->player.pos.y && pos->x == gm->player.pos.x)
		{
			init_loss(gm, 250, pos->x, pos->y);
			return (1);
		}
		else if (pos->x != *j || pos->y != *i)
		{
			gm->map.map[pos->y][pos->x] = 'A';
			gm->map.map[*i][*j] = '0';
			fotographer(gm, "./images/grass.xpm", *j * 75, *i * 75);
			fotographer(gm, "./images/EIdle.xpm", pos->x * 75, pos->y * 75);
		}
	}
	return (0);
}

void	move_locator(t_game_master *gm, t_point *pos, int *x, int *y)
{
	if ((*gm).map.map[*y][*x] == 'A')
	{
		init_loss(gm, 250, pos->x, pos->y);
		return ;
	}
	fotographer(gm, "./images/grass.xpm", pos->x * 75, pos->y * 75);
	if ((*gm).map.map[*y][*x] == 'C')
	{
		gm->cs -= 1;
		(*gm).map.map[*y][*x] = 'D';
		fotographer(gm, "./images/D.xpm", *x * 75 + 15, *y * 75);
	}
	if ((*gm).map.map[pos->y][pos->x] == 'D')
		fotographer(gm, "./images/D.xpm", pos->x * 75 + 15, pos->y * 75);
	fotographer(gm, "./images/Idle.xpm", *x * 75, *y * 75);
	if ((*gm).map.map[pos->y][pos->x] == 'E')
		fotographer(gm, "./images/ang2.xpm", pos->x * 75, pos->y * 75 - 45);
	if ((*gm).map.map[pos->y + 1][pos->x] == 'E')
		fotographer(gm, "./images/ang2.xpm",
			pos->x * 75, (pos->y + 1) * 75 - 45);
	if (pos->x != *x || pos->y != *y)
		gm->moves += 1;
	(*gm).player.pos.x = *x;
	(*gm).player.pos.y = *y;
}
