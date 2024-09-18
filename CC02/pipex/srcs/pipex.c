#include "../includes/pipex.h"

int	count_arguments(char *cmd)
{
	int	count;

	count = 0;
	while (*cmd)
	{
		while (*cmd == ' ')
			cmd++;
		if (*cmd != '\0')
		{
			count++;
			while (*cmd && *cmd != ' ')
				cmd++;
		}
	}
	return (count);
}

char	**parse_command(char *cmd)
{
	int		arg_count;
	char	**args;
	int		i;

	arg_count = count_arguments(cmd);
	args = malloc((arg_count + 1) * sizeof(char *));
	i = 0;
	while (*cmd)
	{
		while (*cmd == ' ')
			cmd++;
		if (*cmd != '\0')
		{
			args[i++] = cmd;
			while (*cmd && *cmd != ' ')
				cmd++;
			if (*cmd)
				*cmd++ = '\0';
		}
	}
	args[i] = NULL;
	return (args);
}
char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcat(char *dst, const char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dst[i])
		i++;
	j = 0;
	while (src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*check_path_for_command(char *path, char *cmd)
{
	char	*full_path;

	full_path = malloc(ft_strlen(path) + ft_strlen(cmd) + 2);
	if (!full_path)
		return (NULL);
	ft_strcpy(full_path, path);
	ft_strcat(full_path, "/");
	ft_strcat(full_path, cmd);
	if (access(full_path, X_OK) == 0)
		return (full_path);
	free(full_path);
	return (NULL);
}

char	*append_newline(char *str)
{
	size_t	len;
	char	*new_str;

	len = ft_strlen(str);
	new_str = malloc(len + 2);
	if (!new_str)
	{
		perror("Memory allocation failed");
		return (NULL);
	}
	ft_strcpy(new_str, str);
	new_str[len] = '\n';
	new_str[len + 1] = '\0';
	return (new_str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

char	*get_path_env(char **envp)
{
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

char	*check_command_path(char *cmd, char *path_start, char *path_end, char *current_path)
{
	char	*full_cmd_path;
	int		path_len;

	path_len = path_end - path_start;
	ft_strncpy(current_path, path_start, path_len);
	current_path[path_len] = '\0';
	full_cmd_path = check_path_for_command(current_path, cmd);
	free(current_path);
	return (full_cmd_path);
}

char	*move_to_next_path(char *path_end)
{
	if (*path_end == ':')
		return (path_end + 1);
	return (path_end);
}

char	*find_in_paths(char *cmd, char *path_env)
{
	char	*path_start;
	char	*path_end;
	char	*current_path;
	char	*full_cmd_path;
	int		path_len;

	path_start = path_env;
	while (*path_start)
	{
		path_end = ft_strchr(path_start, ':');
		if (!path_end)
			path_end = path_start + ft_strlen(path_start);
		path_len = path_end - path_start;
		current_path = malloc(path_len + 1);
		if (!current_path)
			return (NULL);
		full_cmd_path = check_command_path(cmd, path_start, path_end, current_path);
		if (full_cmd_path)
			return (full_cmd_path);
		path_start = move_to_next_path(path_end);
	}
	return (NULL);
}

char	*find_command(char *cmd, char **envp)
{
	char	*path_env;
	char	*full_cmd_path;

	path_env = get_path_env(envp);
	if (!path_env)
		return (NULL);
	full_cmd_path = find_in_paths(cmd, path_env);
	return (full_cmd_path);
}


int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	handle_here_doc(char *limiter, int pipefd[2])
{
	char	buffer[BUFFER_SIZE];
	char	*new_limiter;
	ssize_t read_bytes;

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

void	free_and_exit(int *pipes, char *str)
{
	perror(str);
	free(pipes);
	exit(EXIT_FAILURE);
}

void	execute_commands(char *argv[], char *envp[], int start, int num_cmds, int *pipes)
{
	int		pid;
	int		i;
	char	**cmd;
	char	*cmd_path;

	i = 0;
	while (i < num_cmds)
	{
		pid = fork();
		if (pid == 0)
		{
			setup_pipes(i, pipes, num_cmds);
			cmd = parse_command(argv[start + i]);
			cmd_path = find_command(cmd[0], envp);
			if (!cmd_path)
				free_and_exit(pipes, "Command not found");
			execve(cmd_path, cmd, envp);
			free_and_exit(pipes, "execve failed");
		}
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

void	execute_multiple_pipes(char *argv[], char *envp[], int start, int end)
{
	int		*pipes;
	int		num_cmds;

	num_cmds = end - start;
	pipes = malloc(sizeof(int) * 2 * (num_cmds - 1));
	if (!pipes)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	create_pipes(pipes, num_cmds);
	execute_commands(argv, envp, start, num_cmds, pipes);
	close_pipes(pipes, num_cmds);
	wait_for_children(num_cmds);
	free(pipes);
}

void	exit_with_error(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

void	exec_cmd_in_here_doc(char *argv[], char *envp[], int outfile, int pipefd[2])
{
	char	**cmd;
	char	*cmd_path;

	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(pipefd[0]);
	close(outfile);
	cmd = parse_command(argv[4]);
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

