/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_for_stack_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naomi <naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:11:27 by ahavrank          #+#    #+#             */
/*   Updated: 2025/01/06 19:28:04 by naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//probably have to redo cause of number of lines
stack	*swap_in_stack_a(stack *stack_a)
{
	stack	*temp;
	stack	*tempnx;

	if (stack_a->nx == NULL)
		return (stack_a);
	temp = allocation();
	tempnx = allocation();
	if (temp == NULL || tempnx == NULL)
		free_stack(stack_a);
	temp->index = stack_a->index;
	temp->val = stack_a->val;
	temp->nx = stack_a->nx;
	tempnx->index = stack_a->nx->index;
	tempnx->val = stack_a->nx->val;
	tempnx->nx = stack_a->nx->nx;
	stack_a->index = tempnx->index;
	stack_a->val = tempnx->val;
	stack_a->nx->index = temp->index;
	stack_a->nx->val = temp->val;
	free(temp);
	free(tempnx);
	write(1, "sa\n", 3);
	return (stack_a);
}

stack	*rotate_stack_a(stack *stack_a)
{
	stack	*head;
	stack	*temp;

	if (stack_a->nx == NULL)
		return (stack_a);
	temp = stack_a->nx;
	head = stack_a->nx;
	stack_a->nx->prev = NULL;
	stack_a->nx = NULL;
	while ((temp)->nx != NULL)
		temp = (temp)->nx;
	(temp)->nx = stack_a;
	stack_a->prev = temp;
	write(1, "ra\n", 3);
	return (head);
}

stack	*reverse_rotate_a(stack *stack_a)
{
	stack	*head;
	stack	*temp;

	if (stack_a->nx == NULL)
		return (stack_a);
	temp = stack_a;
	while (temp->nx != NULL)
		temp = temp->nx;
	temp->nx = stack_a;
	stack_a->prev = temp;
	temp->prev->nx = NULL;
	temp->prev = NULL;
	write(1, "rra\n", 4);
	return (temp);
}

int	push_to_a(stack **stack_a, stack **stack_b)
{
	stack	*temp;

	if (*stack_b == NULL)
		return (0);
	temp = *stack_b;
	if ((*stack_b)->nx != NULL)
	{
		(*stack_b)->nx->prev = NULL;
	}
	*stack_b = (*stack_b)->nx;
	temp->nx = *stack_a;
	if (*stack_a != NULL)
		(*stack_a)->prev = temp;
	*stack_a = temp;
	write(1, "pa\n", 3);
	return (1);
}
