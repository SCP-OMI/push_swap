/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpersV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharouh <mcharouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:35:17 by mcharouh          #+#    #+#             */
/*   Updated: 2022/07/17 22:15:15 by mcharouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_strlon(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	chunk_utils(t_stack *stack, t_stack *extra)
{
	stack->middle = stack->sizea / 2;
	if (stack->sizea <= 10)
		stack->offset = stack->sizea / 5;
	else if (stack->sizea > 10 && stack->sizea <= 150)
		stack->offset = stack->sizea / 8;
	else if (stack->sizea > 150)
		stack->offset = stack->sizea / 18;
	stack->start = stack->middle - stack->offset;
	stack->end = stack->middle + stack->offset;
	
}
