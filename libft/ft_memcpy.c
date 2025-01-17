/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:07:31 by oyuhi             #+#    #+#             */
/*   Updated: 2024/11/04 10:43:17 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;
	size_t				i;

	ptr_dest = dest;
	ptr_src = src;
	i = 0;
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// // Prototype for your ft_memcpy
// void	*ft_memcpy(void *dest, const void *src, size_t n);

// int	main(void)
// {
// 	// memcpy causes segmantation fault when passed NULL;
// 	// void*	result_std;
// 	// char	*s_NULL;
// 	// char *dest_NULL = NULL;
// 	// s_NULL = NULL;
// 	// result_std = memcpy(dest_NULL, "HELLO", 5);
// 	///////////////////////////////////
// 	char	dest1[20];
// 	char	src1[20] = "Hello, World!";
// 	char	src2[20] = "Goodbye!";
// 	char	dest2[20] = "Test";
// 	char	buffer[10] = "123456789";

// 	// Test Case 1: Regular Copy
// 	ft_memcpy(dest1, src1, strlen(src1) + 1);
// 	printf("Test 1 - ft_memcpy: %s\n", dest1);
// 	// Test Case 2: Copy Zero Bytes
// 	ft_memcpy(dest2, src2, 8); // Should not change dest2
// 	printf("Test 2 - ft_memcpy: %s\n", dest2);
// 	// Test Case 3: Overlapping Memory (undefined behavior)
// 	// This will give undefined behavior, same as memcpy
// 	ft_memcpy(buffer + 2, buffer, 5);
// 	printf("Test 3 - Overlapping: %s\n", buffer);
// 	return (0);
// }
