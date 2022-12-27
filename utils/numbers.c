/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 03:43:26 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/04/21 03:12:04 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_numbers(t_game_master *gm)
{
	char	*moves;
	char	digit[15];
	int		len;
	int		i;

	i = 0;
	moves = ft_itoa(gm->moves);
	len = ft_strlen(moves);
	ft_printf("Moves: %s\n", moves);
	ft_strlcpy(digit, "./images/0.xpm", 15);
	while (i < len)
	{
		digit[9] = moves[i];
		fotographer(gm, digit, gm->map.dims.x * 75 / 2 + i * 20,
			(gm->map.dims.y) * 75 + 10);
		i++;
	}
	free(moves);
}

void	*fotographer(t_game_master *gm, char *picture, int x, int y)
{
	int		size;
	void	*img;

	img = mlx_xpm_file_to_image(gm->world_seed, picture, &size, &size);
	mlx_put_image_to_window(gm->world_seed, gm->map.world_map,
		img, x, y);
	return (img);
}

void	patrol(t_game_master *gm, int frame)
{
	int		i;
	int		j;
	t_point	pos;
	t_point	ppos;

	i = 0;
	ppos = gm->player.pos;
	if (gm->finished < 0)
		init_loss(gm, frame, ppos.x, ppos.y);
	else if (frame % 5000 == 0)
	{
		while (gm->map.map[i])
		{
			j = 0;
			while (gm->map.map[i][j])
			{
				pos.x = j;
				pos.y = i;
				if (check_mate(gm, &i, &j, &pos))
					return ;
				j = pos.x + 1;
			}
			i++;
		}
	}
}
