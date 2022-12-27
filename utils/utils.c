/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:59:40 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/04/21 03:11:22 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**fill_map(char **world_map, int line_count, char *name)
{
	int	i;
	int	fd;
	int	line_length;

	i = 0;
	world_map = (char **)malloc((line_count + 1) * sizeof(char *));
	world_map[line_count] = 0;
	fd = open(name, O_RDONLY);
	while (i < line_count)
	{
		world_map[i] = get_next_line(fd);
		line_length = ft_strlen(world_map[i]);
		if (world_map[i][line_length - 1] == '\n')
			world_map[i][line_length - 1] = 0;
		i++;
	}
	world_map[i] = 0;
	return (world_map);
}

char	**ft_reader(char **map, char *name, t_game_master *gm)
{
	int	line_count;
	int	fd;

	if (!name_condition(name))
		ft_error("Invalid map", gm);
	fd = open(name, O_RDONLY);
	line_count = line_reader(fd, gm);
	map = fill_map(map, line_count, name);
	return (map);
}

t_game_master	map_dims(t_game_master gm)
{
	int	i;
	int	length;

	i = 0;
	length = ft_strlen(gm.map.map[i]);
	gm.map.dims.x = length;
	while (gm.map.map[i])
		i++;
	gm.map.dims.y = i;
	return (gm);
}

void	display_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

void	checker(t_game_master *gm, char *name)
{
	char	**map;
	int		swapper;

	map = NULL;
	swapper = 0;
	map = ft_reader(map, name, gm);
	gm->map.map = map;
	if (conditions_met(*gm))
	{
		*gm = map_dims(*gm);
		*gm = setup_player(*gm);
	}
}
