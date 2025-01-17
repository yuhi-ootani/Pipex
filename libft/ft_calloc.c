/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:32:13 by oyuhi             #+#    #+#             */
/*   Updated: 2024/11/04 18:33:49 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	result = malloc(nmemb * size);
	if (!result)
		return (NULL);
	ft_memset(result, 0, nmemb * size);
	return (result);
}

// #include <stdio.h>
// #include <stdlib.h> // For calloc
// #include <string.h> // For memcmp

// // Function to test ft_calloc vs. calloc
// void	test_calloc(size_t num_elements, size_t element_size)
// {
// 	void	*real_alloc;
// 	void	*ft_alloc;

// 	// Allocate memory using calloc and ft_calloc
// 	real_alloc = calloc(num_elements, element_size);
// 	ft_alloc = ft_calloc(num_elements, element_size);
// 	// Check if both allocations are identical
// 	if (real_alloc == NULL || ft_alloc == NULL)
// 	{
// 		printf("Memory allocation failed!\n");
// 	}
// 	else if (memcmp(real_alloc, ft_alloc, num_elements * element_size) == 0)
// 	{
// 		printf("✅ Test Passed! Allocations are identical.\n");
// 	}
// 	else
// 	{
// 		printf("❌ Test Failed! Allocations differ.\n");
// 	}
// 	// Free the allocated memory
// 	free(real_alloc);
// 	free(ft_alloc);
// }

// int	main(void)
// {
// 	// Test cases to compare calloc with ft_calloc
// 	test_calloc(5, sizeof(int));    // Small array of integers
// 	test_calloc(10, sizeof(char));  // Array of chars (strings)
// 	test_calloc(1, sizeof(double)); // Single double allocation
// 	test_calloc(0, sizeof(int));    // Zero elements
// 	test_calloc(100, sizeof(char)); // Large array of chars
// 	return (0);
// }
