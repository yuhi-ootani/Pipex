/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:15:11 by oyuhi             #+#    #+#             */
/*   Updated: 2024/11/03 17:40:12 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Use (unsigned char) for Comparison:
We cast s1[i] and s2[i] to unsigned char to ensure correct
comparisons (since character values should be treated as unsigned).*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && (s1[i] == s2[i]))
	{
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// #include <stdio.h>
// #include <string.h> // For the standard strncmp

// int		ft_strncmp(const char *s1, const char *s2, size_t n);

// void	test_ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	int	result_std;
// 	int	result_ft;

// 	result_std = strncmp(s1, s2, n);
// 	result_ft = ft_strncmp(s1, s2, n);
// 	printf("Comparing \"%s\" and \"%s\" for %zu characters:\n", s1, s2, n);
// 	printf("Standard strncmp: %d\n", result_std);
// 	printf("Your ft_strncmp:  %d\n", result_ft);
// 	printf("-------------------------------\n");
// }

// int	main(void)
// {
// // 	// 	////////////////////////////////////////
// // 	//memcpy causes segmantation fault when passed NULL;
// 	int	result_std;
// 	char	*s_NULL;
// 	// char *dest_NULL = NULL;
// 	s_NULL = NULL;
// 	result_std = strmcmp(s_NULL, "I", 5);

// // 	// 	/////////////////////////////////////
// 	// Test with various cases
// 	test_ft_strncmp("Hello", "Hello", 5); // Identical strings
// 	test_ft_strncmp("Hello", "Hel", 3);   // Same prefix, different length
// 	test_ft_strncmp("Hello", "hello", 5); // Case-sensitive comparison
// 	test_ft_strncmp("Hello", "Hella", 5); // One character difference
// 	test_ft_strncmp("abc", "abcdef", 5);  // One shorter than the other
// 	return (0);
// }
// What Happens with NULL Inputs?
// 1. If s1 or s2 is NULL
// Behavior:

// If either s1 or s2 is NULL,
// 	strncmp will attempt to dereference
// a NULL pointer to access the string's characters.
// 	// This will result in undefined behavior,
// 	typically causing a segmentation fault(crash)
