#include "push_swap.h"

int printing_stacks(stack *stack_a, stack *stack_b)
{
// CHECK: PRINTING STACK
	while (stack_a != NULL)
	{
		printf("\nSTACK A:%d\n", stack_a->value);
		stack_a = stack_a ->next;
	}
	while (stack_b != NULL)
	{
		printf("\nSTACK B:%d\n", stack_b->value);
		stack_b = stack_b ->next;
	}
    return (0);
}
