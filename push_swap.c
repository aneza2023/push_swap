/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naomi <naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:20:10 by codespace         #+#    #+#             */
/*   Updated: 2024/12/30 23:25:48 by naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checking_input(char *argv)
{
	int i;
	
	i = 0;
	while (argv[i] != '\0')
	{
		if (is_not_num(argv[i]) == 1)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		if ((is_sign(argv[i]) == 1) && (is_num(argv[i + 1]) != 1))
		{
			write(2, "Error\n", 6);
			return (1);
		}	
		if (modified_atoi(argv) > 2147483647 || modified_atoi(argv) < -2147483648)
		{
			write(2, "Error\n", 6);
			return (1);
		}
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
		write(2, "Error\n", 6);
		return (1);
	}
	stack_a = NULL;
	i = argc - 1;
	arr_arg = (int *)malloc(argc *(sizeof(int)));
	if (arr_arg == NULL)
		return (1);
	while (i >= 1) 
	{
		if (checking_input(argv[i]) == 1)
			return (1);
		arr_arg[i] = arg = ft_atoi(argv[i]);	
		stack_a = inserting_arg(stack_a, arg);
		i--;
	}
	stack_a = add_index(arr_arg, stack_a, argc);		
	return (0);
}
