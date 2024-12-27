/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_for_stack_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naomi <naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:11:17 by ahavrank          #+#    #+#             */
/*   Updated: 2024/12/27 18:14:56 by naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack	*swap_in_stack_b(stack *stack_b)
{
	stack	*temp;

	if (stack_b->nx == NULL)
		return (stack_b);
	temp = allocation();
	if (temp == NULL)
		return (stack_b);
	temp->val = stack_b->nx->val;
	temp->index = stack_b->nx->index;
	temp->prev = NULL;
	if (stack_b->nx->nx != NULL){
		stack_b->nx->nx->prev = stack_b;
		free(stack_b->nx);
		}
	else if (stack_b->nx->nx == NULL)
		free(stack_b->nx);
	stack_b->prev = temp;
	temp->nx = stack_b;
	stack_b = temp;
	printf("sb\n");
	return (stack_b);
}

stack	*rotate_stack_b(stack *stack_b)
{
	stack	*end_node;
	stack	*head;

	if (stack_b->nx == NULL)
		return (stack_b);
	head = stack_b->nx;
	head->prev = NULL;
	end_node = allocation();
	if (end_node == NULL)
		return (stack_b);
	end_node->val = stack_b->val;
	end_node->index = stack_b->index;
	end_node->nx = NULL;
	free(stack_b);
	while (stack_b->nx != NULL)
		stack_b = stack_b->nx;
	stack_b->nx = end_node;
	end_node->prev = stack_b;
	stack_b = head;
	printf("rb\n");
	return (stack_b);
}

stack	*reverse_rotate_b(stack *stack_b)
{
	stack	**head;
	stack	*first_node;
	stack	*temp;

	if (stack_b->nx == NULL)
		return (stack_b);
	head = &stack_b;
	first_node = allocation();
	if (first_node == NULL)
		return (stack_b);
	temp = stack_b;
	while (temp->nx->nx != NULL)
	{
		temp = temp->nx;
	}
	first_node->val = temp->nx->val;
	first_node->index = temp->nx->index;
	temp->nx = NULL;
	free(temp->nx);
	first_node->nx = *head;
	stack_b = first_node;
	printf("rrb\n");
	return (stack_b);
}

int	push_to_b(stack **stack_a, stack **stack_b)
{
	stack	*pushed_stack;

	if (*stack_a == NULL)
		return (0);
	pushed_stack = allocation();
	if (pushed_stack == NULL)
		return (0);
	pushed_stack->val = (*stack_a)->val;
	pushed_stack->index = (*stack_a)->index;
	if ((*stack_a)->nx != NULL)
		(*stack_a)->nx->prev = NULL;
	*stack_a = (*stack_a)->nx;
	pushed_stack->nx = *stack_b;
	if (*stack_b != NULL)
		(*stack_b)->prev = pushed_stack;
	*stack_b = pushed_stack;
	printf("pb\n");
	return (1);
}
