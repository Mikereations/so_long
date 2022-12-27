/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:59:25 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/04/21 03:05:57 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(char *error_message, t_game_master *gm)
{
	ft_printf("Error : %s\n", error_message);
	if (gm->map.map != NULL)
		ft_free_map(gm);
	if (gm->map.world_map != NULL)
	{
		mlx_clear_window(gm->world_seed, gm->map.world_map);
		mlx_destroy_window(gm->world_seed, gm->map.world_map);
	}
	if (gm->world_seed != NULL)
		free(gm->world_seed);
	exit(1);
}

int	ft_close(void)
{
	exit(1);
}
