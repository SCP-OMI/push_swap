/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharouh <mcharouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:46:26 by mcharouh          #+#    #+#             */
/*   Updated: 2021/11/27 11:00:49 by mcharouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	i = 0;
	while (s[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	while (i >= 0)
	{
		dest[i] = s[i];
		i--;
	}
	return (dest);
}
// #include<stdio.h>
// int main ()
// {
// 	char s[] = "This is a test subject";
// 	printf("%s", ft_strdup(s));
// }