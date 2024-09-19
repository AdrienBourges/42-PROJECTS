#include "../includes/pipex.h"

void	create_pipes(int *pipes, int num_cmds)
{
	int	i;

	i = 0;
	while (i < num_cmds - 1)
	{
		if (pipe(pipes + 2 * i) == -1)
		{
			perror("Pipe creation failed");
			free(pipes);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	free_and_exit(int *pipes, char *str)
{
	perror(str);
	free(pipes);
	exit(EXIT_FAILURE);
}

void	exit_with_error(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

void	wait_for_children(int num_cmds)
{
	int	i;

	i = 0;
	while (i < num_cmds)
	{
		wait(NULL);
		i++;
	}
}

void	close_pipes(int *pipes, int num_cmds)
{
	int	i;

	i = 0;
	while (i < 2 * (num_cmds - 1))
	{
		close(pipes[i]);
		i++;
	}
}
