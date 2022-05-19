/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharouh <mcharouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:50:07 by mcharouh          #+#    #+#             */
/*   Updated: 2022/05/19 15:05:08 by mcharouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swap(t_stack *stack, int flag)
{
	int tmp;
	
	if (flag == 0)
	{
		tmp = stack->arra[0];
		stack->arra[0] = stack->arra[1];
		stack->arra[1] = tmp;
		write(1, "sa\n", 3);
		
	}
	else
	{
		tmp = stack->arrb[0];
		stack->arrb[0] = stack->arrb[1];
		stack->arrb[1] = tmp;
		write(1, "sb\n", 3);
	}
}

void	rotate(t_stack *stack, int flag)
{
	int tmp;
	int i;

	i = 0;
	if (flag == 0)
	{
		tmp = stack->arra[0];
		while (i < stack->sizea - 1 )
			stack->arra[i++] = stack->arra[i + 1];
		stack->arra[i] = tmp;
		write(1 , "ra\n", 3);
	}
	else
	{
		tmp = stack->arrb[0];
		while (i < stack->sizeb - 1)
			stack->arrb[i++] = stack->arrb[i + 1];
		stack->arrb[i] = tmp;
		write(1 , "rb\n", 3);
	}
}

void	reverse_rotate(t_stack *stack , int flag)
{
	int tmp;
	int i;

	i = stack->sizea;
	if (flag == 0)
	{
		tmp = stack->arra[stack->sizea];
		while(i > 0)
			stack->arra[i--] = stack->arra[i - 1];
		stack->arra[i] = tmp;
		write(1, "rra\n", 4);
	}
	else
	{
		i = stack->sizeb;
		tmp = stack->arrb[stack->sizea];
		while(i > 0)
			stack->arrb[i--] = stack->arrb[i - 1];
		stack->arrb[i] = tmp;
		write(1, "rrb\n", 4);
	}
}

void	push_stack(t_stack *stack, int flag)
{
	int tmp;

	if (flag == 0)
	{	
		flush_down(&stack, flag);
		stack->arra[0] = stack->arrb[0];
		stack->sizea--;
		stack->sizeb++;

		write(1, "pb\n", 3);
		}
	else
	{
		flush_down(&stack, flag);
		stack->arrb[0] = stack->arra[0];
		stack->sizeb--;
		stack->sizea++;
		write(1, "pa\n", 3);
	}
}

void	flush_down(t_stack *stack, int flag)
{
	int tmp;
	int i;

	if (flag == 0)
	{
		i = stack->sizeb;
		while(i - 1 != 0)
		{
			stack->arrb[i] = stack->arrb[i - 1];
			i--;
		}
	}
	else 
		i = stack->sizea;
		while(i - 1 != 0)
		{
			stack->arra[i] = stack->arra[i - 1];
			i--;
		}

}