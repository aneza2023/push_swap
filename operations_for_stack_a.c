/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_for_stack_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:11:27 by ahavrank          #+#    #+#             */
/*   Updated: 2024/11/18 14:26:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// putting values of 2nd in temp
// deleting 2nds
// stack_a->next->next->prev = stack_a;
// setting temp as 1st
// stack_a->prev = temp;

// pripojit end_node
// set to start


#include "push_swap.h"

stack	*swap_in_stack_a(stack *stack_a)
{
	stack	*temp;

	if (stack_a->next == NULL)
		return (stack_a);
	temp = (stack *)malloc(sizeof(stack));
	if (temp == NULL)
	{
		printf("Allocation failed\n");
		return (stack_a);
	}
	temp->value = stack_a->next->value;
	temp->index = stack_a->next->index;
	temp->prev = NULL;
	if (stack_a->next->next != NULL)
		stack_a->next = stack_a->next->next;
	stack_a->prev = temp;
	temp->next = stack_a;
	stack_a = temp;
	printf("sa\n");
	return (stack_a);
}

stack	*rotate_stack_a(stack *stack_a)
{
	stack	*end_node;
	stack	**head;
	int		i;

	if (stack_a->next == NULL)
		return (stack_a);
	head = &stack_a->next;
	end_node = (stack *)malloc(sizeof(stack));
	if (end_node == NULL)
	{
		printf("Allocation for rotate stack failed\n");
		return (stack_a);
	}
	end_node->value = stack_a->value;
	end_node->index = stack_a->index;
	end_node->next = NULL;
	i = 1;
	while (stack_a->next != NULL)
	{
		stack_a = stack_a->next;
		i++;
	}
	stack_a->next = end_node;
	end_node->prev = stack_a;
	stack_a = *head;
	printf("ra\n");
	return (stack_a);
}


stack	*reverse_rotate_a(stack *stack_a)
{
	stack	**head;
	stack	*first_node;
	stack	*temp;

	if (stack_a->next == NULL)
		return (stack_a);
	head = &stack_a;
	first_node = (stack *)malloc(sizeof(stack));
	if (first_node == NULL)
	{
		printf("Allocation for rotate stack failed\n");
		return (stack_a);
	}
	temp = stack_a;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	first_node->value = temp->next->value;
	first_node->index = temp->next->index;
	temp->next->prev = NULL;
	temp->next = NULL;
	first_node->next = *head;
	(*head)->prev = first_node;
	stack_a = first_node;
	printf("rra\n");
	return (stack_a);
}

int	push_to_a(stack **stack_a, stack **stack_b)
{
	stack	*pushed_stack;

	if (*stack_b == NULL)
		return (0);
	pushed_stack = (stack *)malloc(sizeof(stack));
	if (pushed_stack == NULL)
	{
		printf("Allocation for rotate stack failed\n");
		return (0);
	}
	pushed_stack->value = (*stack_b)->value;
	pushed_stack->index = (*stack_b)->index;
	if ((*stack_b)->next != NULL)
		(*stack_b)->next->prev = NULL;
	*stack_b = (*stack_b)->next;
	pushed_stack->next = *stack_a;
	if (*stack_a != NULL)
		(*stack_a)->prev = pushed_stack;
	*stack_a = pushed_stack;
	printf("pa\n");
	return (1);
}
