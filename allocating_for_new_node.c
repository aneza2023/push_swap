/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocating_for_new_node.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naomi <naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:45:33 by ahavrank          #+#    #+#             */
/*   Updated: 2024/12/30 23:31:43 by naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack	*allocation()
{
	stack	*new_node;
	
	new_node = (stack *)malloc(sizeof(stack));
	if (new_node == NULL)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	return (new_node);
}
