NAME = push_swap
SOURCES =	push_swap.c\
			creating_stack_a.c\
			operations_for_stack_a.c\
			operations_for_stack_b.c\
			functions_for_checking_input.c\
			printing_stacks.c\
			allocating_for_new_node.c\
			algorithm_under5.c\
			algorithm_unknown.c\
			algorithm_under100.c\
			algorithm_under500.c\
			utils_algo_under100.c\
			ft_atoi.c\
			modified_atoi.c\
			before_exit.c

OBJS = $(SOURCES:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra

all:$(NAME)

$(NAME):$(OBJS)
	cc -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
