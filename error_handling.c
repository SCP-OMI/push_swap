/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharouh <mcharouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:11:33 by mcharouh          #+#    #+#             */
/*   Updated: 2022/08/08 02:38:32 by mcharouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	check_dup(t_stuff *extra, t_stack *data)
{
	int	i;
	int	j;

	i = 0;
	sort(extra, data);
	while (i < extra->len)
	{
		j = i + 1;
		while (j < extra->len)
		{
			if (extra->sorted_array[i] == extra->sorted_array[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	sort(t_stuff *extra, t_stack *data)
{
	int	i;
	int	j;
	int	swap;

	j = 0;
	while (j <= extra->len)
	{
		i = 0;
		while (i < extra->len - 1)
		{
			if (extra->sorted_array[i] > extra->sorted_array[i + 1])
			{
				swap = extra->sorted_array[i + 1];
				extra->sorted_array[i + 1] = extra->sorted_array[i];
				extra->sorted_array[i] = swap;
			}
			i++;
		}
		j++;
	}
}

void	check_dub_quotes(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i][0] == '\0')
		{
			write(1, "empty quote\n", 13);
			exit(1);
		}
		i++;
	}
}

int	ft_is_all_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_args(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (!ft_is_all_num(str[i]))
			return (0);
		i++;
	}
	return (1);
}
