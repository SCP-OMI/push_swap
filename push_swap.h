/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharouh <mcharouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:36:13 by mcharouh          #+#    #+#             */
/*   Updated: 2022/07/17 22:14:27 by mcharouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack
{
	int	sizea;
	int	sizeb;
	int	*arra;
	int	*arrb;
	int	len_arr;
	int	small_num;
	int	big_num;
	int	small_index;
	int	big_index;
	int	offset;
	int	middle;
	int	start;
	int	end;
}	t_stack;

typedef struct s_stuff
{
	char	*str;
	int		*arr;
	char	**str1;
	int		*sorted_array;
	int		i;
	int		len;
	int		tmp;
}	t_stuff;

int				ft_atoi(const char *str);
int				check_dup(t_stuff *extra, t_stack *data);
int				check_int(char *str);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char const *s, char c);
void			fill_my_stack(t_stack *stack, t_stuff *extra);
int				ft_strlon(char **str);
t_stuff			*join_split(char **av);
void			sort(t_stuff *extra, t_stack *data);

//FT_SPLIT STUFF//
char			**ft_split(char const *s, char c);
static void		char_count(const char *s, char c, char	**split);
static int		ft_free(char **split, size_t j);
static size_t	word_count(char const *s, char c);
size_t			ft_strlen(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s);

//HELPER FUNCTIONS//

int				arr_len(int **str);

//OPERATIONS//

void			swap(t_stack *stack, int flag);
void			rotate(t_stack *stack, t_stuff *extra, int flag);
void			reverse_rotate(t_stack *stack, t_stuff *extra, int flag);
void			push_stack(t_stack *stack, int flag);
void			flush(t_stack *stack, int flag);
void			unflush(t_stack *stack, int flag);


//SORTING FCTS//
void			push_swap_algo(t_stack *stack, t_stuff *extra);
void			three_sort(t_stack *stack, t_stuff *extra);
void			four_sort(t_stack *stack, t_stuff *extra);
void			five_sort(t_stack *stack, t_stuff *extra);
void			fetch(t_stack *stack);
void			wiggle_big(t_stack *stack, t_stuff *extra);
void			wiggle_small(t_stack *stack, t_stuff *extra);
void			small_index(t_stack *stack);
void			big_index(t_stack *stack);
int				check_if_sorted(t_stack *stack);
void			chunk_utils(t_stack *stack, t_stack *extra);



#endif