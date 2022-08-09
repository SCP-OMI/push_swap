NAME = push_swap

CFLAGS	= -Wall -Wextra -Werror

SRCS = push_swap.c ft_split.c ft_substr.c ft_atoi.c error_handling.c helpersV2.c small_sort.c operations.c not_so_small_sort.c helpers.c push_swap_utils.c
OBJS =	$(SRCS:.c=.o)

RM =	rm -f

all:	$(NAME)

%.o:	%.c
		@$(CC)  -c $< -o $@

$(NAME): $(OBJS)
		@$(CC)  $(CFLAGS) $(OBJS) -g  -o $(NAME)
clean : 
		@$(RM) $(OBJS)
fclean : clean
		@$(RM) $(NAME)
re : fclean all