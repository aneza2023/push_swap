#include "push_swap.h"

int	free_stack(stack *stacka)
{
	stack	*temp;
	while(stacka != NULL && stacka->prev != NULL)
		stacka = stacka->prev;
	while (stacka != NULL)
	{
		temp = stacka;
		stacka = stacka->nx;
		free(temp);
		printf("free\n");
	}
	return (0);
}