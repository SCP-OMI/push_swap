/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharouh <mcharouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:09:19 by mcharouh          #+#    #+#             */
/*   Updated: 2022/07/27 12:31:14 by mcharouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	three_sort(t_stack *stack, t_stuff *extra)
{
	int one;
	int	two;
	int	three;

	one = stack->arra[0];
	two = stack->arra[1];
	three = stack->arra[2];
	
	if ((one > two) && (two < three) && (one < three))
		swap(stack, 0);
	else if ((one > two) && (two > three))
	{
		swap(stack, 0);
		reverse_rotate(stack, extra, 0);
	}
	else if ((one < two) && (two > three) && (one < three))
	{
		swap(stack, 0);
		rotate(stack, extra, 0);
	}
	else if ((one > two) && (two < three) && (one > three))
		rotate(stack, extra, 0);
	else if ((one < two) && (two > three))
		reverse_rotate(stack, extra, 0);
}

void	mid_sort(t_stack *stack, t_stuff *extra)
{
	int count;
	int relay;
	relay = 0;
	count = stack->sizea;
	while (count != 3)
	{
		wiggle_small(stack, extra);
		push(stack, 1);
		count--;
		relay++;
	}
	three_sort(stack, extra);
	while (relay != 0)
	{
		push(stack, 0);
		relay--;
	}	
}
