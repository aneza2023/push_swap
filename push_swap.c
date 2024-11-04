/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:20:10 by codespace         #+#    #+#             */
/*   Updated: 2024/11/04 14:38:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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