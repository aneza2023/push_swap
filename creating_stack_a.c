/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_stack_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezkahavrankova <anezkahavrankova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:36:36 by codespace         #+#    #+#             */
/*   Updated: 2024/11/10 14:01:31 by anezkahavra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// maybe could add a pointer to a previous node
stack *inserting_arg(stack *stack_a, int arg)
{
	stack *new_node;

	new_node = (stack*)malloc(sizeof(stack));
	if (new_node == NULL){
		printf("Allocation failed");
		return (stack_a);
	}
	new_node->value = arg;
	new_node->next = stack_a;
	return (new_node);
}

//add index for easier sorting
void sorting_for_index(int argc, char *argv)


void BubbleSort(int a[], int array_size)
{
    int i, j, temp;
    for (i = 0; i < (array_size - 1); ++i)
    {
        for (j = 0; j < array_size - 1 - i; ++j )
        {
            if (a[j] > a[j+1])
            {
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
    }
}