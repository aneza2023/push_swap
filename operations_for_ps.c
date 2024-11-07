
#include "push_swap.h"

stack  *swap_in_stack(stack *stack_a)
{
    stack   *temp;

// putting values of 2nd in temp
    temp = (stack*)malloc(sizeof(stack));
    if (temp == NULL){
		printf("Allocation failed");
		return (stack_a);
	}
    temp->value = stack_a->next->value;
// deleting 2nd
    stack_a->next = stack_a->next->next;
// setting temp as 1st
    temp->next = stack_a;
    stack_a = temp;
/*     while (stack_a != NULL){
		printf("B: %d\n", stack_a->value);
		stack_a = stack_a ->next;
	}  */
    return (stack_a); 
}

stack *rotate_stack(stack *stack_a)
{
    int i;
    stack   *temp;

    i = 1;
    temp = stack_a;
    while (stack_a->next != NULL)
    {
        stack_a = stack_a->next;
        i++;
    }
    stack_a->next = temp;
    
    while (stack_a->next != NULL){
    printf("%d\n", stack_a->value);
		stack_a = stack_a ->next;
    }
}

/*stack  reverse_rotate_stack(stack **stack)
{}

stack  push_to_stack(stack **stack_dest, stack **stack_src)
{} */
