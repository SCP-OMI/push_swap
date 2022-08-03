/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharouh <mcharouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:50:07 by mcharouh          #+#    #+#             */
/*   Updated: 2022/08/02 22:34:41 by mcharouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swap(t_stack *stack, int flag)
{
	int	tmp;

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

void	rotate(t_stack *stack, t_stuff *extra, int flag)
{
	int	i;

	i = 0;
	if (flag == 0 && stack->sizea > 1)
	{
		extra->tmp = stack->arra[0];
		while (i < stack->sizea)
		{
			stack->arra[i] = stack->arra[i + 1];
			i++;
		}
		stack->arra[stack->sizea - 1] = extra->tmp;
		write (1, "ra\n", 3);
	}
	else if (flag == 1 && stack->sizeb > 1)
	{
		extra->tmp = stack->arrb[0];
		while (i < stack->sizeb)
		{
			stack->arrb[i] = stack->arrb[i + 1];
			i++;
		}
		stack->arrb[stack->sizeb - 1] = extra->tmp;
		write (1, "rb\n", 3);	
	}
}

void	reverse_rotate(t_stack *stack, t_stuff *extra, int flag)
{
	int	i;

	if (flag == 0)
	{
		i = stack->sizea - 1;
		extra->tmp = stack->arra[stack->sizea - 1];
		while (i > 0)
		{
			stack->arra[i] = stack->arra[i - 1];
			i--;
		}
		stack->arra[0] = extra->tmp;
		write(1, "rra\n", 4);
		return ;
	}
		i = stack->sizeb - 1;
		extra->tmp = stack->arrb[stack->sizeb - 1];
	while (i > 0)
	{
		stack->arrb[i] = stack->arrb[i - 1];
		i--;
	}
	stack->arrb[0] = extra->tmp;
	write(1, "rrb\n", 4);
}

void	push(t_stack *stack, int flag)
{
	if (flag == 0)
	{	
		flush(stack, flag);
		stack->arra[0] = stack->arrb[0];
		unflush(stack, flag);
		stack->sizea++;
		stack->sizeb--;
		write(1, "pa\n", 3);
	}
	else if (flag == 1)
	{
		flush(stack, flag);
		stack->arrb[0] = stack->arra[0];
		unflush(stack, flag);
		stack->sizeb++;
		stack->sizea--;
		write(1, "pb\n", 3);
	}
}

void	flush(t_stack *stack, int flag)
{
	int	i;

	if (flag == 0)
	{
		i = stack->sizea - 1;
		while (i > -1)
		{
			stack->arra[i + 1] = stack->arra[i];
			i--; 
		}
	}
	else if (flag == 1)
	{
		i = stack->sizeb - 1;
		while (i > -1)
		{
			stack->arrb[i + 1] = stack->arrb[i];
			i--; 
		}
	}
}

void	unflush(t_stack *stack, int flag)
{
	int i;
	
	i = 0;
	if (flag == 0)
	{
		while (i < stack->sizeb)
		{
			stack->arrb[i] = stack->arrb[i + 1];
			i++;
		}
	}
	else if (flag == 1)
	{
		while (i < stack->sizea)
		{
			stack->arra[i] = stack->arra[i + 1];
			i++;
		}
	}
}