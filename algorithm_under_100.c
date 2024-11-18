/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_under_100.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:58:56 by ahavrank          #+#    #+#             */
/*   Updated: 2024/11/18 12:21:07 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	algori_under100(stack **stack_a, stack **stack_b, int argc)
{
	int		i;
	stack	*checked_num;
	stack	*temp;
	stack	*tempback;
	stack	*tempfront;

	tempfront = *stack_a;
	temp = *stack_a;
	argc = argc / 5;
	i = 0;
	while (tempfront != NULL)
	{
		if (tempfront->index <= argc)
			break ;
		tempfront = tempfront->next;
	}
//	printf("1st from top: %d", tempfront->value);
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	tempback = temp;
//	printf("tempstartback: %d", tempback->value);
	while (tempback != NULL)
	{
		if (tempback->index <= argc)
			break ;
		tempback = tempback->prev;
	}
//	printf("1st from back: %d", tempback->value);
	return (0);
}

int algori_for_2(stack *stack_a)
{
	if (stack_a->value > stack_a->next->value)
		swap_in_stack_a(stack_a);
//	printing_stacks(stack_a);
	return(0);
}	

int	algori_for_3(stack *stack_a)
{
	if ((stack_a->value >= stack_a->next->value) && (stack_a->next->value <= stack_a->next->next->value)){
		if (stack_a->value <= stack_a->next->next->value)
			stack_a = swap_in_stack_a(stack_a);
		else
			stack_a = rotate_stack_a(stack_a);
	}
	else if ((stack_a->value >= stack_a->next->value) && (stack_a->next->value >= stack_a->next->next->value)){
		stack_a = swap_in_stack_a(stack_a);
		stack_a = reverse_rotate_a(stack_a);
	}
	else if ((stack_a->value <= stack_a->next->value) && (stack_a->next->value >= stack_a->next->next->value)){
		if (stack_a->value >= stack_a->next->next->value)
			stack_a = reverse_rotate_a(stack_a);
		else{
			stack_a = swap_in_stack_a(stack_a);
			stack_a = rotate_stack_a(stack_a);
		}
	}
	printing_stacks(stack_a);
	return (0);
}






/* int	numbering(int argc)
{
	int	i;

	i = argc / 5;
	printf("divide>   %d", i);
		printf("divide>   %d", argc);
	return (0);
} */