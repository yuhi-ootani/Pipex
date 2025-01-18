
#include "libft/libft.h"
#include "pipex.h"
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

typedef struct s_fd
{
	int	infile;
	int	outfile;
	int	pipes[2];
}		t_fd;

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	error_exit(char *message)
{
	int	i;

	i = 0;
	write(2, "pipex: ", 7);
	while (message[i])
	{
		write(2, &message[i], 1);
		i++;
	}
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

int	print_error(const char *prefix, const char *argv, const char *message)
{
	if (prefix && *prefix)
	{
		write(2, prefix, ft_strlen(prefix));
		write(2, ": ", 2);
	}
	if (argv && *argv)
	{
		write(2, argv, ft_strlen(argv));
		write(2, ": ", 2);
	}
	if (message && *message)
	{
		write(2, message, ft_strlen(message));
	}
	write(2, "\n", 1);
	return (1);
}

char	**ft_get_paths(char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	paths = NULL;
	while (envp[i])
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
		{
			paths = ft_split(envp[i] + 5, ':');
			return (paths);
		}
		i++;
	}
	return (NULL);
}

char	*check_path(char *cmd, char **paths)
{
	char	*full_path;
	char	*tmp;
	int		i;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (cmd);
		error_exit("");
	}
	i = 0;
	while (paths && paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(full_path, F_OK | X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	error_exit("");
	return (NULL);
}

void	child2_execute(char **argv, char **envp, char **paths, t_fd *fds)
{
	char	**cmd;
	char	*path;

	close(fds->pipes[1]);
	close(fds->infile);
	if (dup2(fds->pipes[0], STDIN_FILENO) == -1 || close(fds->pipes[0]) == -1)
		error_exit("");
	if (dup2(fds->outfile, STDOUT_FILENO) == -1 || close(fds->outfile) == -1)
		error_exit("");
	cmd = ft_split(argv[3], ' ');
	path = check_path(cmd[0], paths);
	execve(path, cmd, envp);
	if (path && ft_strcmp(cmd[0], path) != 0)
		free(path);
	ft_array_free(cmd);
	ft_array_free(paths);
	error_exit("");
}

void	child1_execute(char **argv, char **envp, char **paths, t_fd *fds)
{
	char	**cmd;
	char	*path;

	close(fds->pipes[0]);
	close(fds->outfile);
	if (dup2(fds->infile, STDIN_FILENO) == -1 || close(fds->infile) == -1)
		error_exit("");
	if (dup2(fds->pipes[1], STDOUT_FILENO) == -1 || close(fds->pipes[1]) == -1)
		error_exit("");
	cmd = ft_split(argv[2], ' ');
	path = check_path(cmd[0], paths);
	execve(path, cmd, envp);
	if (path && ft_strcmp(cmd[0], path) != 0)
		free(path);
	ft_array_free(cmd);
	ft_array_free(paths);
	error_exit("");
}

void	pipex(char **argv, char **envp, char **paths, t_fd *fds)
{
	int		status;
	pid_t	child1_id;
	pid_t	child2_id;

	if (pipe(fds->pipes) == -1)
		error_exit("");
	child1_id = fork();
	if (child1_id == -1)
		error_exit("");
	else if (child1_id == 0)
		child1_execute(argv, envp, paths, fds);
	child2_id = fork();
	if (child2_id == -1)
		error_exit("");
	else if (child2_id == 0)
		child2_execute(argv, envp, paths, fds);
	close(fds->infile);
	close(fds->outfile);
	close(fds->pipes[0]);
	close(fds->pipes[1]);
	waitpid(child1_id, &status, 0);
	waitpid(child2_id, &status, 0);
	ft_array_free(paths);
}

void	check_file(char **argv, t_fd *fds)
{
	int	error_flag;

	fds->infile = open(argv[1], O_RDONLY);
	if (fds->infile == -1)
		error_flag = print_error("pipex", argv[1], strerror(errno));
	fds->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fds->outfile == -1)
		error_flag = print_error("pipex", argv[4], strerror(errno));
	if (error_flag)
	{
		if (fds->infile != -1)
			close(fds->infile);
		if (fds->outfile != -1)
			close(fds->outfile);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	t_fd	fds;

	if (!envp)
		error_exit("Error empty enviroment");
	if (argc != 5)
		error_exit("Usage: ./pipex infile cmd1 cmd2 outfile");
	paths = ft_get_paths(envp);
	if (!paths)
		error_exit("");
	check_file(argv, &fds);
	pipex(argv, envp, paths, &fds);
	return (0);
}
