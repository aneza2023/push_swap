#include "push_swap.h"

int printing_stacks(stack *stack_a)
{
// CHECK: PRINTING STACK
	while (stack_a != NULL)
	{
		printf("\nSTACK A:%d\n", stack_a->value);
		stack_a = stack_a ->next;
	}
    return (0);
}
	