/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo_under100.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naomi <naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:29:11 by anezkahavra       #+#    #+#             */
/*   Updated: 2024/12/27 14:59:59 by naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rearanging_stack_b(stack *stack_a, stack *stack_b, int argc)
{
	stack			**stack_b_fp;
	stack			**stack_a_fp;
	
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

int	where_biggest(stack *stack_b, int argc)
{
	int		i;

	i = 0;
	while (stack_b != NULL)
	{
		if (stack_b->index == argc)
			break;
		stack_b = stack_b->nx;
		i++;
	}
	return (i);
}
/* 
int	rearanging_stack_b(stack *stack_a, stack *stack_b, int argc)
{
	stack	**stack_a_fp;
	stack	**stack_b_fp;

	stack_a_fp = &stack_a;
	stack_b_fp = &stack_b;
	while (stack_b != NULL)
	{
		if (stack_b->index == (argc - 1)){
			push_to_a(stack_a_fp, stack_b_fp);
			break;
		}
		else{
			if (end_big(stack_b, argc) < first_big(stack_b, argc))
			{
				stack_b = rotate_stack_b(stack_b);
			}
			else{
				stack_b = reverse_rotate_b(stack_b);
			}
		}
		argc--;
	}
	return (0);
}

int	end_big(stack *stack_b, int argc)
{
	int		i;
	stack	*temp;
	stack	*tempback;

	temp = stack_b;
	i = 1;
	while (temp->nx != NULL)
	{
		temp = temp->nx;
	}
	tempback = temp;
	while (tempback != NULL)
	{
		if (temp->index == argc)
			break ;
		tempback = tempback->prev;
		i++;
	}
	return (i);
}

int	first_big(stack *stack_b, int argc)
{
	int		i;
	stack	*temp;

	temp = stack_b;
	i = 1;
	while (temp != NULL)
	{
		if (temp->index == 1)
			break ;
		temp = temp->nx;
		i++;
	}
	return (i);
} */
