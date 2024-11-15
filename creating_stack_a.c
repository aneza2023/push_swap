/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_stack_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:36:36 by codespace         #+#    #+#             */
/*   Updated: 2024/11/15 17:42:38 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// maybe could add a pointer to a previous node
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
	new_node->value = arg;
	new_node->next = stack_a;
	return (new_node);
}

//add index for easier sorting
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

int	add_index(int *arr_arg, stack **stack_a, int argc)
{
	int		i;
	stack	*temp;

	temp = *stack_a;
	while (temp != NULL)
	{
		i = 1;
		while (i < argc)
		{
			if ((temp)->value == arr_arg[i])
				(temp)->index = i;
			i++;
		}
		(temp) = (temp)->next;
	}
	temp = *stack_a;
/* 	while (*stack_a != NULL)
	{
		printf("INDEX>  %d\n", (*stack_a)->index);
		*stack_a = (*stack_a)->next;
	} */
	return (0);
}
