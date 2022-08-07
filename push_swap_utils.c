/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharouh <mcharouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:52:51 by mcharouh          #+#    #+#             */
/*   Updated: 2022/08/07 02:03:44 by mcharouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	check_if_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->sizea - 1)
	{
		if (stack->arra[i] > stack->arra[i + 1])
			break ;
		i++;
	}
	if (i == stack->sizea - 1)
	{	
		write(2, "Error: Your shit is sorted already\n", 35);
		exit (0);
	}
}

void	push_swap_algo(t_stack *stack, t_stuff *extra)
{
	if (extra->len == 2)
		two_sort(stack, extra);
	if (extra->len == 3)
		three_sort(stack, extra);
	else if (extra->len >= 4 && extra->len <= 15)
		mid_sort(stack, extra);
	else if (extra->len > 15)
		chunk_sort(stack, extra);
}

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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
