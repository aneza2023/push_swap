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
	
	// TO DO: prevent strings as an input - split function maybe, check for repetition
	if (argc <= 1 || (argc == 2 && !argv[1][0])){
		printf("Numbers for swap_push were not provided\n");
		return (1);
	}
//  CREATING STACK_A - MATCHES INPUT
	i = argc - 1;
	stack_a = NULL;
//	stack_b = NULL;
	while (i >= 1 ){
		arg = atoi(argv[i]);
		stack_a = inserting_arg(stack_a, arg);	
		i--;	
	} 
	return (0);
}
// {}