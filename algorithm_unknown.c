/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_unknown.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:22:57 by ahavrank          #+#    #+#             */
/*   Updated: 2025/03/06 19:42:54 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	algorithm(t_stack *stack_a, int argc)
{
	t_stack	*stack_b;

	if (repetition(stack_a) == 1)
	{
		write(2, "Error\n", 6);
		free_stack(stack_a);
		return (1);
	}
	if (correct_order(stack_a) == 1)
		return (1);
	stack_b = NULL;
	if (argc == 3)
		algori_for_2(stack_a);
	else if (argc == 4)
		algori_for_3(stack_a);
	else if (argc > 4 && argc <= 6)
		algori_under_5(stack_a, stack_b, argc);
	else if (argc > 6 && argc <= 100)
		algori_under100(stack_a, stack_b, argc);
	else if (argc > 100)
		algori_under500(stack_a, stack_b, argc);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

int	algori_for_2(t_stack *stack_a)
{
	if (stack_a->val > stack_a->nx->val)
		swap_in_stack_a(stack_a);
	return (0);
}
