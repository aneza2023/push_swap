/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:20:10 by codespace         #+#    #+#             */
/*   Updated: 2024/11/04 14:35:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

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

int	main(int argc, char *argv[])
{
	int i;
	int arg;
	t_node *node;
	
	if (argc <= 1){
		printf("Numbers for swap_push were not provided\n");
		return (1);
	}
	i = 1;
	node = NULL;
	while (i != argc){
		arg = atoi(argv[i]);
		node = inserting_arg(node, arg);
		i++;	
	}
/* 	while (node != NULL){
		printf("%d ->", node->value);
		node = node ->next;
	} */
	return (0);
}
// {}