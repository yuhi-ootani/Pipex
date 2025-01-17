
#include "pipex.h"
#include <stdio.h>

char	*ft_get_paths(char **envp)
{
	char	**path;
	int		i;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
		{
			path = ft_split(envp[i], ':');
			return (envp[i]);
		}
		i++;
	}
	return (NULL);
}

char	*check_path(char *cmd, char **envp)
{
	char	**paths;
	char	*full_path;
	char	*tmp;
	int		i;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (cmd);
		ft_printf_error("");
		return (NULL);
	}
	paths = ft_get_paths(envp);
	if (!paths)
		ft_print_error("");
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (acces(full_path, F_OK | X_OK) == 0)
			return (full_path);
		i++;
	}
	ft_printf_error("");
	return (NULL);
}

void	child2_excute(char **argv, char **envp, int *pipe_fd)
{
	int		outfile_fd;
	char	**cmd;
	char	*path;

	close(pipe_fd[1]);
	outfile_fd = open(argv[4], O_RDONLY);
	if (outfile_fd == -1)
	{
		close(pipe_fd[1]);
		ft_printf_error("");
	}
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1 && close(pipe_fd[0]))
		ft_print_error("");
	if (dup2(outfile_fd, STDOUT_FILENO) == -1 && close(outfile_fd))
		ft_print_error("");
	cmd = ft_split(argv[3], ' ');
	path = check_path(cmd[0], envp);
	execve(path, cmd, envp);
	ft_print_error("");
	return (ft_free(cmd), free(path), path = NULL, NULL);
}

void	child1_excute(char **argv, char **envp, int *pipe_fd)
{
	int		infile_fd;
	char	**cmd;
	char	*path;

	close(pipe_fd[0]);
	infile_fd = open(argv[1], O_RDONLY);
	if (infile_fd == -1)
	{
		close(pipe_fd[1]);
		ft_printf_error("");
	}
	if (dup2(infile_fd, STDIN_FILENO) == -1 && close(infile_fd))
		ft_print_error("");
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1 && close(pipe_fd[1]))
		ft_print_error("");
	cmd = ft_split(argv[2], ' ');
	path = check_path(cmd[0], envp);
	execve(path, cmd, envp);
	ft_print_error("");
	return (ft_free(cmd), free(path), path = NULL, NULL);
}

void	pipex(char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	child1_id;
	pid_t	child2_id;

	if (pipe(pipe_fd) == -1)
		ft_print_error("");
	child1_id = fork();
	if (child1_id == -1)
		ft_print_error("");
	else if (child1_id == 0)
		child1_excute(argv, envp, pipe_fd);
	child2_id = fork();
	if (child2_id == -1)
		ft_print_error("");
	else if (child2_id == 0)
		child2_excute();
	close();
	close();
	waitpid();
	waitpid();
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	if (!envp)
		ft_error("Error empty enviroment");
	if (argc != 5)
		ft_print_error("Usage: ./pipex infile cmd1 cmd2 outfile");
	pipex(, argv, envp);
	return (0);
}
