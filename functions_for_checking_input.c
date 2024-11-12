#include "push_swap.h"

int	not_number(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0'){
		if (ft_isalpha(argv[i]) == 1)
			return (1); 
		i++;
	}
	return (0);
} 

int	ft_isalpha(int c)
{
	if ((c >= 1 && c <= 44) || (c >= 46 && c <= 47) || (c >= 58 && c <= 127))
	{
		return (1);
	}
	return (0);
}

int	repetition(char *argv, stack *stack_a)
{
	int	i;
	int arg;

	i = 1;
	while (stack_a != NULL){
		arg = atoi(argv);
		if (stack_a->value == arg){
			while (stack_a->next != NULL){
				if(stack_a->next->value == arg)
					return (1);
				stack_a = stack_a->next;
			}
		}
		stack_a = stack_a->next;
	}
	return (0);
}

// {}