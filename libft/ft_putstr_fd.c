/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:08:51 by oyuhi             #+#    #+#             */
/*   Updated: 2024/10/26 14:04:21 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

// #include <fcntl.h> // For open() and O_* constants
// #include <stdio.h> // For perror()
// #include <unistd.h> // For write() and close()

// // Helper function to print a string to both stdout and a file
// void	test_ft_putstr_fd(char *str, const char *filename)
// {
// 	int	fd;

// 	printf("Testing: \"%s\"\n", str ? str : "NULL");
// 	// Write the string to standard output (fd = 1)
// 	ft_putstr_fd(str, 1);
// 	write(1, "\n", 1); // Add a newline for clarity
// 	// Open a file for writing
// 	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd < 0)
// 	{
// 		perror("Failed to open file");
// 		return ;
// 	}
// 	// Write the string to the file
// 	ft_putstr_fd(str, fd);
// 	// Close the file descriptor
// 	close(fd);
// 	printf("Output written to %s\n\n", filename);
// }

// int	main(void)
// {
// 	// Test cases
// 	test_ft_putstr_fd("Hello, world!", "output.txt");
// 	// test_ft_putstr_fd("42tokyo", "output.txt");
// 	// test_ft_putstr_fd("", "output.txt"); // Edge case: empty string
// 	// test_ft_putstr_fd(NULL, "output.txt"); // Edge case: NULL input

// 	return (0);
// }