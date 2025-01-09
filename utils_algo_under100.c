/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo_under100.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:29:11 by anezkahavra       #+#    #+#             */
/*   Updated: 2025/01/09 14:46:15 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rearanging_stack_b(t_stack *stack_a, t_stack *stack_b, int argc)
{
	t_stack			**stack_b_fp;
	t_stack			**stack_a_fp;

	stack_b_fp = &stack_b;
	stack_a_fp = &stack_a;
	while (stack_b != NULL)
	{
		if (where_biggest(stack_b, (argc - 1)) == 0)
		{
			push_to_a(stack_a_fp, stack_b_fp);
			argc--;
		}
		else if (where_biggest(stack_b, (argc - 1)) < ((argc - 1) / 2))
			stack_b = rotate_stack_b(stack_b);
		else
			stack_b = reverse_rotate_b(stack_b);
	}
	return (0);
}

int	where_biggest(t_stack *stack_b, int argc)
{
	int		i;

	i = 0;
	while (stack_b != NULL)
	{
		if (stack_b->index == argc)
			break ;
		stack_b = stack_b->nx;
		i++;
	}
	return (i);
}

void	help_for_first_round(t_stack **stack_a_fp, t_stack **stack_b_fp)
{
	push_to_a(stack_a_fp, stack_b_fp);
	push_to_a(stack_a_fp, stack_b_fp);
}
