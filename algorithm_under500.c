/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_under500.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naomi <naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:00:39 by codespace         #+#    #+#             */
/*   Updated: 2024/12/27 15:11:54 by naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	algori_under500(stack *stack_a, stack *stack_b, int argc)
{
	stack			**stack_a_fp;
	stack			**stack_b_fp;
	static int		chunk;
	int				k;
	int				old_argc;

	chunk = (argc - 1) / 11;
	old_argc = (argc - 1);
	k = 0;
	while (stack_a != NULL)
	{
		stack_a = cheapest_numer(stack_a, chunk, argc);
		stack_a_fp = &stack_a;
		stack_b_fp = &stack_b;
		stack_b = checking_stack_b(stack_b); 
		push_to_b(stack_a_fp, stack_b_fp);
		k++;
		if (k == old_argc / 11)
		{
			chunk += old_argc / 11;
			k = 0;
		}
	}
	rearanging_stack_b(stack_a, stack_b, argc);
	return (0);
}