#include "push_swap.h"

// CHECK: PRINTING STACK
/* 	while (node != NULL){
		printf("%d ->", node->value);
		node = node ->next;
	} */
/* 

 
//WORKING SWAP WITHOUT USING PREVIOUS
// putting values of 2nd in temp
    temp = (stack*)malloc(sizeof(stack));
    if (temp == NULL){
		printf("Allocation failed");
		return (stack_a);
	}
    temp->value = stack_a->next->value;
// deleting 2nd
    stack_a->next = stack_a->next->next;
// setting temp as 1st
    temp->next = stack_a;
    stack_a = temp;
/*     while (stack_a != NULL){
		printf("B: %d\n", stack_a->value);
		stack_a = stack_a ->next;
	}  */
   
//  {}  

int	not_number(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0'){
		if (ft_isalpha(argv[i]) == 1)
			return (0); 
		i++;
	}
	return (1);
} 

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}