/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezkahavrankova <anezkahavrankova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:52:36 by codespace         #+#    #+#             */
/*   Updated: 2024/11/10 21:34:03 by anezkahavra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h> 

typedef struct node{
    int value;
    struct node *next;
//    struct node *prev;
} stack;

stack *inserting_arg(stack *stack_a, int arg);
stack *swap_in_stack(stack *stack_a);
stack *rotate_stack(stack *stack_a);
stack *reverse_rotate(stack *stack_a);
int   push_to_a(stack **stack_a, stack **stack_b);
int   push_to_b(stack **stack_a, stack **stack_b);
int	not_number(char *argv);
int	ft_isalpha(int c);

#endif