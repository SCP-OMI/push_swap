/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharouh <mcharouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:32:21 by mcharouh          #+#    #+#             */
/*   Updated: 2022/06/11 19:47:26 by mcharouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	put_error(void)
{
	write(2, "You have an outside range charecter\n", 36);
	exit (1);
}

int	check_edges(size_t result, int sign)
{
	if (result >= 2147483647 && sign == 1)
		put_error();
	if (result >= 2147483648 && sign == -1)
		put_error();
	return (result *= sign);
}

int	ft_atoi(const char *str)
{
	int		sign;
	size_t	result;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == ' '
			|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			put_error();
		result = (result * 10) + str[i++] - '0';
	}
	return (check_edges(result, sign));
}