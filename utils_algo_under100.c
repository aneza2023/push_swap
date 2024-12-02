/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo_under100.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:29:11 by anezkahavra       #+#    #+#             */
/*   Updated: 2024/11/29 09:59:24 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	back_to_a(stack *stack_a, stack *stack_b, int argc)
{
	stack	**stack_a_fp;
	stack	**stack_b_fp;

	printing_stacks(stack_b);
	stack_a_fp = &stack_a;
	stack_b_fp = &stack_b;
	while (stack_b != NULL)
	{	
		stack_b = check_order(stack_b);
		push_to_a(stack_a_fp, stack_b_fp);
	}
	printing_stacks(stack_a);
	return (0);
}

stack	*check_order(stack *stack_b)
{
	if (stack_b == NULL || stack_b->nx == NULL)
	{
		return (stack_b);
	}
	//this shit at fault probably
	if (stack_b->index < stack_b->nx->index)
	{
		stack_b = swap_in_stack_b(stack_b);
	}
//	printing_stacks(stack_b);
	return (stack_b);
}
