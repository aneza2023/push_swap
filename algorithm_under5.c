/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_under5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:58:56 by ahavrank          #+#    #+#             */
/*   Updated: 2025/03/06 19:43:48 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*algori_for_3(t_stack *sa)
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

int	algori_under_5(t_stack *stack_a, t_stack *stack_b, int argc)
{
	t_stack	**stack_a_fp;
	t_stack	**stack_b_fp;

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

void	first_round(t_stack *stack_a, t_stack *b)
{
	t_stack	**stack_a_fp;
	t_stack	**stack_b_fp;

	stack_a_fp = &stack_a;
	stack_b_fp = &b;
	if (b->index == 5 && b->nx->index != 4)
	{
		push_to_a(stack_a_fp, stack_b_fp);
		stack_a = rotate_stack_a(stack_a);
	}
	else if (b->index == 4)
	{
		stack_a = reverse_rotate_a(stack_a);
		push_to_a(stack_a_fp, stack_b_fp);
	}
	else if (b->index == 3 && b->nx != NULL)
	{
		push_to_a(stack_a_fp, stack_b_fp);
		stack_a = swap_in_stack_a(stack_a);
		push_to_a(stack_a_fp, stack_b_fp);
	}
	else if (b->index == 2 || (b->index == 5 && b->nx->index == 4))
		help_for_first_round(stack_a_fp, stack_b_fp);
	second_round(stack_a, b);
}

int	second_round(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	**stack_a_fp;
	t_stack	**stack_b_fp;

	stack_a_fp = &stack_a;
	stack_b_fp = &stack_b;
	if (stack_a->index > stack_a->nx->index)
		stack_a = swap_in_stack_a(stack_a);
	if (stack_b != NULL)
	{
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

int	third_round(t_stack *stack_a)
{
	if (stack_a->index > stack_a->nx->index)
		stack_a = swap_in_stack_a(stack_a);
	if (stack_a->index == 2 && stack_a->nx->index == 4)
	{
		stack_a = reverse_rotate_a(stack_a);
		stack_a = swap_in_stack_a(stack_a);
	}
	if (stack_a->index == 1 && stack_a->nx->index == 4)
	{
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
