/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:52:36 by codespace         #+#    #+#             */
/*   Updated: 2024/11/04 15:07:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>

typedef struct node{
    int value;
    struct node *next;
} stack;

stack *inserting_arg(stack *stack_a, int arg);
stack *swap_in_stack(stack *stack_a);

#endif