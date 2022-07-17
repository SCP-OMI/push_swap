/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharouh <mcharouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:09:19 by mcharouh          #+#    #+#             */
/*   Updated: 2022/07/17 00:01:27 by mcharouh         ###   ########.fr       */
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

void	five_sort(t_stack *stack, t_stuff *extra)
{
	wiggle_small(stack, extra);
	push_stack(stack, 1);
	wiggle_small(stack, extra);
	push_stack(stack, 1);
	three_sort(stack, extra);
	push_stack(stack, 0);
	push_stack(stack, 0);
	
}

void	four_sort(t_stack *stack, t_stuff *extra)
{
	wiggle_small(stack, extra);
	push_stack(stack, 1);
	three_sort(stack, extra);
	push_stack(stack, 0);
}