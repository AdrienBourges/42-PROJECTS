#include "../includes/pipex.h"

void	setup_pipes(int i, int *pipes, int num_cmds)
{
	int	j;

	if (i != 0)
		dup2(pipes[(i - 1) * 2], STDIN_FILENO);
	if (i != num_cmds - 1)
		dup2(pipes[i * 2 + 1], STDOUT_FILENO);
	j = 0;
	while (j < 2 * (num_cmds - 1))
		close(pipes[j++]);
}

void	execute_commands(t_pipe_data *data, int start)
{
	int		pid;
	int		i;
	char	**cmd;
	char	*cmd_path;

	i = 0;
	while (i < data->num_cmds)
	{
		pid = fork();
		if (pid == 0)
		{
			setup_pipes(i, data->pipes, data->num_cmds);
			cmd = parse_command(data->argv[start + i]);
			cmd_path = find_command(cmd[0], data->envp);
			if (!cmd_path)
				free_and_exit(data->pipes, "Command not found");
			execve(cmd_path, cmd, data->envp);
			free_and_exit(data->pipes, "execve failed");
		}
		i++;
	}
}

void	execute_multiple_pipes(char *argv[], char *envp[], int start, int end)
{
	t_pipe_data	data;
	int			*pipes;
	int			num_cmds;

	num_cmds = end - start;
	pipes = malloc(sizeof(int) * 2 * (num_cmds - 1));
	if (!pipes)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	create_pipes(pipes, num_cmds);
	data.argv = argv;
	data.envp = envp;
	data.pipes = pipes;
	data.num_cmds = num_cmds;
	execute_commands(&data, start);
	close_pipes(pipes, num_cmds);
	wait_for_children(num_cmds);
	free(pipes);
}

void	handle_standard_mode(char *argv[], char *envp[], int argc)
{
	int		infile;
	int		outfile;

	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (infile < 0 || outfile < 0)
		exit_with_error("Error opening infile/outfile");
	dup2(infile, STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	execute_multiple_pipes(argv, envp, 2, argc - 1);
	close(infile);
	close(outfile);
}

int	main(int argc, char *argv[], char *envp[])
{
	if (argc < 5)
	{
		write(STDERR_FILENO, "Usage: ./pipex infile cmd1 cmd2 outfile\n", 40);
		exit(EXIT_FAILURE);
	}
	if (ft_strcmp(argv[1], "here_doc") == 0 && argc == 6)
		handle_here_doc_mode(argv, envp);
	else
		handle_standard_mode(argv, envp, argc);
	return (0);
}
