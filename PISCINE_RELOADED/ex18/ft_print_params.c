void	ft_putchar(char c);

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc >= 1)
	{
		i = 1;
		while (argv[i])
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				ft_putchar(argv[i][j]);
				j++;
			}
			i++;
			ft_putchar('\n');
		}
	}
	return (0);
}
