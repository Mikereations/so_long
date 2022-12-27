/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:54:31 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/04/21 03:11:41 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	conditions_met(t_game_master gm)
{
	if (!wall_condition(gm))
	{
		ft_error("The wall condition wasn't met", &gm);
	}
	else if (!content_locator(gm.map.map))
	{
		ft_error("The content doesnt satisfy the conditions", &gm);
	}
	return (1);
}

int	name_condition(char *name)
{
	int		i;
	int		j;
	char	ber[5];

	if (ft_strlen(name) < 5)
		return (0);
	i = ft_strlen(name) - 4;
	j = 0;
	ft_memcpy(ber, ".ber", 5);
	while (name[i])
	{
		if (ber[j] != name[i])
			return (0);
		i++;
		j++;
	}
	return (1);
}
