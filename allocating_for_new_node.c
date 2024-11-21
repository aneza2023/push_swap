/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocating_for_new_node.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:45:33 by ahavrank          #+#    #+#             */
/*   Updated: 2024/11/21 15:12:46 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack	*allocation(stack *new_node)
{
	new_node = (stack *)malloc(sizeof(stack));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	return (new_node);
}
