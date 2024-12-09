/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_unknown.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:22:57 by ahavrank          #+#    #+#             */
/*   Updated: 2024/12/09 08:12:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	algorithm(stack *stack_a, int argc)
{
	stack	*stack_b;

	if (repetition(stack_a) == 1)
	{
		printf("Error\n");
		return (1);
	}
	stack_b = NULL;
	if (argc == 3)
		algori_for_2(stack_a);
	else if (argc == 4)
		algori_for_3(stack_a);
	else if (argc > 4 && argc <= 6)
		algori_under_5(stack_a, stack_b, argc);
	else if (argc > 6 && argc <= 100)
		algori_under100(stack_a, stack_b, argc);
	return (0);
}
