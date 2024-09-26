


char	*ft_strdup(const char *s1)
{
	char				*temp;
	unsigned int		i;

	temp = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}


int main(int argc, char *argv[])
{
    char    *stacka[];
    char    *stackb[];
    int     i;

    i = 0;
    stacka = (int *)malloc(argc * sizeof(int));
    while (i <= argc){
        stacka[i] = argv[i];
    }
   
    
}

