/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezkahavrankova <anezkahavrankova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:20:10 by codespace         #+#    #+#             */
/*   Updated: 2024/11/10 21:36:29 by anezkahavra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int i;
	int arg;
	stack *stack_a;
	stack *stack_b;
	stack **stack_a_fp;
	stack **stack_b_fp;
	
	// TO DO: prevent strings as an input - split function maybe, check for repetition
	if (argc <= 1 || (argc == 2 && !argv[1][0])){
		printf("Error\n");	
		return (1);
	}
	if (not_number(*argv) == 0){
		printf("Error\n");
		return (1);
	}
//  CREATING STACK_A - MATCHES INPUT
	i = argc - 1;
	stack_a = NULL;
	stack_b = NULL;
	while (i >= 1 ){
		arg = atoi(argv[i]);
		stack_a = inserting_arg(stack_a, arg);	
		i--;	
	} 
	stack_a_fp = &stack_a;
	stack_b_fp = &stack_b;
//	stack_a = rotate_stack(stack_a);
// CHECK: PRINTING STACK
	while (stack_a != NULL){
		printf("STACK A:%d\n", stack_a->value);
		stack_a = stack_a ->next;
	} 
	while (stack_b != NULL){
		printf("STACK B:%d\n", stack_b->value);
		stack_b = stack_b ->next;
	} 
	return (0);
}
// {}