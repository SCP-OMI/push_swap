/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharouh <mcharouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:36:13 by mcharouh          #+#    #+#             */
/*   Updated: 2022/05/19 15:16:53 by mcharouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
#define PUSHSWAP_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_stack
{
	int	sizea;
	int sizeb;
	int	*arra;
	int *arrb;
	int len_arr;
}	t_stack;

typedef struct s_stuff
{
	char	*str;
	char	**str1;
	int		i;
	int		len;
}	t_stuff;



int		ft_atoi(const char *str);
int		check_dup(char **av);
int		check_int(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	fill_my_stack(t_stack *stack, char *str);
int		ft_strlon(char **str);
t_stuff *joiny_splity(char **av);





//FT_SPLIT STUFF//
char            **ft_split(char const *s, char c);
static void     char_count(const char *s, char c, char	**split);
static int      ft_free(char **split, size_t j);
static size_t   word_count(char const *s, char c);
size_t          ft_strlen(const char *str);
char*			ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s);


#endif