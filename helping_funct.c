

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
    return (stack_a); 