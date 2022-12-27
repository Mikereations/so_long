/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conclusions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 00:30:25 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/04/21 03:12:42 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_loss(t_game_master *gm, int frame, int x, int y)
{
	gm->finished = -1;
	gm->frames = frame;
	display_numbers(gm);
	fotographer(gm, "./images/grass.xpm", x * 75, y * 75);
	if (frame % 280 == 0)
		game_stop(gm);
	else if (frame % 270 == 0)
		fotographer(gm, "./images/death2.xpm", x * 75, y * 75);
	else if (frame % 260 == 0)
		fotographer(gm, "./images/death1.xpm", x * 75, y * 75);
	else if (frame % 250 == 0)
		fotographer(gm, "./images/Idle.xpm", x * 75, y * 75);
}

int	game_stop(t_game_master *gm)
{
	if (gm->map.map)
		ft_free_map(&(*gm));
	if (gm->player.player.image)
		mlx_destroy_image(gm->world_seed, gm->player.player.image);
	printf("Game Finished!\nTotal Moves: %d\n\n", gm->moves);
	if (gm->map.world_map != NULL)
	{
		mlx_clear_window(gm->world_seed, gm->map.world_map);
		mlx_destroy_window(gm->world_seed, gm->map.world_map);
	}
	if (gm->world_seed != NULL)
		free(gm->world_seed);
	exit(0);
	return (0);
}

void	game_won(t_game_master *gm, int frame)
{
	t_point	pos;

	pos = gm->player.pos;
	gm->frames = frame;
	display_numbers(gm);
	if (gm->cs != 0)
		return ;
	gm->finished = 1;
	if (frame % 450 == 0)
		game_stop(gm);
	else if (frame % 350 == 0)
		fotographer(gm, "./images/ang4.xpm", pos.x * 75, pos.y * 75 - 45);
	else if (frame % 300 == 0)
		fotographer(gm, "./images/ang3.xpm", pos.x * 75, pos.y * 75 - 45);
	else if (frame % 250 == 0)
		fotographer(gm, "./images/ang2.xpm", pos.x * 75, pos.y * 75 - 45);
	mlx_put_image_to_window(gm->world_seed, gm->map.world_map,
		gm->player.player.image, pos.x * 75, pos.y * 75);
}

void	ft_free_map(t_game_master *gm)
{
	int	i;

	i = 0;
	while (gm->map.map[i])
	{
		free(gm->map.map[i]);
		i++;
	}
	free(gm->map.map[i]);
	free(gm->map.map);
}
