/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:59:34 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/04/21 03:17:08 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_game_master	locate_player(t_game_master gm)
{
	int	x;
	int	y;

	y = 0;
	while (gm.map.map[y])
	{
		x = 0;
		while (gm.map.map[y][x])
		{
			if (gm.map.map[y][x] == 'P')
			{
				gm.player.pos.x = x;
				gm.player.pos.y = y;
				return (gm);
			}
			x++;
		}
		y++;
	}
	return (gm);
}

t_game_master	setup_player(t_game_master gm)
{
	int		width;
	int		height;
	void	*img;

	gm = locate_player(gm);
	img = NULL;
	img = mlx_xpm_file_to_image(gm.world_seed,
			"./images/idle2.xpm", &width, &height);
	if (!img)
		ft_error("The image of the player wasn't loaded successfully", &gm);
	gm.player.player.image = img;
	gm.player.player.dims.x = width;
	gm.player.player.dims.y = height;
	return (gm);
}

int	locator(char **map, char character)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == character)
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

int	line_reader(int fd, t_game_master *gm)
{
	int		lines;
	char	*line;

	lines = 0;
	line = get_next_line(fd);
	while (line && line[0])
	{
		lines++;
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	if (!lines)
		ft_error("The file does't contain lines", gm);
	return (lines);
}
