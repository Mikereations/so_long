/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 20:39:12 by aba-nabi          #+#    #+#             */
/*   Updated: 2021/12/28 21:05:50 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		count++;
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
	}
	return (count);
}

static int	lettercount(char *s, int start, char c)
{
	int	i;
	int	count;

	i = start;
	count = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i] != c && s[i])
	{
		i++;
		count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**sentence;
	size_t	i[3];

	i[0] = 0;
	i[2] = 0;
	if (!s)
		return (NULL);
	sentence = (char **)malloc(sizeof(char *) * (wordcount((char *)s, c) + 1));
	if (!sentence)
		return (NULL);
	while (s[i[0]] == c && s[i[0]])
		i[0]++;
	while (s[i[0]])
	{
		sentence[i[2]++] = (char *)malloc(lettercount((char *)s, i[0], c) + 1);
		i[1] = 0;
		while (s[i[0]] != c && s[i[0]])
			sentence[i[2] - 1][i[1]++] = s[i[0]++];
		sentence[i[2] - 1][i[1]] = 0;
		while (s[i[0]] == c && s[i[0]])
			i[0]++;
	}
	sentence[i[2]] = 0;
	return (sentence);
}
