/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:27:55 by oyuhi             #+#    #+#             */
/*   Updated: 2024/10/26 14:04:12 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

// #include <fcntl.h> // For open() and O_* constants
// #include <stdio.h> // For perror()
// #include <unistd.h> // For write() and close()

// // Helper function to test ft_putendl_fd and print the result
// void	test_ft_putendl_fd(char *str, const char *filename)
// {
// 	int	fd;

// 	printf("Testing: \"%s\"\n", str ? str : "NULL");
// 	// Write the string to standard output (fd = 1)
// 	ft_putendl_fd(str, 1);
// 	// Open a file for writing
// 	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd < 0)
// 	{
// 		perror("Failed to open file");
// 		return ;
// 	}
// 	// Write the string to the file
// 	ft_putendl_fd(str, fd);
// 	// Close the file descriptor
// 	close(fd);
// 	printf("Output written to %s\n\n", filename);
// }

// int	main(void)
// {
// 	// Test cases
// 	test_ft_putendl_fd("Hello, world!", "output.txt");
// 	test_ft_putendl_fd("42tokyo", "output.txt");
// 	test_ft_putendl_fd("", "output.txt");   // Edge case: empty string
// 	test_ft_putendl_fd(NULL, "output.txt"); // Edge case: NULL input
// 	return (0);
// }
