/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:36:36 by codespace         #+#    #+#             */
/*   Updated: 2024/11/04 14:39:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *inserting_arg(t_node *node, int arg)
{
	t_node *new_node;

	new_node = (t_node*)malloc(sizeof(t_node));
	if (new_node == NULL){
		printf("Allocation failed");
		return (node);
	}
	new_node->value = arg;
	new_node->next = node;
	return (new_node);
}