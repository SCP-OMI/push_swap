/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpersV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharouh <mcharouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:35:17 by mcharouh          #+#    #+#             */
/*   Updated: 2022/08/04 05:40:43 by mcharouh         ###   ########.fr       */
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
	if (stack->sizea <= 16)
		stack->offset = stack->sizea / 5;
	else if (stack->sizea > 16 && stack->sizea <= 150)
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
	if (stack->end > stack->len_arr)
		stack->end = stack->len_arr - 2;
}