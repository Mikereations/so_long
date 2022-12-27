/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:58:33 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/04/21 03:18:02 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	inner_loop(t_game_master *gm, t_point *p, char **map)
{
	p->y = 0;
	while ((*gm).map.map[p->y] != 0)
	{
		if ((*gm).map.map[p->y][p->x])
			map[p->x][p->y] = (*gm).map.map[p->y][p->x];
		else
			break ;
		p->y++;
	}
}

static t_game_master	invert(t_game_master gm)
{
	char	**inverted;
	t_point	p;

	p = gm.map.dims;
	inverted = (char **)malloc((p.x + 1) * sizeof(char *));
	p.x = 0;
	while (gm.map.map[0][p.x])
		inverted[p.x++] = (char *)malloc(p.y + 1);
	p.x = 0;
	while (gm.map.map[0][p.x])
	{
		inner_loop(&gm, &p, inverted);
		inverted[p.x][p.y] = 0;
		p.x++;
	}
	inverted[p.x] = 0;
	ft_free_map(&gm);
	gm.map.map = inverted;
	return (gm);
}

static int	check_walls(t_game_master gm)
{
	int	i;
	int	length;
	int	j;

	j = 0;
	while (j < 2)
	{
		i = 0;
		length = ft_strlen(gm.map.map[i]);
		gm.map.dims.x = length;
		while (gm.map.map[i])
		{
			if (gm.map.map[i][0] != '1' || gm.map.map[i][length - 1] != '1')
				return (0);
			i++;
		}
		gm.map.dims.y = i;
		gm = invert(gm);
		j++;
	}
	return (1);
}

static int	check_lines(t_game_master gm)
{
	int	i;
	int	length;
	int	j;

	j = 0;
	while (j < 2)
	{
		i = 0;
		length = ft_strlen(gm.map.map[i]);
		gm.map.dims.x = length;
		while (gm.map.map[i])
		{
			if (ft_strlen(gm.map.map[i]) != length)
				return (0);
			i++;
		}
		j++;
		gm.map.dims.y = i;
		gm = invert(gm);
	}
	return (1);
}

int	wall_condition(t_game_master gm)
{
	if (!gm.map.map)
	{
		ft_printf("Empty map\n");
		return (0);
	}
	if (!check_lines(gm))
	{
		ft_printf("Wrong lines\n");
		return (0);
	}
	if (!check_walls(gm))
	{
		ft_printf("Wrong walls\n");
		return (0);
	}
	return (1);
}
