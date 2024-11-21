/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_under100.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:09:49 by codespace         #+#    #+#             */
/*   Updated: 2024/11/21 17:06:30 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	algori_under100(stack *stack_a, stack *stack_b, int argc)
{
	stack			**stack_a_fp;
	stack			**stack_b_fp;
	static int		chunk;

	chunk = argc / 5;
	while (stack_a != NULL)
	{
		stack_a = cheapest_numer(stack_a, chunk, argc);
		stack_a_fp = &stack_a;
	//	stack_b = checking_stack_b(stack_b);
		stack_b_fp = &stack_b;
		push_to_b(stack_a_fp, stack_b_fp);
		argc--;
	}
//	printing_stacks(stack_a);
	return (0);
}

stack	*cheapest_numer(stack *stack_a, int chunk, int argc)
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
//	printing_stacks(stack_a);
	return (stack_a);
}

int	first_index(stack *stack_a, int ch, int argc)
{
	int				i;
	static int		k;
	stack			*tempfront;

	tempfront = stack_a;
	i = 1;
	printf("ch siz: %d\n", ch);
	while (tempfront != NULL && i < argc)
	{
		if (k == ch || k == 2 * ch || k == 3 * ch || k == 4 * ch || k == 5 * ch)
			ch += ch;
		printf("ch siz num.: %d\n", ch);
		if (tempfront->index <= ch)
			break ;
		tempfront = tempfront->nx;
		i++;
	}
	k++;
	if (tempfront == NULL && i != 1)
		tempfront = stack_a;
	if (tempfront != NULL && i == argc)
		i = 1;
	printf("1st from top: %d, position> %d\n", tempfront->val, i);
	printf("velikost K: %d\n", k);
	return (i);
}

int	second_index(stack *stack_a, int ch, int argc)
{
	int		i;
	stack	*tempback;
	stack	*temp;

	temp = stack_a;
	while (temp->nx != NULL)
	{
		temp = temp->nx;
	}
	tempback = temp;
	i = 1;
	while (tempback != NULL)
	{
		if (tempback->index <= chunk)
			break ;
		tempback = tempback->prev;
		i++;
	}
	if (tempback == NULL && i != 1)
	{
		tempback = stack_a;
		chunk += 2;
	}
	if (tempback != NULL && i == argc)
		i = 1;
	printf("1st from back: %d, position> %d\n", tempback->val, i);
	return (i);
}

stack	*checking_stack_b(stack *stack_b)
{
	if (stack_b == NULL)
		return (stack_b);
	while (stack_b->index >= stack_b->nx->index)
	{
		stack_b = rotate_stack_b(stack_b);
	}
	return (stack_b);
}
