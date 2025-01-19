/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:34:17 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/19 19:32:44 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child2_execute(char **argv, char **envp, t_fd *fds)
{
	char	**cmd;
	char	**paths;
	char	*cmd_path;

	close(fds->pipes[1]);
	if (fds->infile != -1)
		close(fds->infile);
	if (dup2(fds->pipes[0], STDIN_FILENO) == -1 || close(fds->pipes[0]) == -1)
		error_exit("pipex", "dup2/close", strerror(errno), 1);
	if (dup2(fds->outfile, STDOUT_FILENO) == -1 || close(fds->outfile) == -1)
		error_exit("pipex", "dup2/close", strerror(errno), 1);
	paths = get_paths(envp);
	if (!paths)
		error_exit("pipex", argv[3], "No such file or directory", 1);
	cmd = ft_split(argv[3], ' ');
	cmd_path = check_path(cmd[0], paths);
	if (cmd_path)
		execve(cmd_path, cmd, envp);
	if (cmd_path && ft_strcmp(cmd[0], cmd_path) != 0)
		free(cmd_path);
	ft_array_free(cmd);
	ft_array_free(paths);
	exit(EXIT_FAILURE);
}

// each cmd needs a stdin (input) and returns an output (to stdout)
//  dup2 makes infile                                   dup2 makes outfile
// as stdin for cmd1                                 as stdout for cmd2
//        |                        PIPE                        ↑
//        |           |---------------------------|            |
//        ↓             |                       |              |
//       cmd1   -->   pipes[1]      ↔      pipes[0]   -->     cmd2
//                      |                       |
//             cmd1   |---------------------------|  pipes[0]
//            output                             reads pipes[1]
//          is written                          and spipess cmd1
//           to pipes[1]                          output to cmd2
//     dup2(pipes[1] becomes                   dup2(pipes[0] becomes
//         cmd1 stdout)                           cmd2 stdin)

void	child1_execute(char **argv, char **envp, t_fd *fds)
{
	char	**cmd;
	char	**paths;
	char	*cmd_path;

	close(fds->pipes[0]);
	if (fds->outfile != -1)
		close(fds->outfile);
	if (dup2(fds->infile, STDIN_FILENO) == -1 || close(fds->infile) == -1)
		error_exit("pipex", "dup2/close", strerror(errno), 1);
	if (dup2(fds->pipes[1], STDOUT_FILENO) == -1 || close(fds->pipes[1]) == -1)
		error_exit("pipex", "dup2/close", strerror(errno), 1);
	paths = get_paths(envp);
	if (!paths)
		error_exit("pipex", argv[2], "No such file or directory", 1);
	cmd = ft_split(argv[2], ' ');
	cmd_path = check_path(cmd[0], paths);
	if (cmd_path)
		execve(cmd_path, cmd, envp);
	if (cmd_path && ft_strcmp(cmd[0], cmd_path) != 0)
		free(cmd_path);
	ft_array_free(cmd);
	ft_array_free(paths);
	exit(EXIT_FAILURE);
}

// STATUS //
// The status variable is used to capture and
// interpret the exit information of child processes via waitpid.
// @param fds infd + outfd
void	close_files_wait_children(int child1_id, int child2_id, t_fd *fds)
{
	int	status;

	if (fds->infile != -1)
		close(fds->infile);
	if (fds->outfile != -1)
		close(fds->outfile);
	close(fds->pipes[0]);
	close(fds->pipes[1]);
	if (child1_id != -1)
		waitpid(child1_id, &status, 0);
	if (child2_id != -1)
		waitpid(child2_id, &status, 0);
}

/**
 *
 *  fork ///
				[Parent Process]
				|             |
   [Child Process 1]      [Child Process 2]
			|                       |
			|                       |
	(child1_execute)      (child2_execute)
 */
void	pipex(char **argv, char **envp, t_fd *fds)
{
	pid_t	child1_id;
	pid_t	child2_id;

	child1_id = -1;
	child2_id = -1;
	if (pipe(fds->pipes) == -1)
		error_exit("pipex", "pipe", strerror(errno), 1);
	if (fds->infile != -1)
	{
		child1_id = fork();
		if (child1_id == -1)
			error_exit("pipex", "fork", strerror(errno), 1);
		else if (child1_id == 0)
			child1_execute(argv, envp, fds);
	}
	if (fds->outfile != -1)
	{
		child2_id = fork();
		if (child2_id == -1)
			error_exit("pipex", "fork", strerror(errno), 1);
		else if (child2_id == 0)
			child2_execute(argv, envp, fds);
	}
	close_files_wait_children(child1_id, child2_id, fds);
}
// strerror(errno) is a C function that translates the error code stored
// in the global variable errno into a human-readable string.

int	main(int argc, char **argv, char **envp)
{
	t_fd	fds;

	if (!envp)
		error_exit("pipex", NULL, "environment is empty", 1);
	if (argc != 5)
		error_exit("pipex", argv[0], "Usage: ./pipex infile cmd1 cmd2 outfile",
			1);
	fds.infile = open(argv[1], O_RDONLY);
	if (fds.infile == -1)
		error_exit("pipex", argv[1], strerror(errno), 0);
	fds.outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fds.outfile == -1)
		error_exit("pipex", argv[4], strerror(errno), 0);
	pipex(argv, envp, &fds);
	return (0);
}
