/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharouh <mcharouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:52:51 by mcharouh          #+#    #+#             */
/*   Updated: 2022/05/18 22:38:44 by mcharouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void check_if_sorted(t_stack *stack)
{
	int tmp;
	int i;
	
	i = 0;
	while(stack->arra[i])
	{
		tmp = stack->arra[i];
		stack->arra[i] = stack->arra[i + 1];
		if (tmp < stack->arra[i])
		{
			write(1, "error", 5);
			exit(0);
		}		
	}
}

void fill_my_stack(t_stack *stack, char *str)
{
	int i;
	
	i = 0;

	while(str[i])
	{
		stack->arra[i] = ft_atoi(str);
		i++;
	}
}
