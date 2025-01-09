/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:18:48 by ahavrank          #+#    #+#             */
/*   Updated: 2025/01/09 14:47:08 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	struct node	*prev;
}	t_stack;

t_stack		*inserting_arg(t_stack *stack_a, int arg);
t_stack		*swap_in_stack_a(t_stack *stack_a);
t_stack		*rotate_stack_a(t_stack *stack_a);
t_stack		*reverse_rotate_a(t_stack *stack_a);
t_stack		*swap_in_stack_b(t_stack *stack_b);
t_stack		*rotate_stack_b(t_stack *stack_b);
t_stack		*reverse_rotate_b(t_stack *stack_b);
int			push_to_a(t_stack **stack_a, t_stack **stack_b);
int			push_to_b(t_stack **stack_a, t_stack **stack_b);
int			is_num(int c);
int			is_not_num(int c);
int			is_sign(int c);
int			repetition(t_stack *stack_a);
int			algori_under100(t_stack *stack_a, t_stack *stack_b, int argc);
int			*sorting_for_index(int *arr_arg, int argc);
t_stack		*add_index(int *arr_arg, t_stack *stack_a, int argc);
int			printing_stacks(t_stack *stack_a);
int			algorithm(t_stack *stack_a, int argc);
int			algori_for_2(t_stack *stack_a);
t_stack		*algori_for_3(t_stack *stack_a);
int			algori_under_5(t_stack *stack_a, t_stack *stack_b, int argc);
t_stack		*cheapest_numer(t_stack *stack_a, int chunk, int argc);
int			first_index(t_stack *stack_a, int chunk, int argc);
int			second_index(t_stack *stack_a, int chunk, int argc);
t_stack		*checking_stack_b(t_stack *stack_b);
t_stack		*allocation(void);
int			back_to_a(t_stack *stack_a, t_stack *stack_b, int argc);
int			ft_atoi(const char *nptr);
long int	mod_atoi(const char *nptr);
void		first_round(t_stack *stack_a, t_stack *stack_b);
int			second_round(t_stack *stack_a, t_stack *stack_b);
int			third_round(t_stack *stack_a);
int			checking_input(char *argv);
int			algori_under500(t_stack *stack_a, t_stack *stack_b, int argc);
int			rearanging_stack_b(t_stack *stack_a, t_stack *stack_b, int argc);
int			where_biggest(t_stack *stack_b, int argc);
int			free_stack(t_stack *stacka);
void		help_for_first_round(t_stack **stack_a_fp, t_stack **stack_b_fp);

#endif
