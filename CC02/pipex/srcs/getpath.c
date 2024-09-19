#include "../includes/pipex.h"

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

char	*check_command_path(char *cmd, char *p_start, char *p_end, char *c_path)
{
	char	*f_cmd_path;
	int		p_len;

	p_len = p_end - p_start;
	ft_strncpy(c_path, p_start, p_len);
	c_path[p_len] = '\0';
	f_cmd_path = check_path_for_command(c_path, cmd);
	free(c_path);
	return (f_cmd_path);
}

char	*move_to_next_path(char *path_end)
{
	if (*path_end == ':')
		return (path_end + 1);
	return (path_end);
}
