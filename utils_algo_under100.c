/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo_under100.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezkahavrankova <anezkahavrankova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:29:11 by anezkahavra       #+#    #+#             */
/*   Updated: 2024/11/28 01:15:03 by anezkahavra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int back_to_a(stack **stack_a, stack **stack_b, int argc)
{
    int chunk;
    int left;

    chunk = argc / 5;
    left = (argc - 1) % 5;
    *stack_b = check_order(*stack_b, chunk, left);
    return (0);
}

stack *check_order(stack *stack_b, int chunk, int left)
{
    int i;
    int k;

    i = 1;
    printf("chunk> %d, left> %d", chunk, left); 
    while (i < (chunk + left)){
        if ((stack_b)->index < (stack_b)->nx->index)
            stack_b = swap_in_stack_b(stack_b);
        stack_b = stack_b->nx;
        i++;
    }
    k = 0;
    while (stack_b != NULL)
    {
        stack_b = stack_b->prev;
        printf("stack B> prev>> %d", stack_b->index);
        k++;
    }
    printf("i> %d  +  k> %d", i, k);
    return (stack_b);
}