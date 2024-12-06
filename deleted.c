// functioning main

/* 
int	main(int argc, char *argv[])
{
	int		i;
	int		arg;
	int		*arr_arg;
	stack	*stack_a;
	stack	**stack_a_fp;

	if (argc <= 1 || (argc == 2 && !argv[1][0]))
	{
		printf("Error\n");
		return (1);
	}
	i = argc - 1;
	stack_a = NULL;
	arr_arg = (int *)malloc(argc *(sizeof(int)));
	if (arr_arg == NULL)
		return (1);
	while (i >= 1)
	{
		arg = ft_atoi(argv[i]);
		arr_arg[i] = arg;
		stack_a = inserting_arg(stack_a, arg);
		i--;
	}
	arr_arg = sorting_for_index (arr_arg, argc);
	i = 1;
	while (argv[i] != NULL)
	{
		if (repetition(argv[i], stack_a) == 1 || (not_number(argv[i]) == 1))
		{
			printf("Error\n");
			return (1);
		}
		i++;
	}
	stack_a_fp = &stack_a;
	add_index(arr_arg, stack_a_fp, argc);
	algorithm(stack_a, argc);
	return (0);
} */












// deleted from algo_under5

/* int	algori_under_5(stack *stack_a, stack *stack_b, int argc)
{
	stack	**stack_a_fp;
	stack	**stack_b_fp;

	stack_a_fp = &stack_a;
	stack_b_fp = &stack_b;
	push_to_b(stack_a_fp, stack_b_fp);
	if (argc > 5)
		push_to_b(stack_a_fp, stack_b_fp);
	stack_a = algori_for_3(stack_a);
	if (stack_b->nx != NULL && stack_b->val < stack_b->nx->val)
		stack_b = swap_in_stack_b(stack_b);
	another_check(stack_a, stack_b);
	return (0);
}
int	another_check(stack *stack_a, stack *stack_b)
{
	stack	**stack_a_fp;
	stack	**stack_b_fp;
	int		i;

	stack_a_fp = &stack_a;
	stack_b_fp = &stack_b;
	i = 0;
	while (stack_b->nx != NULL && i < 1){
		if (stack_b->index == 5 || (stack_b->index <= 3 && stack_b->nx->index == 1))
			push_to_a(stack_a_fp, stack_b_fp);
		else if (stack_b->index == 4 || (stack_b->index == 3 && stack_b->nx->index == 2))
			stack_a = reverse_rotate_a(stack_a);
		i++;
	}
	if (stack_b->index == (stack_a->index - 1))
		push_to_a(stack_a_fp, stack_b_fp);
	if (stack_b->index <= 2 && stack_a->index >= 4)
		stack_a = rotate_stack_a(stack_a);
	if (stack_b->index <= 2 && stack_a->index == 5 || stack_b->index == 1)
		stack_a = rotate_stack_a(stack_a);
	if ((stack_a->index == 4 && stack_b->index == 2) || (stack_a->index == 5 && stack_b->index == 3))
		stack_a = reverse_rotate_a(stack_a);
	else
		and_another(stack_a, stack_b);
	printing_stacks(stack_a);
	printf("\n\n\n\n");
	return (0);
}

int	and_another(stack *stack_a, stack *stack_b)
{
	stack	**stack_a_fp;
	stack	**stack_b_fp;
	int		i;

	stack_a_fp = &stack_a;
	stack_b_fp = &stack_b;
	if (stack_a->index == 3 && stack_a->nx->index == 2)
		stack_a = swap_in_stack_a(stack_a);
	while (stack_b != NULL){
		push_to_a(stack_a_fp, stack_b_fp);
	}
	while (stack_a->index != 1)
	{
		stack_a = rotate_stack_a(stack_a);
	}
	printing_stacks(stack_b);
	return (0);
}/ */



























/* 	while (stack_b != NULL)
	{
		if (stack_b->val >= stack_a->val && stack_b->val <= stack_a->nx->val)
		{
			push_to_a(stack_a_fp, stack_b_fp);
			stack_a = swap_in_stack_a(stack_a);
		}
		else if (stack_b->index >= 4 && stack_b->index >= stack_a->index)
		{
			push_to_a(stack_a_fp, stack_b_fp);
			stack_a = rotate_stack_a(stack_a);
		}
		else if (stack_b->index <= 2)
		{
			push_to_a(stack_a_fp, stack_b_fp);
		}
		else
			stack_a = rotate_stack_a(stack_a);
	} */

/* 	if (stack_b->nx != NULL && stack_b->val < stack_b->nx->val)
		stack_b = swap_in_stack_b(stack_b); */

/* int	algori_under100(stack **stack_a, stack **stack_b, int argc)
{
	int		i;
	int		k;
	stack	*temp;
	stack	*tempback;
	stack	*tempfront;

	tempfront = *stack_a;
	temp = *stack_a;
	argc = argc / 5;
	i = 0;
	while (tempfront != NULL)
	{
		if (tempfront->index <= argc)
			break ;
		tempfront = tempfront->next;
		i++;
	}
	printf("1st from top: %d, position> %d", tempfront->value, i);
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	tempback = temp;
//	printf("tempstartback: %d", tempback->value);
	k = 0;
	while (tempback != NULL)
	{
		if (tempback->index <= argc)
			break ;
		tempback = tempback->prev;
		k++;
	}
	printf("1st from back: %d, position> %d", tempback->value, k);
	return (0);
} */

/* int	algori_for_2(stack *stack_a)
{
	stack	**stack_a_fp;
	stack	**stack_b_fp;
	stack	*stack_b;

	stack_a_fp = &stack_a;
	stack_b = NULL;
	stack_b = allocation(stack_b);
	stack_b_fp = &stack_b;
	push_to_b(stack_a_fp, stack_b_fp);
	push_to_b(stack_a_fp, stack_b_fp);
	checking_stack_b(stack_b);
	printing_stacks(stack_b);
	return (0);
} */


	/* int	i;
	int	k;

	i = 1;
//	printf("chunk> %d, left> %d", chunk, left);
	while (i < (chunk + left))
	{
	if ((stack_b)->index < (stack_b)->nx->index)
		stack_b = swap_in_stack_b(stack_b);
	stack_b = stack_b->nx;
	i++;
	}
	k = 0;
/*	 while (stack_b != NULL)
	{
	stack_b = stack_b->prev;
	printf("stack B> prev>> %d", stack_b->index);
	k++;
	} */
//	printf("i> %d  +  k> %d", i, k); */