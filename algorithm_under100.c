/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_under100.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:09:49 by codespace         #+#    #+#             */
/*   Updated: 2024/11/20 12:17:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	algori_under100(stack *stack_a, stack *stack_b, int argc)
{
	cheapest_numer(stack_a, argc);
	return (0);
}

int	cheapest_numer(stack *stack_a, int argc)
{
	int	half;
	int	first_ind;
	int	sec_ind;

	half = argc / 2;
	first_ind = first_index(stack_a, argc);
	sec_ind = second_index(stack_a, argc);
	if (((half - first_ind) > (half - sec_ind)) || ((half - first_ind) == (half - sec_ind))){
		while (first_ind >= 2){
		stack_a = rotate_stack_a(stack_a);
		first_ind--;
		}	
	}
	else{
		while (sec_ind >= 1){
			stack_a = reverse_rotate_a(stack_a);
			sec_ind--;
		}
	}
	printing_stacks(stack_a);
	return (0);
}

int	first_index(stack *stack_a, int argc)
{
	int 	i;
	stack	*tempfront;

	tempfront = stack_a;
	argc = argc / 5;
	i = 1;
	while (tempfront != NULL)
	{
		if (tempfront->index <= argc)
			break ;
		tempfront = tempfront->next;
		i++;
	}
 printf("1st from top: %d, position> %d", tempfront->value, i);
	return (i);
}

int	second_index(stack *stack_a, int argc)
{
	int		i;
	stack	*tempback;

	tempback = stack_a;
	argc = argc / 5;
	while (tempback->next != NULL)
	{
		tempback = tempback->next;
	}
	i = 1;
	while (tempback != NULL)
	{
		if (tempback->index <= argc)
			break ;
		tempback = tempback->prev;
		i++;
	}
	printf("1st from back: %d, position> %d", tempback->value, i);
	return (i);
}
