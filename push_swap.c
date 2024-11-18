/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:20:10 by codespace         #+#    #+#             */
/*   Updated: 2024/11/18 10:13:19 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	int		arg;
	int		*arr_arg;
	stack	*stack_a;
	stack	**stack_a_fp;

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
		i++;
	}
	i = argc - 1;
	stack_a = NULL;
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
		i++;
	}
	stack_a_fp = &stack_a;
	add_index(arr_arg, stack_a_fp, argc);
	return (0);
}
