NAME = PUSHY_SWAPY

CFLAGS	= -Wall -Wextra -Werror

SRCS = push_swap.c ft_split.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_substr.c ft_atoi.c
OBJS =	$(SRCS:.c=.o)

RM =	rm -f

all:	$(NAME)

%.o:	%.c
		$(CC)  -c $< -o $@

$(NAME): $(OBJS)
		$(CC)  $(CFLAGS) $(OBJS)  -o $(NAME)
clean : 
		$(RM) $(OBJS)
fclean : clean
		$(RM) $(NAME)
re : fclean all