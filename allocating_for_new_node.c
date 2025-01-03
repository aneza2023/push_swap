/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocating_for_new_node.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naomi <naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:45:33 by ahavrank          #+#    #+#             */
/*   Updated: 2024/12/21 11:16:53 by naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack	*allocation()
{
	stack	*new_node;
	
	new_node = (stack *)malloc(sizeof(stack));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	return (new_node);
}
