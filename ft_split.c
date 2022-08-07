/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharouh <mcharouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:15:24 by ahamdy            #+#    #+#             */
/*   Updated: 2022/08/07 17:12:43 by mcharouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	word_count(char const *s, char c)
{
	long	i;
	long	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		while (s[i] && s[i] != c)
			i++;
		count++;
	}
	return (count);
}

static int	ft_free(char **split, long j)
{
	if (split[j])
		return (0);
	while (j--)
		free(split[j]);
	free(split);
	split = 0;
	return (1);
}

static void	char_count(const char *s, char c, char	**split)
{
	long	count;
	long	i;
	long	j;

	count = 0;
	j = 0;
	i = 0;
	while (s[i])
	{
		count = 0;
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		while (s[i + count] && s[i + count] != c)
			count++;
		split[j] = ft_substr(s, i, count);
		if (ft_free(split, j))
			return ;
		i += count;
		j++;
	}
	split[j] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	long	count;

	if (!s)
		return (NULL);
	count = word_count(s, c);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	char_count(s, c, split);
	if (!split)
		return (0);
	return (split);
}
