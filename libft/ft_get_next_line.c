/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:47:57 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/12 09:21:53 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	split_by_newline(char **next_line, char *newline_pos,
		char **mega_buf)
{
	char	*tmp;
	size_t	len_line;

	if (!(*mega_buf))
		return ;
	tmp = NULL;
	if (newline_pos)
	{
		len_line = newline_pos - *mega_buf + 1;
		tmp = ft_substr_gnl(*mega_buf, len_line, ft_strlen_gnl(*mega_buf)
				- len_line);
		*next_line = ft_substr_gnl(*mega_buf, 0, len_line);
		if (tmp && !*next_line)
		{
			free(tmp);
			tmp = NULL;
		}
	}
	else if (**mega_buf)
		*next_line = ft_substr_gnl(*mega_buf, 0, ft_strlen_gnl(*mega_buf));
	free(*mega_buf);
	*mega_buf = tmp;
}

static void	read_till_newline(int fd, char **mega_buf)
{
	char	*buf;
	ssize_t	read_s;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return ;
	while (!*mega_buf || ft_strchr_gnl(*mega_buf, '\n') == NULL)
	{
		read_s = read(fd, buf, BUFFER_SIZE);
		if (read_s < 0 || (*mega_buf && ft_strlen_gnl(*mega_buf) > SIZE_MAX
				- read_s - 1))
		{
			free(*mega_buf);
			*mega_buf = NULL;
			break ;
		}
		if (read_s == 0)
			break ;
		buf[read_s] = '\0';
		*mega_buf = ft_strjoin_gnl(*mega_buf, buf);
		if (!*mega_buf)
			break ;
	}
	free(buf);
	buf = NULL;
}

char	*ft_get_next_line(int fd)
{
	static char	*mega_buf = NULL;
	char		*next_line;
	char		*newline_pos;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_till_newline(fd, &mega_buf);
	if (!mega_buf)
		return (NULL);
	next_line = NULL;
	newline_pos = ft_strchr_gnl(mega_buf, '\n');
	split_by_newline(&next_line, newline_pos, &mega_buf);
	return (next_line);
}

// #include "get_next_line.h" // Include your GNL header here
// #include <fcntl.h> // For open
// #include <stdio.h> // For printf, perror
// #include <stdlib.h> // For free
// #include <unistd.h> // For close

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*line;

// 	if (argc == 2)
// 	{
// 		// Open the provided file
// 		fd = open(argv[1], O_RDONLY);
// 		if (fd < 0)
// 		{
// 			perror("Error opening file");
// 			return (1);
// 		}
// 	}
// 	else
// 	{
// 		// No filename provided, use standard input
// 		fd = STDIN_FILENO;
// 	}
// 	// Read line by line until EOF or error
// 	while ((line = ft_get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	// Close the file if we opened one
// 	if (argc == 2)
// 		close(fd);
// 	return (0);
// }
