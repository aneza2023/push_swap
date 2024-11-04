/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:20:10 by codespace         #+#    #+#             */
/*   Updated: 2024/11/04 13:50:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>


int	main(int argc, char *argv[])
{
	int i;
	int arg;
	t_node *node;
	t_node *new_node;
	t_node *current;
	
	if (argc <= 1){
		printf("Numbers for swap_push were not provided\n");
		return (1);
	}
	i = 1;
	node = NULL;
	while (i != argc){
		arg = atoi(argv[i]);
		new_node = (t_node *)malloc(sizeof(t_node));
		if (new_node == NULL){
			printf("Allocation failed");
			return (NULL);
		}
		new_node->value = arg;
		new_node->next = NULL;
		if (node == NULL)
			node = new_node;
		else {
			current = node;
			while (current->next != NULL)
				current = current->next;
			current->next = new_node;
		}
	}
	while (current != NULL){
		printf("%d", current->value);
		current = current -> next;
	}
	return (0);
}

// {}