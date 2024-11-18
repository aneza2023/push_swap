/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:20:10 by codespace         #+#    #+#             */
/*   Updated: 2024/11/15 17:50:37 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
//	push_to_b(stack_a_fp, stack_b_fp);
	push_to_a(stack_a_fp, stack_b_fp);
	add_index(arr_arg, stack_a_fp, argc);
//	algori_under100(stack_a_fp, stack_b_fp, argc);
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
