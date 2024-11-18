/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_for_stack_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:11:17 by ahavrank          #+#    #+#             */
/*   Updated: 2024/11/18 10:49:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack  *swap_in_stack_b(stack *stack_b)
{
   stack   *temp;

    if (stack_b->next == NULL)
        return (stack_b);
    temp = (stack*)malloc(sizeof(stack));
    if (temp == NULL){
		printf("Allocation failed\n");
		return (stack_b);
	}
    temp->value = stack_b->next->value;
    temp->prev = NULL;
    if (stack_b->next->next != NULL)
        stack_b->next = stack_b->next->next;
    stack_b->prev = temp;
    temp->next = stack_b;
    stack_b = temp;
    printf("sb\n");
    return (stack_b);
}

stack *rotate_stack_b(stack *stack_b)
{
    stack   *end_node;
    stack   **head;
    int     i;

    if (stack_b->next == NULL)
        return (stack_b);
	head = &stack_b->next;
    end_node = (stack*)malloc(sizeof(stack));
    if (end_node == NULL) {
        printf("Allocation for rotate stack failed\n");
        return(stack_b);
    }
    end_node->value = stack_b->value;
    end_node->next = NULL;
// pripojit end_node
    i = 1;
    while (stack_b->next != NULL){
        stack_b = stack_b->next;
        i++;
    }
    stack_b->next = end_node;
//set to start
    stack_b = *head;
    printf("rb\n");
    return (stack_b);
}

stack *reverse_rotate_b(stack *stack_b)
{
    stack   **head;
    stack   *first_node;
    stack   *temp;

    if (stack_b->next == NULL)
        return (stack_b);
    head = &stack_b;
    first_node = (stack*)malloc(sizeof(stack));
    if (first_node == NULL) {
        printf("Allocation for rotate stack failed\n");
        return(stack_b);
    }
    temp = stack_b;
    while (temp->next->next != NULL){
        temp = temp->next;
    }
    first_node->value = temp->next->value;
    temp->next = NULL;
    first_node->next = *head;
    stack_b = first_node;
    printf("rrb\n");
    return (stack_b);
}

int push_to_b(stack **stack_a, stack **stack_b)
{
    stack   *pushed_stack;

    if (*stack_a == NULL)
        return (0);
    pushed_stack = (stack*)malloc(sizeof(stack));
    if (pushed_stack == NULL) {
        printf("Allocation for rotate stack failed\n");
        return(0);
    }
    pushed_stack->value = (*stack_a)->value;
    if ((*stack_a)->next != NULL)
        (*stack_a)->next->prev = NULL;
    *stack_a = (*stack_a)->next;
    pushed_stack->next = *stack_b;
    if (*stack_b != NULL)
        (*stack_a)->prev = pushed_stack;
    *stack_b = pushed_stack;
    printf("pb\n");
    return (1);
}
