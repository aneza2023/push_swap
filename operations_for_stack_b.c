/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_for_stack_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naomi <naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:11:17 by ahavrank          #+#    #+#             */
/*   Updated: 2025/01/06 19:28:46 by naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack	*swap_in_stack_b(stack *stack_b)
{
	stack	*temp;
	stack	*tempnx;

	if (stack_b->nx == NULL)
		return (stack_b);
	temp = allocation();
	tempnx = allocation();
	if (temp == NULL || tempnx == NULL)
		free_stack(stack_b);
	temp->index = stack_b->index;
	temp->val = stack_b->val;
	temp->nx = stack_b->nx;
	tempnx->index = stack_b->nx->index;
	tempnx->val = stack_b->nx->val;
	tempnx->nx = stack_b->nx->nx;
	stack_b->index = tempnx->index;
	stack_b->val = tempnx->val;
	stack_b->nx->index = temp->index;
	stack_b->nx->val = temp->val;
	free(temp);
	free(tempnx);
	write(1, "sb\n", 3);
	return (stack_b);
}

stack	*rotate_stack_b(stack *stack_b)
{
	stack	*head;
	stack	*temp;

	if (stack_b->nx == NULL)
		return (stack_b);
	temp = stack_b->nx;
	head = stack_b->nx;
	stack_b->nx->prev = NULL;
	stack_b->nx = NULL;
	while ((temp)->nx != NULL)
		temp = (temp)->nx;
	(temp)->nx = stack_b;
	stack_b->prev = temp;
	write(1, "rb\n", 3);
	return (head);
}

stack	*reverse_rotate_b(stack *stack_b)
{
	stack	*head;
	stack	*temp;

	if (stack_b->nx == NULL)
		return (stack_b);
	temp = stack_b;
	while (temp->nx != NULL)
		temp = temp->nx;
	temp->nx = stack_b;
	stack_b->prev = temp;
	temp->prev->nx = NULL;
	temp->prev = NULL;
	write(1, "rrb\n", 4);
	return (temp);
}

int	push_to_b(stack **stack_a, stack **stack_b)
{
	stack	*temp;

	if (*stack_a == NULL)
		return (0);
	temp = *stack_a;
	if ((*stack_a)->nx != NULL)
	{
		(*stack_a)->nx->prev = NULL;
	}
	*stack_a = (*stack_a)->nx;
	temp->nx = *stack_b;
	if (*stack_b != NULL)
		(*stack_b)->prev = temp;
	*stack_b = temp;
	write(1, "pb\n", 3);
	return (1);
}
