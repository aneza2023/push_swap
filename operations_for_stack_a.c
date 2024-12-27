/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_for_stack_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naomi <naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:11:27 by ahavrank          #+#    #+#             */
/*   Updated: 2024/12/27 18:14:11 by naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack	*swap_in_stack_a(stack *stack_a)
{
	stack	*temp;

	if (stack_a->nx == NULL)
		return (stack_a);
	temp = allocation();
	if (temp == NULL)
		return (stack_a);
	temp->val = stack_a->nx->val;
	temp->index = stack_a->nx->index;
	temp->prev = NULL;
	if (stack_a->nx->nx == NULL)
		free(stack_a->nx);
	else if (stack_a->nx->nx != NULL){
		stack_a->nx->nx->prev = stack_a;
		free(stack_a->nx);
		}
	stack_a->prev = temp;
	temp->nx = stack_a;
	stack_a = temp;
	printf("sa\n");
	return (stack_a);
}

stack	*rotate_stack_a(stack *stack_a)
{
	stack	*end_node;
	stack	*head;

	if (stack_a->nx == NULL)
		return (stack_a);
	head = stack_a->nx;
	head->prev = NULL;
	end_node = allocation();
	if (end_node == NULL)
		return (stack_a);
	end_node->val = stack_a->val;
	end_node->index = stack_a->index;
	end_node->nx = NULL;
	free(stack_a);
	stack_a = head;
	while (stack_a->nx != NULL)
		stack_a = stack_a->nx;
	stack_a->nx = end_node;
	end_node->prev = stack_a;
	stack_a = head;
	printf("ra\n");
	return (stack_a);
}

stack	*reverse_rotate_a(stack *stack_a)
{
	stack	**head;
	stack	*first_node;
	stack	*temp;

	if (stack_a->nx == NULL)
		return (stack_a);
	head = &stack_a;
	first_node = allocation();
	if (first_node == NULL)
		return (stack_a);
	temp = stack_a;
	while (temp->nx->nx != NULL)
	{
		temp = temp->nx;
	}
	first_node->val = temp->nx->val;
	first_node->index = temp->nx->index;
	temp->nx->prev = NULL;
	free(temp->nx);
	first_node->nx = *head;
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
	pushed_stack = allocation();
	if (pushed_stack == NULL)
		return (0);
	pushed_stack->val = (*stack_b)->val;
	pushed_stack->index = (*stack_b)->index;
	if ((*stack_b)->nx != NULL)
		(*stack_b)->nx->prev = NULL;
	*stack_b = (*stack_b)->nx;
	pushed_stack->nx = *stack_a;
	if (*stack_a != NULL)
		(*stack_a)->prev = pushed_stack;
	*stack_a = pushed_stack;
	printf("pa\n");
	return (1);
}
