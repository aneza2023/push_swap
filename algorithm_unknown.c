#include "push_swap.h"

int algorithm(stack *stack_a, int argc)
{
    stack   *stack_b;

    stack_b = NULL;
    if (argc == 3)
        algori_for_2(stack_a);
    else if (argc == 4)
        algori_for_3(stack_a);
    else if (argc > 4 && argc <= 6)
        algori_under_5(stack_a, stack_b, argc);
    return (0);
}
