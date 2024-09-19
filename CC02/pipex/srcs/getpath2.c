#include "../includes/pipex.h"

char	*find_in_paths(char *cmd, char *path_env)
{
	char	*path_start;
	char	*path_end;
	char	*c_path;
	char	*full_cmd_path;
	int		path_len;

	path_start = path_env;
	while (*path_start)
	{
		path_end = ft_strchr(path_start, ':');
		if (!path_end)
			path_end = path_start + ft_strlen(path_start);
		path_len = path_end - path_start;
		c_path = malloc(path_len + 1);
		if (!c_path)
			return (NULL);
		full_cmd_path = check_command_path(cmd, path_start, path_end, c_path);
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
