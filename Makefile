NAME = push_swap.a
SOURCES =	push_swap.c\
			creating_stack_a.c\
			operations_for_ps.c\
			
OBJS = $(SOURCES:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra

all:$(NAME)

$(NAME):$(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all