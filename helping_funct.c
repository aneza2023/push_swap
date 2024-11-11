#include "push_swap.h"

int	not_number(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0'){
		if (ft_isalpha(argv[i]) == 1)
			return (1); 
		i++;
	}
	return (0);
} 

int	ft_isalpha(int c)
{
	if ((c >= 1 && c <= 44) || (c >= 46 && c <= 47) || (c >= 58 && c <= 127))
	{
		return (1);
	}
	return (0);
}