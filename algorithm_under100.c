/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_under100.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:09:49 by codespace         #+#    #+#             */
/*   Updated: 2025/01/09 14:32:21 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	algori_under100(t_stack *stack_a, t_stack *stack_b, int argc)
{
	t_stack			**stack_a_fp;
	t_stack			**stack_b_fp;
	static int		chunk;
	int				k;
	int				old_argc;

	chunk = (argc - 1) / 5;
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
		if (k == old_argc / 5)
		{
			chunk += old_argc / 5;
			k = 0;
		}
	}
	rearanging_stack_b(stack_a, stack_b, argc);
	return (0);
}

t_stack	*cheapest_numer(t_stack *stack_a, int chunk, int argc)
{
	int	half;
	int	first;
	int	sec;

	half = argc / 2;
	first = first_index(stack_a, chunk, argc);
	sec = second_index(stack_a, chunk, argc);
	if (((half - first) > (half - sec)) || ((half - first) == (half - sec)))
	{
		while (first >= 2)
		{
			stack_a = rotate_stack_a(stack_a);
			first--;
		}
	}
	else
	{
		while (sec >= 1)
		{
			stack_a = reverse_rotate_a(stack_a);
			sec--;
		}
	}
	return (stack_a);
}

int	first_index(t_stack *stack_a, int ch, int argc)
{
	int				i;
	t_stack			*tempfront;

	tempfront = stack_a;
	i = 1;
	while (tempfront != NULL && i < argc)
	{
		if (tempfront->index <= ch)
			break ;
		tempfront = tempfront->nx;
		i++;
	}
	if (tempfront == NULL && i != 1)
		tempfront = stack_a;
	if (tempfront != NULL && i == argc)
		i = 1;
	return (i);
}

int	second_index(t_stack *stack_a, int ch, int argc)
{
	int		i;
	t_stack	*tempback;
	t_stack	*temp;

	temp = stack_a;
	while (temp->nx != NULL)
	{
		temp = temp->nx;
	}
	tempback = temp;
	i = 1;
	while (tempback != NULL)
	{
		if (tempback->index <= ch)
			break ;
		tempback = tempback->prev;
		i++;
	}
	if (tempback == NULL && i != 1)
		tempback = stack_a;
	if (tempback != NULL && i == argc)
		i = 1;
	return (i);
}

t_stack	*checking_stack_b(t_stack *stack_b)
{
	if (stack_b == NULL || stack_b->nx == NULL)
	{
		return (stack_b);
	}
	if (stack_b->index < stack_b->nx->index)
	{
		stack_b = swap_in_stack_b(stack_b);
	}
	return (stack_b);
}
