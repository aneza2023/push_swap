/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:07:36 by ahavrank          #+#    #+#             */
/*   Updated: 2025/01/09 14:32:21 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_stack(t_stack *stacka)
{
	t_stack	*temp;

	while (stacka != NULL && stacka->prev != NULL)
		stacka = stacka->prev;
	while (stacka != NULL)
	{
		temp = stacka;
		stacka = stacka->nx;
		free(temp);
	}
	exit(1);
	return (0);
}
