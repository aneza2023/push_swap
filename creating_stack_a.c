/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_stack_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:36:36 by codespace         #+#    #+#             */
/*   Updated: 2025/01/09 14:32:21 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*inserting_arg(t_stack *stack_a, int arg)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
	{
		write(2, "Error\n", 6);
		free_stack(stack_a);
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
			if (arr_arg[i] >= arr_arg[i + 1])
			{
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

t_stack	*add_index(int *arr_arg, t_stack *stack_a, int argc)
{
	int		i;
	t_stack	*temp;

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
