/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharouh <mcharouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:04:47 by mcharouh          #+#    #+#             */
/*   Updated: 2022/07/27 07:36:43 by mcharouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack;
	t_stuff	*extra;
	int i = 0;

	extra = join_split(av);
	fill_my_stack(&stack, extra);
	if (check_dup(extra, &stack))
		return (write(2, "Dups\n", 5));
	check_if_sorted(&stack);
	push_swap_algo(&stack, extra);
	printf("---stack a--- ---stack b---\n");
	while (i < stack.sizea)
	{
		printf("-----%d-----     -----%d-----\n", stack.arra[i], stack.arrb[i]);
		i++;
	}
}

t_stuff	*join_split(char **av)
{
	t_stuff		*extra;

	extra = malloc(sizeof(t_stuff));
	extra->i = 1;
	extra->str = ft_strdup("");
	while (av[extra->i])
	{
		extra->str = ft_strjoin(extra->str, av[extra->i]);
		extra->str = ft_strjoin(extra->str, " ");
		extra->i++;
	}
	extra->i = 0;
	extra->str1 = ft_split(extra->str, ' ');
	extra->len = ft_strlon(extra->str1);
	return (extra);
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
		extra->i++;
	}
		stacks->sizeb = 0;
}
