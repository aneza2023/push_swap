/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:29:02 by ahavrank          #+#    #+#             */
/*   Updated: 2024/11/21 15:27:42 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	printing_stacks(stack *stack_a)
{
	while (stack_a != NULL)
	{
		printf("\nSTACK A:%d with index: %d\n", stack_a->val, stack_a->index);
		stack_a = stack_a ->nx;
	}
	return (0);
}
