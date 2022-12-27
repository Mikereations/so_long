/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 01:23:28 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/04/21 03:07:25 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	populate_world(t_game_master *gm)
{
	int	i;
	int	j;

	i = 0;
	while (gm->map.map[i])
	{
		j = 0;
		while (gm->map.map[i][j])
		{
			if (gm->map.map[i][j] == '1')
				fotographer(gm, "./images/fence.xpm", j * 75, i * 75);
			else
				fotographer(gm, "./images/grass.xpm", j * 75, i * 75);
			if (gm->map.map[i][j] == 'E')
				fotographer(gm, "./images/ang2.xpm", j * 75, i * 75 - 45);
			if (gm->map.map[i][j] == 'C')
				fotographer(gm, "./images/collectable.xpm",
					j * 75 + 15, i * 75);
			if (gm->map.map[i][j] == 'A')
				fotographer(gm, "./images/EIdle.xpm", j * 75 + 15, i * 75);
			j++;
		}
		i++;
	}
}

int	ft_key_event(int keycode, t_game_master *gm)
{
	int		x;
	int		y;
	t_point	pos;

	x = (*gm).player.pos.x;
	y = (*gm).player.pos.y;
	pos.x = x;
	pos.y = y;
	if (keycode == 53)
		game_stop(gm);
	if (keycode == 0)
		x -= 1;
	if (keycode == 13)
		y -= 1;
	if (keycode == 2)
		x += 1;
	if (keycode == 1)
		y += 1;
	if ((*gm).map.map[y][x] != '1' && !gm->finished)
		move_locator(gm, &pos, &x, &y);
	if ((*gm).map.map[y][x] == 'E')
		game_won(gm, 250);
	display_numbers(gm);
	return (0);
}

static void	ctw(int x, int y, char *name, t_game_master *gm)
{
	void	*world_map;

	world_map = mlx_new_window(gm->world_seed, x, y + 75, name);
	gm->map.world_map = world_map;
	gm->world_bounds.x = x;
	gm->world_bounds.y = y;
	populate_world(gm);
	mlx_put_image_to_window(gm->world_seed, gm->map.world_map,
		gm->player.player.image, gm->player.pos.x * 75, gm->player.pos.y * 75);
	mlx_hook(gm->map.world_map, 17, 0, &game_stop, gm);
	display_numbers(gm);
	gm->cs = locator(gm->map.map, 'C');
}

int	frames(t_game_master *gm)
{
	int	x;
	int	y;

	x = gm->player.pos.x;
	y = gm->player.pos.y;
	gm->frames += 1;
	patrol(gm, gm->frames);
	if (gm->finished == 0)
	{
		if (gm->frames % 750 == 0)
		{
			fotographer(gm, "./images/grass.xpm", x * 75, y * 75);
			if (gm->frames % 1500 == 0)
				gm->player.player.image = fotographer(gm, "./images/idle2.xpm",
						x * 75, y * 75);
			else
				gm->player.player.image = fotographer(gm, "./images/idle.xpm",
						x * 75, y * 75);
		}
	}
	else if (gm->finished == 1)
		game_won(gm, gm->frames);
	return (gm->frames);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_error("Invalid number of arguments", NULL);
	g_master.world_seed = mlx_init();
	checker(&g_master, argv[1]);
	g_master.finished = 0;
	g_master.frames = 0;
	g_master.moves = 0;
	if (!g_master.world_seed)
		ft_error("The world seed wasn't initiallised", &g_master);
	ctw(g_master.map.dims.x * 75, g_master.map.dims.y * 75,
		"The creation", &g_master);
	if (!g_master.map.world_map)
		ft_error("The world map failed to be created", &g_master);
	mlx_key_hook(g_master.map.world_map, &ft_key_event, &g_master);
	mlx_loop_hook(g_master.world_seed, &frames, &g_master);
	mlx_loop(g_master.world_seed);
	return (0);
}
