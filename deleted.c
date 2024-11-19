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