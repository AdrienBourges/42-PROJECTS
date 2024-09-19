#include "../includes/pipex.h"

void	handle_here_doc(char *limiter, int pipefd[2])
{
	char	buffer[BUFFER_SIZE];
	char	*new_limiter;
	ssize_t	read_bytes;

	new_limiter = append_newline(limiter);
	close(pipefd[0]);
	while (1)
	{
		write(STDOUT_FILENO, "> ", 2);
		read_bytes = read(STDIN_FILENO, buffer, BUFFER_SIZE - 1);
		if (read_bytes <= 0)
			break ;
		buffer[read_bytes] = '\0';
		if (ft_strcmp(buffer, new_limiter) == 0)
			break ;
		if (write(pipefd[1], buffer, ft_strlen(buffer)) == -1)
		{
			perror("Error writing to pipe");
			break ;
		}
	}
	close(pipefd[1]);
	free(new_limiter);
}

void	exec_cmd_in_here_doc(char *av[], char *envp[], int outf, int pipefd[2])
{
	char	**cmd;
	char	*cmd_path;

	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(outf, STDOUT_FILENO);
	close(pipefd[0]);
	close(outf);
	cmd = parse_command(av[4]);
	cmd_path = find_command(cmd[0], envp);
	if (!cmd_path)
		exit_with_error("Command not found for cmd2");
	execve(cmd_path, cmd, envp);
	exit_with_error("execve failed for cmd2");
}

void	handle_here_doc_mode(char *argv[], char *envp[])
{
	int		outfile;
	int		pipefd[2];
	pid_t	pid2;

	outfile = open(argv[5], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (outfile < 0)
		exit_with_error("Error opening outfile");
	if (pipe(pipefd) == -1)
		exit_with_error("Pipe creation failed");
	pid2 = fork();
	if (pid2 == 0)
		exec_cmd_in_here_doc(argv, envp, outfile, pipefd);
	handle_here_doc(argv[2], pipefd);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid2, NULL, 0);
}
