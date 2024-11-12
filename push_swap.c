/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezkahavrankova <anezkahavrankova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:20:10 by codespace         #+#    #+#             */
/*   Updated: 2024/11/11 22:46:26 by anezkahavra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int	algori(stack **stack_a, stack **stack_b)
{
	int i;
	stack	*checked_num;
	stack	*temp;

	checked_num = (stack *)malloc(sizeof(stack));
	if (checked_num == NULL)
		return (1);
	temp = (stack *)malloc(sizeof(stack));
	if (temp == NULL)
		return (1);
	temp = stack_a;
	while (temp != NULL && i < 20){
		checked_num->value = (*stack_a)->value;
		if (checked_num->value <= temp->value || temp.next )
			temp = temp->next; 
		else 
		(*stack_a) = (*stack_a)->next;
		i++;
	}
	printf("checked%d", checked_num->value);

	return (0);
} */

int	main(int argc, char *argv[])
{
	int i;
	int arg;
	stack *stack_a;
	stack *stack_b;
	stack **stack_a_fp;
	stack **stack_b_fp;
	
	if (argc <= 1 || (argc == 2 && !argv[1][0])){
		printf("Error\n");	
		return (1);
	}
	i = 1;
	while (argv[i] != NULL){
		if (not_number(argv[i]) == 1){
			printf("Error\n");
			return (1);
		}
		else
			i++;
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
	i = 1;
	while (argv[i] != NULL){
		if (repetition(argv[i], stack_a) == 1){
			printf("Error\n");
			return (1);
		}
		else
			i++;
		}
	stack_a_fp = &stack_a;
	stack_b_fp = &stack_b;
//	algori(stack_a_fp, stack_b_fp);
// CHECK: PRINTING STACK
	while (stack_a != NULL){
		printf("\nSTACK A:%d\n", stack_a->value);
		stack_a = stack_a ->next;
	} 
	while (stack_b != NULL){
		printf("\nSTACK B:%d\n", stack_b->value);
		stack_b = stack_b ->next;
	} 
	return (0);
}
// {}