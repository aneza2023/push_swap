/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_checking_input.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:08:31 by ahavrank          #+#    #+#             */
/*   Updated: 2025/01/09 14:32:21 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	is_not_num(int c)
{
	if ((c >= 1 && c <= 42) || (c == 44))
		return (1);
	else if ((c >= 46 && c <= 47) || (c >= 58 && c <= 127))
		return (1);
	return (0);
}

int	is_sign(int c)
{
	if (c == 45 || c == 43)
		return (1);
	return (0);
}

int	repetition(t_stack *stack_a)
{
	t_stack	*temp;

	temp = stack_a;
	while (temp != NULL)
	{
		stack_a = temp;
		while (stack_a != NULL)
		{
			if (stack_a->val == temp->val)
			{
				while (stack_a->nx != NULL)
				{
					if (stack_a->nx->val == temp->val)
						return (1);
					stack_a = stack_a->nx;
				}
			}
			stack_a = stack_a->nx;
		}
		temp = temp->nx;
	}
	return (0);
}
