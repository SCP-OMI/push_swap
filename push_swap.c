/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharouh <mcharouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:04:47 by mcharouh          #+#    #+#             */
/*   Updated: 2022/05/19 15:29:18 by mcharouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	main(int ac, char **av)
{
	t_stack stacks;
	t_stuff *lobnani;
	
	lobnani = joiny_splity(av);
	stacks.arra = malloc(sizeof(int) * lobnani->len);
	while (lobnani->str1[lobnani->i])
	{
		stacks.arra[lobnani->i] = ft_atoi(lobnani->str1[lobnani->i]);
		printf("%d\n", stacks.arra[lobnani->i]);
		lobnani->i++;
	}
	
	
	//checking them errors #1
	//fill_my_stack(&stacks, ft_split(str, ' '));
	
}

int	ft_strlon(char **str)
{
	int i;
	
	i = 0;
	while(str[i])
		i++;
	return(i);
}

t_stuff *joiny_splity(char **av)
{
	t_stuff		*lobnani;
	lobnani = malloc(sizeof(t_stuff));
	lobnani->i = 1;
	lobnani->str = ft_strdup("");
	while(av[lobnani->i])
	{
		lobnani->str = ft_strjoin(lobnani->str, av[lobnani->i]);
		lobnani->str = ft_strjoin(lobnani->str, " ");
		lobnani->i++;
	}
	lobnani->i = 0;
	lobnani->str1 = ft_split(lobnani->str, ' ');
	lobnani->len = ft_strlon(lobnani->str1);
	return(lobnani);
}
