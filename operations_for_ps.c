
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
    stack_a->next->next->prev = stack_a;
    stack_a->next = stack_a->next->next;
// setting temp as 1st
    temp->next = stack_a;
    stack_a->prev = temp;
    stack_a = temp;
/*     while (stack_a != NULL){
		printf("B: %d\n", stack_a->value);
		stack_a = stack_a ->next;
	}   */
    return (stack_a);  
}

stack *rotate_stack(stack *stack_a)
{
    stack   *end_node;
    stack   *temp;
    int     i;

    end_node = (stack*)malloc(sizeof(stack));
    if (end_node == NULL) {
        printf("Allocation for rotate stack failed");
        return(stack_a);
    }
    end_node->value = stack_a->value;
    end_node->next = NULL;
    stack_a = stack_a->next;
//    printf("STACK:%d\n", stack_a->value);
//    printf("end:%d\n", end_node->value);
// pripojit end_node
    i = 1;
    while (stack_a->next != NULL){
        stack_a = stack_a->next;
        i++;
    }
//    printf("pocet:%d", i);
//    printf("STACK:%d\n", stack_a->value);
    end_node->prev = stack_a;
    stack_a->next = end_node;
//pocad funkcni
    while (i >= 1)
    {
        stack_a = stack_a->prev;
        i--;
    }
   printf("pocet 2x:%d", i);   
 //   printf("STACK:%d\n", stack_a->value);
    return (stack_a);
}   
   
/*     while (stack_a->next != NULL)
    {
        printf("%d\n", stack_a->value);
        stack_a = stack_a->next;
    } */


/*stack  reverse_rotate_stack(stack **stack)
{}

stack  push_to_stack(stack **stack_dest, stack **stack_src)
{} */
