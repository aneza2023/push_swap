#include <stdlib.h>
#include <stdio.h>


/* int	ft_atoi(char *nptr)
{
	int	i;
	int	result;
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

int main(int argc, char *argv[])
{
    int     *stacka;
    int     *stackb;
    int     *alloc_stack;
    int     i;

    i = 0;
    stacka = (int *)malloc(argc * sizeof(int));
    stackb = (int *)malloc(argc * sizeof(int));
    if (stacka == NULL || stackb == NULL )
        return (1);
    while (i <= argc){
        stacka[i] = ft_atoi(argv[i]);
 //       stacka[i] = argv[i];
        i++;
    }
    i = 0;
    while (i < argc){
        printf("%d\n", stacka[i]);
        i++;
    }
    return (0);
} */

