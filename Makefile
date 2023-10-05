CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
SRCS = push_swap.c handle_node.c swap_node1.c push_swap_free_and_error.c swap_node2.c swap_node3.c sort_small_swap.c sort_big_swap.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	cp libft/libft.a $(NAME)
	ar rcs $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C libft clean
	$(RM) push_swap

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean
	$(RM) push_swap

re: fclean all

.PHONY: all clean fclean re

a.out: $(NAME)
	$(CC) -Wall -Wextra -Werror $(NAME) push_swap.c -o push_swap
