/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:20:10 by codespace         #+#    #+#             */
/*   Updated: 2024/12/06 14:28:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checking_input(char *argv, int argc)
{
	int i;
	
	i = 0;
	while (argv[i] != '\0')
	{
		if (is_not_num(argv[i]) == 1)
		{
			printf("Error\n");
			return (1);
		}
		if ((is_sign(argv[i]) == 1) && (is_num(argv[i + 1]) != 1))
		{
			printf("Error\n");
			return (1);
		}	
		else if (ft_atoi(argv))
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int		i;
	int 	arg;
	int		*arr_arg;
	stack	*stack_a;

	if (argc <= 1 || (argc == 2 && !argv[1][0])) 
	{
		printf("Error\n");
		return (1);
	}
	stack_a = NULL;
	i = argc - 1;
	arr_arg = (int *)malloc(argc *(sizeof(int)));
	if (arr_arg == NULL)
		return (1);
	while (i >= 1) 
	{
		if (checking_input(argv[i], argc) == 1)
			return (1);
		arr_arg[i] = arg = atoi(argv[i]);	
		stack_a = inserting_arg(stack_a, arg);
		i--;
	}
	stack_a = add_index(arr_arg, stack_a, argc);	
	return (0);
}
