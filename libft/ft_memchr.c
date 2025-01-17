/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:22:01 by oyuhi             #+#    #+#             */
/*   Updated: 2024/10/29 15:48:06 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h> // For the standard memchr

// void	test_ft_memchr(const void *s, int c, size_t n)
// {
// 	void	*result_std;
// 	void	*result_ft;

// 	result_std = memchr(s, c, n);
// 	result_ft = ft_memchr(s, c, n);
// 	printf("Standard memchr: %s\n", result_std ? (char *)result_std : "NULL");
// 	printf("Searching for '%c' (ASCII: %d) in \"%s\" (first %zu bytes):\n",
// 		(char)c, c, (const char *)s, n);
// 	printf("Your ft_memchr:  %s\n", result_ft ? (char *)result_ft : "NULL");
// 	if (result_std == result_ft)
// 	{
// 		printf("✅ Test Passed!\n");
// 	}
// 	else
// 	{
// 		printf("❌ Test Failed!\n");
// 	}
// 	printf("-------------------------------\n");
// }

// int	main(void)
// {
// 	// memechr does segmantation fault when NULL is passed.
// 	// char	*s_NULL;
// 	// void	*s;
// 	// s_NULL = NULL;
// 	// s = memchr(s_NULL, 'S', 1);
// 	// Test cases to ensure your ft_memchr matches the standard memchr
// 	test_ft_memchr("Hello, World!", 'W', 13);  // Found case
// 	test_ft_memchr("Hello, World!", 'z', 13);  // Not found
// 	test_ft_memchr("Hello, World!", '\0', 13); // Null terminator
// 	test_ft_memchr("abc\0def", 'd', 7);        // After null byte
// 	test_ft_memchr("Hello", 'o', 4);           // Boundary test
// 	return (0);
// }
