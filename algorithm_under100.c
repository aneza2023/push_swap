/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_under100.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:09:49 by codespace         #+#    #+#             */
/*   Updated: 2024/11/20 13:45:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	algori_under100(stack *stack_a, stack *stack_b, int argc)
{
	stack	**stack_a_fp;
	stack	**stack_b_fp;
	
	while (stack_a != NULL){
		stack_a = cheapest_numer(stack_a, argc);
 		stack_a_fp = &stack_a;
	//	stack_b = checking_stack_b(stack_b);
		stack_b_fp = &stack_b;
		push_to_b(stack_a_fp, stack_b_fp); 
		argc--;
	}
	printing_stacks(stack_b);
	return (0);
}

stack	*cheapest_numer(stack *stack_a, int argc)
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
//	printing_stacks(stack_a);
	return (stack_a);
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
	if (tempfront == NULL && i != 1){
		tempfront = stack_a;
		i = 1;
		argc += argc;
	}
	printf("1st from top: %d, position> %d\n", tempfront->value, i);
	return (i);
}

int	second_index(stack *stack_a, int argc)
{
	int		i;
	stack	*tempback;
	stack	*temp;

	temp = stack_a;
	argc = argc / 5;
	while (temp->next != NULL)
	{
		temp = temp->next;
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
	if (tempback == NULL && i != 1){
		tempback = temp;
		i = 1;
		argc += argc;
	}
	printf("1st from back: %d, position> %d\n", tempback->value, i);
	return (i);
}

stack	*checking_stack_b(stack *stack_b)
{
	if (stack_b == NULL)
		return (stack_b);
	while (stack_b->index >= stack_b->next->index){
		stack_b = rotate_stack_b(stack_b);
	}
	return (stack_b);
}