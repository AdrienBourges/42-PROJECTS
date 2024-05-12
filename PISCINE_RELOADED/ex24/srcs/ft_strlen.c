int	ft_strlen(char *str)
{
	int	result;

	result = 0;
	while (str[result])
		result++;
	return (result);
}
