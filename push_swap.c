/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:20:10 by codespace         #+#    #+#             */
/*   Updated: 2024/11/04 15:10:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int i;
	int arg;
	stack *stack_a;
//	stack *stack_b;
	
	// to do: prevent strings as input - split function maybe, check for repetition
	if (argc <= 1 || (argc == 2 && !argv[1][0])){
		printf("Numbers for swap_push were not provided\n");
		return (1);
	}
	i = 1;
	stack_a = NULL;
//	stack_b = NULL;
	while (i != argc){
		arg = atoi(argv[i]);
		stack_a = inserting_arg(stack_a, arg);	
		i++;	
	} // created stack a consisting of arguments input
	while (stack_a != NULL){
		printf("%d ->", stack_a->value);
		stack_a = stack_a ->next;
	}
	return (0);
}
// {}