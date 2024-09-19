#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <sys/stat.h>

# define BUFFER_SIZE 1024

typedef struct s_pipe_data
{
	char	**argv;
	char	**envp;
	int		*pipes;
	int		num_cmds;
}	t_pipe_data;

char	*ft_strcpy(char *dst, const char *src);
char	*append_newline(char *str);
int		count_arguments(char *cmd);
char	*ft_strcat(char *dst, const char *src);
size_t	ft_strlen(const char *str);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	*check_command_path(char *c, char *p_start, char *p_end, char *c_path);
char	*get_path_env(char **envp);
char	*check_path_for_command(char *path, char *cmd);
char	**parse_command(char *cmd);
char	*move_to_next_path(char *path_end);
void	handle_here_doc(char *limiter, int pipefd[2]);
void	handle_here_doc_mode(char *argv[], char *envp[]);
void	exec_cmd_in_here_doc(char *av[], char *envp[], int outf, int pipefd[2]);
char	*find_in_paths(char *cmd, char *path_env);
char	*find_command(char *cmd, char **envp);
void	free_and_exit(int *pipes, char *str);
void	create_pipes(int *pipes, int num_cmds);
void	close_pipes(int *pipes, int num_cmds);
void	wait_for_children(int num_cmds);
void	exit_with_error(char *message);
void	execute_commands(t_pipe_data *data, int start);
void	execute_multiple_pipes(char *argv[], char *envp[], int start, int end);
void	handle_standard_mode(char *argv[], char *envp[], int argc);

#endif
