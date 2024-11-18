#include "push_swap.h"

int algorithm(stack **stack_a, stack **stack_b, int argc)
{
    stack   ***stack_a_fp;
    stack   ***stack_b_fp;

    stack_a_fp = &stack_a;
    stack_b_fp = &stack_b;
    if (argc <= 2)
        algori_2(stack_a_fp, stack_b_fp);
    else if (argc < 5 && argc < 100)
        algori_under100()
    return (0);
}
