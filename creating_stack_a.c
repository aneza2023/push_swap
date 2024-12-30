/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_stack_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naomi <naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:36:36 by codespace         #+#    #+#             */
/*   Updated: 2024/12/30 23:08:35 by naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack	*inserting_arg(stack *stack_a, int arg)
{
	stack	*new_node;

	new_node = (stack *)malloc(sizeof(stack));
	if (new_node == NULL)
	{
		printf("Allocation failed");
		return (stack_a);
	}
	if (stack_a != NULL)
		stack_a->prev = new_node;
	new_node->prev = NULL;
	new_node->val = arg;
	new_node->nx = stack_a;
	return (new_node);
}

int	*sorting_for_index(int *arr_arg, int argc)
{
	int	i;
	int	j;
	int	temp;


	j = 1;
	while (j < argc)
	{
		i = 1;
		while (i < argc - j)
		{
			if (arr_arg[i] >= arr_arg[i + 1]){
				temp = arr_arg[i + 1];
				arr_arg[i + 1] = arr_arg[i];
				arr_arg[i] = temp;
			}
			i++;
		}
		j++;
	}
	return (arr_arg);
}

stack	*add_index(int *arr_arg, stack *stack_a, int argc)
{
	int		i;
	stack	*temp;

	arr_arg = sorting_for_index(arr_arg, argc);
	temp = stack_a;
	while (temp != NULL)
	{
		i = 1;
		while (i < argc)
		{
			if ((temp)->val == arr_arg[i])
				(temp)->index = i;
			i++;
		}
		(temp) = (temp)->nx;
	}
	temp = stack_a;
	free(arr_arg);
	algorithm(temp, argc);
	return (temp);
}
