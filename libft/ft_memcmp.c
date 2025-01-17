/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:38:45 by oyuhi             #+#    #+#             */
/*   Updated: 2024/11/03 17:41:35 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*ptr_s1;
	const unsigned char	*ptr_s2;

	i = 0;
	ptr_s1 = s1;
	ptr_s2 = s2;
	while (i < n && ptr_s1[i] == ptr_s2[i])
	{
		i++;
	}
	if (i == n)
		return (0);
	return ((int)(ptr_s1[i] - ptr_s2[i]));
}

// #include <stdio.h>
// #include <string.h> // For the standard memcmp

// int		ft_memcmp(const void *s1, const void *s2, size_t n);

// void	test_ft_memcmp(const void *s1, const void *s2, size_t n)
// {
// 	int	result_std;
// 	int	result_ft;

// 	result_std = memcmp(s1, s2, n);
// 	result_ft = ft_memcmp(s1, s2, n);
// 	printf("Comparing \"%s\" and \"%s\" for %zu bytes:\n", (const char *)s1,
// 		(const char *)s2, n);
// 	printf("Standard memcmp: %d\n", result_std);
// 	printf("Your ft_memcmp:  %d\n", result_ft);
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
// 	//memcmp causes segmantation fault when passed NULL;
// 	// int		result_std;
// 	// char	*s_NULL;

// 	// s_NULL = NULL;
// 	// result_std = memcmp("HELLO", s_NULL, 5);

// 	// Test cases to ensure ft_memcmp matches the standard memcmp
// 	test_ft_memcmp("Hello", "Hello", 5);       // Identical
// 	test_ft_memcmp("Hello", "HellO", 5);       // Case-sensitive difference
// 	test_ft_memcmp("Hello", "Hell", 5);        // Length difference
// 	test_ft_memcmp("abc\0def", "abc\0dEf", 7); // Null byte in middle
// 	test_ft_memcmp("12345", "12346", 5);       // One character difference
// 	test_ft_memcmp("ABC", "abc", 3);           // Case-sensitive, all different
// 	return (0);
// }
