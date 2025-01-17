/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:54:19 by oyuhi             #+#    #+#             */
/*   Updated: 2024/10/27 17:40:50 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// #include <fcntl.h> // For open() and the O_* constants
// #include <stdio.h> // For perror() (optional for error handling)
// #include <unistd.h> // For write() and close()

// int	main(void)
// {
// 	// Write a character to standard output (fd = 1)
// 	ft_putchar_fd('A', 1);

// 	// Open a file for writing
//  //(creates if it doesn't exist,truncates if it does)
// 	int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd < 0)
// 	{
// 		write(2, "Failed to open file\n", 20); // Error handling
// 		return (1);
// 	}

// 	// Write characters to the file
// 	ft_putchar_fd('B', fd);
// 	ft_putchar_fd('\n', fd); // Write a newline for clarity
// 	ft_putchar_fd('\n', fd); // Write a newline for clarity
// 	ft_putchar_fd('C', fd);  // Write a newline for clarity

// 	// Close the file descriptor
// 	close(fd);

// 	return (0);
// }