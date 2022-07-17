/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharouh <mcharouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:11:33 by mcharouh          #+#    #+#             */
/*   Updated: 2022/06/11 19:42:07 by mcharouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	check_dup(t_stuff *extra, t_stack *data)
{
	int	i;
	int	j;

	i = 0;
	sort(extra, data);
	while (extra->sorted_array[i])
	{
		j = i + 1;
		while (j < extra->len)
		{
			if (extra->sorted_array[i] == extra->sorted_array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	sort(t_stuff *extra, t_stack *data)
{
	int	i;
	int	j;
	int	swap;

	j = 0;
	while (j <= extra->len)
	{
		i = 0;
		while (i < extra->len - 1)
		{
			if (extra->sorted_array[i] > extra->sorted_array[i + 1])
			{
				swap = extra->sorted_array[i + 1];
				extra->sorted_array[i + 1] = extra->sorted_array[i];
				extra->sorted_array[i] = swap;
			}
			i++;
		}
		j++;
	}
}
