
#include "push_swap.h"

stack  *swap_in_stack(stack *stack_a)
{
    stack   *temp;
    int     i;

// putting temp at 1st place with value of 2nd
    temp = (stack*)malloc(sizeof(stack));
    if (temp == NULL){
		printf("Allocation failed");
		return (stack_a);
	}
    temp->value = stack_a->next->value;
    temp->next = stack_a;
    stack_a = temp;
/*     while (stack_a != NULL){
		printf("A: %d\n", stack_a->value);
		stack_a = stack_a ->next;
	}  */
// deleting 2nd
    i = 1;
    while (stack_a != NULL && i <= 1){
        stack_a = stack_a->next;
        i++;
    }
    stack_a->next = stack_a->next->next;
    while (stack_a != NULL){
		printf("B: %d\n", stack_a->value);
		stack_a = stack_a ->next;
	} 
    return (stack_a); 
}

/* stack  rotate_stack(stack **stack)
{}

stack  reverse_rotate_stack(stack **stack)
{}

stack  push_to_stack(stack **stack_dest, stack **stack_src)
{} */
