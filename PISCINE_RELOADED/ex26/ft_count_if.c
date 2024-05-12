int	ft_count_if(char **tab, int (*f)(char *))
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (*tab[i])
	{
		if (f(tab[i]) == 1)
			counter++;
		i++;
	}
	return (counter);
}
