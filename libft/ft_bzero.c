/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:21:36 by oyuhi             #+#    #+#             */
/*   Updated: 2024/10/29 15:40:10 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

// // real bzero do segmentation fault;
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char buffer1[10];
// 	char buffer2[10];
// 	// char *buffer_NULL = NULL;

// 	// Initialize both buffers with non-zero values for testing
// 	memset(buffer1, 'A', sizeof(buffer1));
// 	memset(buffer2, 'A', sizeof(buffer2));

// 	// Use bzero and ft_bzero to set the buffers to zero
// 	bzero(buffer1, 5);    // Standard bzero
// 	ft_bzero(buffer2, 5); // Your implementation using ft_memset

// 	// Print results to check if they behave the same
// 	printf("Standard bzero result:\n");
// 	for (int i = 0; i < 10; i++)
// 	{
// 		printf("%d ", buffer1[i]); // Print bytes as integers
// 	}
// 	printf("\n");

// 	printf("ft_bzero result:\n");
// 	for (int i = 0; i < 10; i++)
// 	{
// 		printf("%d ", buffer2[i]); // Print bytes as integers
// 	}
// 	printf("\n");

// 	return (0);
// }