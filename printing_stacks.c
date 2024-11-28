/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:29:02 by ahavrank          #+#    #+#             */
/*   Updated: 2024/11/28 16:00:37 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	printing_stacks(stack *stack_a)
{
	if (stack_a == NULL)
	{
		printf("ERROR PRINT");
		return (1);
	}
	while (stack_a != NULL)
	{
		printf("\nSTACK:%d with index: %d\n", stack_a->val, stack_a->index);
		stack_a = stack_a ->nx;
	}
	return (0);
}
