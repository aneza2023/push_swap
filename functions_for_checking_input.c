/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_checking_input.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:08:31 by ahavrank          #+#    #+#             */
/*   Updated: 2024/11/21 15:29:14 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// add check for long int, neg/pos, vyzkouset pomlcku zvlast
int	not_number(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (is_alpha(argv[i]) == 1)
			return (1);
		else if ((is_sign(argv[i]) == 1) && (i != 0))
			return (1);
		else
			i++;
	}
	return (0);
}


int	is_alpha(int c)
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

int	repetition(char *argv, stack *stack_a)
{
	int	i;
	int	arg;

	i = 1;
	while (stack_a != NULL)
	{
		arg = atoi(argv);
		if (stack_a->val == arg)
		{
			while (stack_a->nx != NULL)
			{
				if (stack_a->nx->val == arg)
					return (1);
				stack_a = stack_a->nx;
			}
		}
		stack_a = stack_a->nx;
	}
	return (0);
}
