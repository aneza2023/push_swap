/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo_under100.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:29:11 by anezkahavra       #+#    #+#             */
/*   Updated: 2024/12/04 13:12:47 by codespace        ###   ########.fr       */
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
		stack_b = checking_stack_b(stack_b);
		push_to_a(stack_a_fp, stack_b_fp);
	}
	printing_stacks(stack_a);
	return (0);
}
