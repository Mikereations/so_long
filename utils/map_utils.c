/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:57:31 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/04/21 03:12:10 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
