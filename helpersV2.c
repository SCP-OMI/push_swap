/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpersV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharouh <mcharouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:35:17 by mcharouh          #+#    #+#             */
/*   Updated: 2022/08/09 22:23:06 by mcharouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_strlon(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	chunk_utils(t_stack *stack, t_stuff *extra)
{
	stack->middle = stack->sizea / 2;
	if (stack->sizea <= 15)
		stack->offset = stack->sizea / 5;
	else if (stack->sizea <= 150)
		stack->offset = stack->sizea / 8;
	else if (stack->sizea > 150)
		stack->offset = stack->sizea / 18;
	stack->start = stack->middle - stack->offset;
	stack->end = stack->middle + stack->offset;
}

void	offset_adjust(t_stack *stack, t_stuff *extra)
{
	stack->start = stack->start - stack->offset;
	if (stack->start < 0)
		stack->start = 0;
	stack->end = stack->end + stack->offset;
	if (stack->end >= extra->len)
		stack->end = extra->len;
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
	int	i;

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
