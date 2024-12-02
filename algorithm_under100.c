/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_under100.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezkahavrankova <anezkahavrankova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:09:49 by codespace         #+#    #+#             */
/*   Updated: 2024/11/29 15:58:42 by anezkahavra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	algori_under100(stack *stack_a, stack *stack_b, int argc)
{
	stack			**stack_a_fp;
	stack			**stack_b_fp;
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
		stack_b = checking_stack_b(stack_b); //was unnder push, worked
		push_to_b(stack_a_fp, stack_b_fp);
	//	argc--;		// maybe not needed, used before
		k++;
		if (k == old_argc / 5)
		{
			chunk += old_argc / 5;
			k = 0;
		}
	}
	back_to_a(stack_a, stack_b, old_argc);
//	printing_stacks(stack_b);
	printf("argc: %d", old_argc);
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
	stack			*tempfront;

	tempfront = stack_a;
	i = 1;
//	printf("chunk siz: %d\n argc siz:%d\n", ch, argc);
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
//	printf("1st from top: %d (index %d), position> %d\n", tempfront->val, tempfront->index, i);
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
		if (tempback->index <= ch)
			break ;
		tempback = tempback->prev;
		i++;
	}
	if (tempback == NULL && i != 1)
		tempback = stack_a;
	if (tempback != NULL && i == argc)
		i = 1;
//	printf("1st from back: %d (index %d), position> %d\n", tempback->val, tempback->index, i);
	return (i);
}

stack	*checking_stack_b(stack *stack_b)
{
	if (stack_b == NULL || stack_b->nx == NULL)
	{
		return (stack_b);
	}
	//this shit at fault probably
	if (stack_b->index < stack_b->nx->index)
	{
		stack_b = swap_in_stack_b(stack_b);
	}
//	printing_stacks(stack_b);
	return (stack_b);
}
