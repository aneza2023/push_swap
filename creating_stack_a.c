/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_stack_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezkahavrankova <anezkahavrankova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:36:36 by codespace         #+#    #+#             */
/*   Updated: 2024/11/10 14:01:31 by anezkahavra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// maybe could add a pointer to a previous node
stack *inserting_arg(stack *stack_a, int arg)
{
	stack *new_node;

	new_node = (stack*)malloc(sizeof(stack));
	if (new_node == NULL){
		printf("Allocation failed");
		return (stack_a);
	}
	new_node->value = arg;
	new_node->next = stack_a;
	return (new_node);
}

//add index for easier sorting
int sorting_for_index(int *arr_arg, int argc)
{
	int i;
	int	j;
	int	temp;

	i = 1;
	j = 1;
	while (j < argc){
		while (i < argc - j){
			if (arr_arg[i] >= arr_arg[i + 1]){
				temp = arr_arg[i + 1];
				arr_arg[i + 1] = arr_arg[i];
				arr_arg[i] = temp;
			}
			i++;
		}
		j++;
	}
	i = 1;
	while (i < argc){
		printf("array>%d", arr_arg[i]);
		i++;
	}
	return (0);
}
