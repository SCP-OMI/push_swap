/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharouh <mcharouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 22:02:30 by mcharouh          #+#    #+#             */
/*   Updated: 2022/08/02 22:35:34 by mcharouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	wiggle_big(t_stack *stack, t_stuff *extra)
{
	while (stack->arra[0] != stack->big_num)
	{
		if (stack->big_index > 2)
			reverse_rotate(stack, extra, 0);
		else if (stack->big_index < 3)
			rotate(stack, extra, 0);
	}
}

void	wiggle_small(t_stack *stack, t_stuff *extra)
{
	fetch(stack);
	while (stack->arra[0] != stack->small_num)
	{
		if (stack->small_index < 3)
			rotate(stack, extra, 0);
		else if (stack->small_index > 2)
			reverse_rotate(stack, extra, 0);
	}
}

void	fetch(t_stack *stack)
{
	int i;
	
	stack->small_num = stack->arra[0];
	i = 0;
	while (i < stack->sizea)
	{
		if (stack->small_num > stack->arra[i])
			stack->small_num = stack->arra[i];
		i++;
	}
	stack->small_index = i;
	stack->big_num = stack->arra[0];
	i = 0;
	while (i < stack->sizea - 1)
	{
		if (stack->big_num < stack->arra[i])
			stack->big_num = stack->arra[i];
		i++;
	}
}

void	small_index(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->sizea - 1)
	{
		if (stack->arra[i] == stack->small_num)
			break ;
		i++;
	}
	stack->small_index = i;
}

void	big_index(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->sizea - 1)
	{
		if (stack->arra[i] == stack->big_num)
			break ;
		i++;
	}
	stack->big_index = i;
}
