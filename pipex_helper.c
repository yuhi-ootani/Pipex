/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:22:48 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/19 19:32:39 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

/*
 * error_exit(prefix, argv, message, exit_flag)
 * If prefix is set, prints "prefix: "
 * If argv is set, prints "argv: "
 * Then prints message, and a newline.
 * If exit_flag is 1, calls exit(EXIT_FAILURE).
 */
void	error_exit(char *prefix, char *argv, char *message, int exit_flag)
{
	int	i;

	if (prefix && *prefix)
	{
		write(2, prefix, ft_strlen(prefix));
		write(2, ": ", 2);
	}
	if (argv && *argv && *argv != ' ')
	{
		i = 0;
		while (argv[i] && argv[i] != ' ')
			i++;
		write(2, argv, i);
		write(2, ": ", 2);
	}
	if (message && *message)
	{
		write(2, message, ft_strlen(message));
	}
	write(2, "\n", 1);
	if (exit_flag)
		exit(EXIT_FAILURE);
}

char	**get_paths(char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	paths = NULL;
	while (envp && envp[i])
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

/// PATHS ///
// PATH=
// /home/oyuhi/bin:
// /home/oyuhi/bin:
// /usr/local/sbin:
// /usr/local/bin:
// /usr/sbin:
// /usr/bin:
// /sbin:
// /bin:
// /usr/games:
// /usr/local/games:
// /snap/bin

/// access ///
// to check a file exists and
// whether you have the required permissions to access it in a certain way.
char	*check_path(char *cmd, char **paths)
{
	char	*full_path;
	char	*tmp;
	int		i;

	if (!cmd || !(*cmd))
		return (NULL);
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (cmd);
		error_exit("pipex", cmd, strerror(errno), 0);
		return (NULL);
	}
	i = -1;
	while (paths && paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(full_path, F_OK | X_OK) == 0)
			return (full_path);
		free(full_path);
	}
	error_exit(NULL, cmd, "command not found", 0);
	return (NULL);
}
