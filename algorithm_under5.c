/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_under5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:58:56 by ahavrank          #+#    #+#             */
/*   Updated: 2024/12/04 13:10:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	algori_for_2(stack *stack_a)
{
	if (stack_a->val > stack_a->nx->val)
		swap_in_stack_a(stack_a);
	return (0);
}

stack	*algori_for_3(stack *sa)
{
	if ((sa->val >= sa->nx->val) && (sa->nx->val <= sa->nx->nx->val))
	{
		if (sa->val <= sa->nx->nx->val)
			sa = swap_in_stack_a(sa);
		else
			sa = rotate_stack_a(sa);
	}
	else if ((sa->val >= sa->nx->val) && (sa->nx->val >= sa->nx->nx->val))
	{
		sa = swap_in_stack_a(sa);
		sa = reverse_rotate_a(sa);
	}
	else if ((sa->val <= sa->nx->val) && (sa->nx->val >= sa->nx->nx->val))
	{
		if (sa->val >= sa->nx->nx->val)
			sa = reverse_rotate_a(sa);
		else
		{
			sa = swap_in_stack_a(sa);
			sa = rotate_stack_a(sa);
		}
	}
	return (sa);
}
int	algori_under_5(stack *stack_a, stack *stack_b, int argc)
{
	stack	**stack_a_fp;
	stack	**stack_b_fp;

	stack_a_fp = &stack_a;
	stack_b_fp = &stack_b;
	push_to_b(stack_a_fp, stack_b_fp);
	if (argc > 5)
		push_to_b(stack_a_fp, stack_b_fp);
	stack_a = algori_for_3(stack_a);
	if (stack_b->nx != NULL && stack_b->val < stack_b->nx->val)
		stack_b = swap_in_stack_b(stack_b);
	first_round(stack_a, stack_b);
	return (0);
}

int	first_round(stack *stack_a, stack *stack_b)
{
	stack	**stack_a_fp;
	stack	**stack_b_fp;

	stack_a_fp = &stack_a;
	stack_b_fp = &stack_b;
	if (stack_b->index == 5 && stack_b->nx->index != 4){
		push_to_a(stack_a_fp, stack_b_fp);
		stack_a = rotate_stack_a(stack_a);
	}
 	else if (stack_b->index == 4){
		stack_a = reverse_rotate_a(stack_a);
		push_to_a(stack_a_fp, stack_b_fp);
	}
	else if (stack_b->index == 3){	
		push_to_a(stack_a_fp, stack_b_fp);
		stack_a = swap_in_stack_a(stack_a);
		push_to_a(stack_a_fp, stack_b_fp);	
	}
	else if (stack_b->index == 2 || (stack_b->index == 5 && stack_b->nx->index == 4)){
		push_to_a(stack_a_fp, stack_b_fp);
		push_to_a(stack_a_fp, stack_b_fp);
	}
	second_round(stack_a, stack_b);
	return (0);
}

int		second_round(stack *stack_a, stack *stack_b)
{	stack	**stack_a_fp;
	stack	**stack_b_fp;

	stack_a_fp = &stack_a;
	stack_b_fp = &stack_b;
	if (stack_a->index > stack_a->nx->index)
		stack_a = swap_in_stack_a(stack_a);
	if (stack_b != NULL){
		if (stack_b->index < stack_a->nx->index)
			push_to_a(stack_a_fp, stack_b_fp);
		else
			stack_a = rotate_stack_a(stack_a);
		if (stack_b != NULL)
			push_to_a(stack_a_fp, stack_b_fp);
	}
	third_round(stack_a);
	return (0);
}

int	third_round(stack *stack_a)
{
	if (stack_a->index > stack_a->nx->index)
		stack_a = swap_in_stack_a(stack_a);
	if (stack_a->index == 2 && stack_a->nx->index == 4){
		stack_a = reverse_rotate_a(stack_a);
		stack_a = swap_in_stack_a(stack_a);
	}
	if (stack_a->index == 1 && stack_a->nx->index == 4){
		stack_a = reverse_rotate_a(stack_a);
		stack_a = swap_in_stack_a(stack_a);
		stack_a = reverse_rotate_a(stack_a);
		stack_a = swap_in_stack_a(stack_a);
	}
	while (stack_a->index != 1)
	{
		stack_a = reverse_rotate_a(stack_a);
	}
	return (0);
}
