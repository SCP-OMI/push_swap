/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharouh <mcharouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:09:19 by mcharouh          #+#    #+#             */
/*   Updated: 2022/05/18 18:50:07 by mcharouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void small_sort(t_stack *stack)
{
	if(stack->arra[0] > stack->arra[1])
	{
		if (stack->arra[1] < stack->arra[2])
			swap(&stack, 0);
	}
			reverse_rotate(&stack, 0);

}