/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_under100.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:09:49 by codespace         #+#    #+#             */
/*   Updated: 2024/11/21 15:38:03 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	algori_under100(stack *stack_a, stack *stack_b, int argc)
{
	stack	**stack_a_fp;
	stack	**stack_b_fp;
	int		chunk;

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
	printing_stacks(stack_a);
	return (0);
}

stack	*cheapest_numer(stack *stack_a, int chunk, int argc)
{
	int	half;
	int	first_ind;
	int	sec_ind;

	half = argc/ 2;
	first_ind = first_index(stack_a, chunk);
	sec_ind = second_index(stack_a, chunk);
	if (((half - first_ind) > (half - sec_ind)) || ((half - first_ind) == (half - sec_ind))){
		while (first_ind >= 2){
		stack_a = rotate_stack_a(stack_a);
		first_ind--;
		}
	}
	else
	{
		while (sec_ind >= 1)
		{
			stack_a = reverse_rotate_a(stack_a);
			sec_ind--;
		}
	}
	printing_stacks(stack_a);
	return (stack_a);
}

int	first_index(stack *stack_a, int argc)
{
	int				i;
	static int		k;
	stack			*tempfront;

	tempfront = stack_a;
	i = 1;

	printf("argc: %d\n", argc);
	while (tempfront != NULL)
	{
		if (tempfront->index <= argc)
			break ;
		tempfront = tempfront->nx;
		i++;
	}
	if (tempfront == NULL && i != 1)
	{
		tempfront = stack_a;
		i = 1;
		k++;
	}
	printf("1st from top: %d, position> %d\n", tempfront->val, i);
	printf("velikost k: %d\n", k);
	return (i);
}

int	second_index(stack *stack_a, int argc)
{
	int		i;
	int		k;
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
		if (tempback->index <= argc)
			break ;
		tempback = tempback->prev;
		i++;
	}
	if (tempback == NULL && i != 1)
	{
		tempback = temp;
		i = 1;
		if (k == argc)
			argc += 2;
		k++;
	}
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
