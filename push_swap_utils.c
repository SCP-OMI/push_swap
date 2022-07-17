/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharouh <mcharouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:52:51 by mcharouh          #+#    #+#             */
/*   Updated: 2022/07/17 22:10:29 by mcharouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int check_if_sorted(t_stack *stack)
{
	int i;
	
	i = 0;
	while(i < stack->sizea - 1)
	{
		if (stack->arra[i] > stack->arra[i + 1])
			break;
		i++;
	}
	if (i == stack->sizea - 1)
	{	
		write(2, "Your shit is sorted already\n", 28);
		exit (0);
	}
}

void	push_swap_algo(t_stack *stack, t_stuff *extra)
{
	if (extra->len == 3)
		three_sort(stack, extra);
	else if (extra->len == 4)
		four_sort(stack, extra);
	else if (extra->len == 5)
		five_sort(stack, extra);
	else if (extra->len > 5)
		chunk_sort(stack, extra);
	
}