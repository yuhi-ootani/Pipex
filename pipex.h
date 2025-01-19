/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:51:54 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/19 19:35:57 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_fd
{
	int	infile;
	int	outfile;
	int	pipes[2];
}		t_fd;

// pipex
void	child2_execute(char **argv, char **envp, t_fd *fds);
void	child1_execute(char **argv, char **envp, t_fd *fds);
void	close_files_wait_children(int child1_id, int child2_id, t_fd *fds);
void	pipex(char **argv, char **envp, t_fd *fds);

// pipex_helper
int		ft_strcmp(const char *s1, const char *s2);
void	error_exit(char *prefix, char *argv, char *message, int exit_flag);
char	**get_paths(char **envp);
char	*check_path(char *cmd, char **paths);

#endif