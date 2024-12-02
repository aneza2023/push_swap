/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_checking_input.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezkahavrankova <anezkahavrankova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:08:31 by ahavrank          #+#    #+#             */
/*   Updated: 2024/11/28 11:08:13 by anezkahavra      ###   ########.fr       */
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
		if (is_not_num(argv[i]) == 1)
			return (1);
		else if ((is_sign(argv[i]) == 1) && (is_not_num(argv[i + 1] != 1)))
			return (1);
		else
			i++;
	}
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

int	repetition(char *argv, stack *stack_a)
{
	int	arg;

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
