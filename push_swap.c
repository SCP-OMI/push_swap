/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharouh <mcharouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:04:47 by mcharouh          #+#    #+#             */
/*   Updated: 2022/08/09 22:22:14 by mcharouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack;
	t_stuff	*extra;

	check_dub_quotes(av);
	extra = join_split(av);
	fill_my_stack(&stack, extra);
	if (!check_dup(extra, &stack))
		return (write(2, "Dups\n", 5));
	check_if_sorted(&stack);
	push_swap_algo(&stack, extra);
}

void	fill_my_stack(t_stack *stacks, t_stuff *extra)
{
	stacks->arra = malloc(sizeof(int) * extra->len);
	stacks->arrb = malloc(sizeof(int) * extra->len);
	extra->sorted_array = malloc(sizeof(int) * extra->len);
	stacks->sizea = 0;
	while (extra->str1[extra->i])
	{
		stacks->arra[extra->i] = ft_atoi(extra->str1[extra->i]);
		extra->sorted_array[extra->i] = ft_atoi(extra->str1[extra->i]);
		stacks->sizea++;
		free(extra->str1[extra->i]);
		extra->i++;
	}
	stacks->sizeb = 0;
}
