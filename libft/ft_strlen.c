/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:37:29 by oyuhi             #+#    #+#             */
/*   Updated: 2024/10/29 16:36:42 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

// #include <stdio.h>
// #include <string.h> // For the real strlen

// // Prototype for your custom ft_strlen
// size_t	ft_strlen(const char *str);

// void	test_ft_strlen(const char *str)
// {
// 	size_t	real_result;
// 	size_t	ft_result;

// 	real_result = strlen(str);
// 	ft_result = ft_strlen(str);
// 	// Print the results of both functions
// 	printf("String: \"%s\"\n", str);
// 	printf("strlen:    %zu\n", real_result);
// 	printf("ft_strlen: %zu\n", ft_result);
// 	// Compare the results
// 	if (real_result == ft_result)
// 	{
// 		printf("Test passed ✅\n");
// 	}
// 	else
// 	{
// 		printf("Test failed ❌\n");
// 	}
// 	printf("-------------------------------\n");
// }

// int	main(void)
// {
// 	size_t	result_std;
// 	char	*s_NULL;

// 	// 	// 	// 	////////////////////////////////////////
// 	// 	//memcpy causes segmantation fault when passed NULL;
// 	// char *dest_NULL = NULL;
// 	s_NULL = NULL;
// 	result_std = ft_strlen(s_NULL);
// 	// // 	// 	/////////////////////////////////////
// 	// Test cases with various strings
// 	test_ft_strlen("");                 // Empty string
// 	test_ft_strlen("Hello");            // Normal string
// 	test_ft_strlen("Hello, World!");    // Longer string
// 	test_ft_strlen(" ");                // Single space
// 	test_ft_strlen("42");               // Numbers as characters
// 	test_ft_strlen("\0hidden");         // Null character at the start
// 	test_ft_strlen("null\0terminated"); // Null character in the middle
// 	return (0);
// }
