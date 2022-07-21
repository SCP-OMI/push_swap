/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_so_small_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharouh <mcharouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 19:42:02 by mcharouh          #+#    #+#             */
/*   Updated: 2022/07/21 03:07:36 by mcharouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	chunk_sort(t_stack *stack, t_stuff *extra)
{
	chunk_utils(stack, extra);
	
	while (stack->sizea != 0)
	{
		while (stack->sizeb < stack->end - stack->start + 1)
		{
			if (stack->arra[0] >= extra->sorted_array[stack->start]
			&& stack->arra[0] <= extra->sorted_array[stack->end])
				{
					push_stack(stack, 1);
					if (stack->arrb[0] >= extra->sorted_array[stack->start] 
					&& stack->arrb[0] < extra->sorted_array[stack->middle])
					rotate(stack, extra, 1);
				}
				else
					rotate(stack, extra, 0);
		}
		offset_adjust(stack, extra);
		chunk_sort_V2(stack, extra);
	}
}

void	chunk_sort_V2(t_stack *stack, t_stuff *extra)
{

		stack->last_index = stack->sizea - 1;
		stack->down = 0;
		while (stack->sizeb != 0 || stack->down != 0)
		{
			extra->ret = check_max_val(stack, extra);
			if (extra->ret != -1)
				cont(stack, extra);
			else
			{
				if (stack->down > 0)
				{
					reverse_rotate(stack, extra, 0);
					stack->down--;
					stack->last_index;
				}
			}
		}
}

int	check_max_val(t_stack *stack, t_stuff *extra)
{
	int i;

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
	while (1)
	{
		if (extra->sorted_array[stack->last_index] == stack->arrb[0])
		{
			push_stack(stack, 0);
			stack->last_index--;
			return ;
		}
		if (stack->down == 0 || stack->arrb[0] > stack->arra[stack->sizea - 1])
		{
			push_stack(stack, 0);
			rotate(stack, extra, 0);
			stack->down++;
		}
		else if (extra->ret <= stack->sizeb / 2)
			rotate(stack, extra, 1);
		else if (extra->ret > stack->sizeb / 2)
			reverse_rotate(stack, extra, 1);
		
	}
}