/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharouh <mcharouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:46:36 by mcharouh          #+#    #+#             */
/*   Updated: 2021/11/27 11:01:52 by mcharouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	p = malloc ((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!(p))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		p[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		p[j++] = s2[i++];
	}
	p[j] = '\0';
	return (p);
}
// #include<stdio.h>
// int main()
// {
// 	char s1[] = "mehdi";
// 	char s2[] = " is a cunt";
// 	printf("%s", ft_strjoin(s1, s2));
// }
