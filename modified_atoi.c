/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modified_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:20:42 by codespace         #+#    #+#             */
/*   Updated: 2024/12/06 15:26:18 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	modified_atoi(const char *nptr)
{
	int	i;
	long int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((nptr[i] == 32) || (nptr[i] <= 13 && nptr[i] >= 9))
		i++;
	if (nptr[i] == '-')
	{
		sign = sign * (-1);
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return (result * sign);
}
