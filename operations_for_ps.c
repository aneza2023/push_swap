
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
// deleting 2nds
//    stack_a->next->next->prev = stack_a;
    stack_a->next = stack_a->next->next;
// setting temp as 1st
    temp->next = stack_a;
//    stack_a->prev = temp;
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
    stack   **head;
    int     i;

	head = &stack_a->next;
    end_node = (stack*)malloc(sizeof(stack));
    if (end_node == NULL) {
        printf("Allocation for rotate stack failed");
        return(stack_a);
    }
    end_node->value = stack_a->value;
    end_node->next = NULL;
// pripojit end_node
    i = 1;
    while (stack_a->next != NULL){
        stack_a = stack_a->next;
        i++;
    }
    stack_a->next = end_node;
//set to start
    stack_a = *head;
    return (stack_a);
}   
   

stack *reverse_rotate(stack *stack_a)
{
    stack   **head;
    stack   *first_node;
    stack   *temp;

    head = &stack_a;
    first_node = (stack*)malloc(sizeof(stack));
    if (first_node == NULL) {
        printf("Allocation for rotate stack failed");
        return(stack_a);
    }
    temp = stack_a;
    while (temp->next->next != NULL){
        temp = temp->next;
    }
    first_node->value = temp->next->value;
    temp->next = NULL;
    first_node->next = *head;
    stack_a = first_node;
    return (stack_a);
}

int push_to_a(stack **stack_a, stack **stack_b)
{
    stack   *pushed_stack;

    pushed_stack = (stack*)malloc(sizeof(stack));
    if (pushed_stack == NULL) {
        printf("Allocation for rotate stack failed");
        return(0);
    }
    pushed_stack->value = (*stack_a)->value;
//    (*stack_a)->value = NULL;
    *stack_a = (*stack_a)->next;
    pushed_stack->next = *stack_b;
    *stack_b = pushed_stack;
    return (1);
}

int push_to_b(stack **stack_a, stack **stack_b)
{
        stack   *pushed_stack;

    pushed_stack = (stack*)malloc(sizeof(stack));
    if (pushed_stack == NULL) {
        printf("Allocation for rotate stack failed");
        return(0);
    }
    pushed_stack->value = (*stack_b)->value;
    *stack_b = (*stack_b)->next;
    pushed_stack->next = *stack_a;
    *stack_a = pushed_stack;
    return (1);
}
