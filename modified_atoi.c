/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modified_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:20:42 by codespace         #+#    #+#             */
/*   Updated: 2024/12/03 08:37:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	modified_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	if (nptr[i] == '-')
	{
		sign = sign * (-1);
		i++;
	}
	else if (nptr[i] == '+')
		i++;
    else if ((nptr[i] >= 1 && nptr[i] <= 42) || (nptr[i] == 44))
        return ('\0');
    else if ((nptr[i] >= 46 && nptr[i] <= 47) || (nptr[i] >= 58 && nptr[i] <= 127))
        return ('\0');
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return (result * sign);
}

/* int not_number(char *argv)
{
    int i;
    
    i = 0;
    if (modified_atoi != '\0')
        return (0);
    return (1);
} */
