/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:20:10 by codespace         #+#    #+#             */
/*   Updated: 2024/11/15 13:48:06 by ahavrank         ###   ########.fr       */
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
	int		i;
	int		arg;
	int		*arr_arg;
	stack	*stack_a;
	stack	*stack_b;
	stack	**stack_a_fp;
	stack	**stack_b_fp;

	if(argc <= 1 || (argc == 2 && !argv[1][0])){
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
	arr_arg = (int *)malloc(argc *(sizeof(int)));
	if (arr_arg == NULL)
		return (1);
	while (i >= 1)
	{
		arg = atoi(argv[i]);
		arr_arg[i] = arg;
		stack_a = inserting_arg(stack_a, arg);
		i--;
	}
	arr_arg = sorting_for_index (arr_arg, argc);
	i = 1;
	while (argv[i] != NULL)
	{
		if (repetition(argv[i], stack_a) == 1){
			printf("Error\n");
			return (1);
		}
		else
			i++;
	}
	stack_a_fp = &stack_a;
	stack_b_fp = &stack_b;
//	add_index(arr_arg, stack_a_fp, argc);
// CHECK: PRINTING STACK
	while (stack_a != NULL)
	{
		printf("\nSTACK A:%d\n", stack_a->value);
		stack_a = stack_a ->next;
	}
	while (stack_b != NULL)
	{
		printf("\nSTACK B:%d\n", stack_b->value);
		stack_b = stack_b ->next;
	}
	return (0);
}
// {}
