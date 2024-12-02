/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:18:48 by ahavrank          #+#    #+#             */
/*   Updated: 2024/11/28 16:20:26 by ahavrank         ###   ########.fr       */
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

typedef struct node
{
	int			val;
	struct node	*nx;
	int			index;
	struct node *prev;
}	stack;

stack	*inserting_arg(stack *stack_a, int arg);
stack	*swap_in_stack_a(stack *stack_a);
stack	*rotate_stack_a(stack *stack_a);
stack	*reverse_rotate_a(stack *stack_a);
stack	*swap_in_stack_b(stack *stack_b);
stack	*rotate_stack_b(stack *stack_b);
stack	*reverse_rotate_b(stack *stack_b);
int		push_to_a(stack **stack_a, stack **stack_b);
int		push_to_b(stack **stack_a, stack **stack_b);
int		not_number(char *argv);
int		is_alpha(int c);
int		is_sign(int c);
int		repetition(char *argv, stack *stack_a);
int		algori_under100(stack *stack_a, stack *stack_b, int argc);
int		*sorting_for_index(int *arr_arg, int argc);
int		add_index(int *arr_arg, stack **stack_a, int argc);
int		numbering(int argc);
int		printing_stacks(stack *stack_a);
int		algorithm(stack *stack_a, int argc);
int		algori_for_2(stack *stack_a);
stack	*algori_for_3(stack *stack_a);
int		algori_under_5(stack *stack_a, stack *stack_b, int argc);
stack	*cheapest_numer(stack *stack_a, int chunk, int argc);
int		first_index(stack *stack_a, int chunk, int argc);
int		second_index(stack *stack_a, int chunk, int argc);
stack	*checking_stack_b(stack *stack_b);
stack	*allocation(stack *new_node);
int		back_to_a(stack *stack_a, stack *stack_b, int argc);
stack	*check_order(stack *stack_b);

#endif
