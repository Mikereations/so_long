/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_condition_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:35:09 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/04/21 03:21:26 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	content_locator(char **map)
{
	char	str[7];
	int		i;

	i = 0;
	ft_memcpy(str, "01CEPA", 7);
	while (str[i])
	{
		if (!locator(map, str[i]) && str[i] != 'A')
			return (0);
		i++;
	}
	i = 0;
	while (i < 127)
	{
		if (ft_strrchr(str, i) == NULL)
		{
			if (locator(map, i))
				return (0);
		}
		i++;
	}
	if (locator(map, 'P') != 1)
		return (0);
	return (1);
}
