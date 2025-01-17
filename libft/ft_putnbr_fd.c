/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:33:31 by oyuhi             #+#    #+#             */
/*   Updated: 2024/10/26 14:04:16 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*str_i;

	str_i = ft_itoa(n);
	if (!str_i)
		return ;
	write(fd, str_i, ft_strlen(str_i));
	free(str_i);
}
// #include <fcntl.h> // For open() and O_* constants
// #include <stdio.h> // For perror()
// #include <unistd.h> // For write() and close()

// // Helper function to test ft_putnbr_fd and print the result
// void	test_ft_putnbr_fd(int n, const char *filename)
// {
// 	int	fd;

// 	printf("Testing: %d\n", n);
// 	// Open the file in append mode so results don't overwrite each other
// 	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
// 	if (fd < 0)
// 	{
// 		perror("Failed to open file");
// 		return ;
// 	}
// 	// Write the integer to the file
// 	ft_putnbr_fd(n, fd);
// 	write(fd, "\n", 1); // Add a newline for clarity
// 	// Close the file descriptor
// 	close(fd);
// }

// int	main(void)
// {
// 	const char *filename = "output.txt"; // Use a single file for all tests

// 	// Test cases
// 	test_ft_putnbr_fd(0, filename);
// 	test_ft_putnbr_fd(42, filename);
// 	test_ft_putnbr_fd(-42, filename);
// 	test_ft_putnbr_fd(2147483647, filename);  // INT_MAX
// 	test_ft_putnbr_fd(-2147483648, filename); // INT_MIN

// 	printf("\nAll results written to %s\n", filename);
// 	return (0);
// }