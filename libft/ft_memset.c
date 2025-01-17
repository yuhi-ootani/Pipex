/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:41:31 by oyuhi             #+#    #+#             */
/*   Updated: 2024/11/03 17:40:45 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// #include <stdio.h>
// #include <string.h>

/////// integer array version (1 byte = 255)
// int	main(void)
// {
// 	// 	////////////////////////////////////////
// 	//memcpy causes segmantation fault when passed NULL;
// 	// void*	result_std;
// 	// char	*s_NULL;
// 	// // char *dest_NULL = NULL;
// 	// s_NULL = NULL;
// 	// result_std = ft_memset(s_NULL, 'I', 5);
// 	// 	/////////////////////////////////////
// 	unsigned char	*byte_ptr;

// 	int arr[5]; // Create an integer array
// 	// Set all bytes in the array to 1 using ft_memset
// 	ft_memset(arr, 256, sizeof(arr));
// 	// Print the memory content as integers
// 	printf("Integer array content:\n");
// 	for (int i = 0; i < 5; i++)
// 	{
// 		printf("%d ", arr[i]);
// 	}
// 	printf("\n");
// 	// Print the raw memory (byte by byte) for clarity
// 	printf("Memory content (byte-by-byte):\n");
// 	byte_ptr = (unsigned char *)arr;
// 	for (size_t i = 0; i < sizeof(arr); i++)
// 	{
// 		printf("%02x ", byte_ptr[i]); // Print each byte in hexadecimal
// 	}
// 	printf("\n");
// 	return (0);
// }

/////////////////normal version//////////////////////////////
// int	main(void)
// {
// 	int	buffer[10];

// 	// Fill the buffer with '*'
// 	ft_memset(buffer, 1, sizeof(buffer));
// 	// Print the result
// 	for (int i = 0; i < 10; i++)
// 	{
// 		printf("%c ", buffer[i]);
// 	}
// 	return (0);
// }
