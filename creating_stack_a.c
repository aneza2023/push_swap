/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_stack_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:36:36 by codespace         #+#    #+#             */
/*   Updated: 2024/11/04 15:07:02 by codespace        ###   ########.fr       */
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
	new_node->prev = stack_a;
	new_node->value = arg;
	new_node->next = stack_a;
	return (new_node);
}

/* stack	*match_input(stack *stack_a)
{
	
} */
