/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_so_small_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharouh <mcharouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 19:42:02 by mcharouh          #+#    #+#             */
/*   Updated: 2022/08/09 22:21:27 by mcharouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	chunk_sort(t_stack *stack, t_stuff *extra)
{
	chunk_utils(stack, extra);
	while (stack->sizea != 0)
	{
		while (stack->sizeb != (stack->end - stack->start))
		{
			if (stack->arra[0] >= extra->sorted_array[stack->start]
				&& stack->arra[0] <= extra->sorted_array[stack->end - 1])
			{
				push(stack, 1);
				if (stack->arrb[0] < extra->sorted_array[stack->middle])
					rotate(stack, extra, 1);
			}
			else
				rotate(stack, extra, 0);
		}
		offset_adjust(stack, extra);
	}
	chunk_sort_v2(stack, extra);
}

void	chunk_sort_v2(t_stack *stack, t_stuff *extra)
{
	stack->last_index = extra->len - 1;
	stack->down = 0;
	while (stack->sizeb > 0 || stack->down != 0)
	{
		extra->mvi = check_max_val_index(stack, extra);
		if (extra->mvi != -1)
			cont(stack, extra);
		else
		{
			if (stack->down > 0)
			{
				reverse_rotate(stack, extra, 0);
				stack->down--;
				stack->last_index--;
			}
		}
	}
}

int	check_max_val_index(t_stack *stack, t_stuff *extra)
{
	int	i;

	i = 0;
	while (i < stack->sizeb)
	{
		if (extra->sorted_array[stack->last_index] == stack->arrb[i])
			return (i);
		i++;
	}
	return (-1);
}

void	cont(t_stack *stack, t_stuff *extra)
{
	if (extra->sorted_array[stack->last_index] == stack->arrb[0])
	{
		push(stack, 0);
		stack->last_index--;
	}
	else if (stack->down == 0
		|| stack->arrb[0] > stack->arra[stack->sizea - 1])
	{
		push(stack, 0);
		rotate(stack, extra, 0);
		stack->down++;
	}
	else if (extra->mvi <= stack->sizeb / 2)
	{
		rotate(stack, extra, 1);
	}
	else if (extra->mvi > stack->sizeb / 2)
		reverse_rotate(stack, extra, 1);
}
