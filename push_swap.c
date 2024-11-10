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
		printf("Numbers for swap_push were not provided\n");
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
//	stack_a = swap_in_stack(stack_a);
//	stack_a = rotate_stack(stack_a);
//	stack_a = reverse_rotate(stack_a);
	stack_a_fp = &stack_a;
	stack_b_fp = &stack_b;
	push_to_a(stack_a_fp, stack_b_fp);
	push_to_a(stack_a_fp, stack_b_fp);
	push_to_b(stack_a_fp, stack_b_fp);
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