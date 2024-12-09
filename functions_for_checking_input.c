	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_checking_input.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:08:31 by ahavrank          #+#    #+#             */
/*   Updated: 2024/12/02 14:16:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// add check for long int, neg/pos, vyzkouset pomlcku zvlast
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

int	repetition(stack *stack_a)
{
	stack	*temp;

	temp = (stack *)malloc(sizeof(stack));
	if (temp == NULL)
		return (1);
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
