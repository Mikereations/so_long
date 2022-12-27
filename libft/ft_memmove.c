/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:04:40 by aba-nabi          #+#    #+#             */
/*   Updated: 2021/12/22 13:08:20 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		idx;

	idx = 0;
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	while (src < dst && len-- > 0)
		ft_memcpy(&dst[len], &src[len], 1);
	return (dst);
}
