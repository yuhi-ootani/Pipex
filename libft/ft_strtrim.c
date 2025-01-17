/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:27:44 by oyuhi             #+#    #+#             */
/*   Updated: 2024/10/27 17:42:33 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	if (!set)
		return (0);
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static void	ft_strncpy(char *dest, const char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && ft_isset(s1[i], set))
		i++;
	while (j >= i && ft_isset(s1[j], set))
		j--;
	if (i > j)
		return ((char *)ft_calloc(1, 1));
	result = (char *)malloc(j - i + 2);
	if (!result)
		return (NULL);
	ft_strncpy(result, s1 + i, j - i + 1);
	return (result);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Helper function to run tests and print results
// void	test_ft_strtrim(char const *s1, char const *set, const char *expected)
// {
// 	char	*result;

// 	result = ft_strtrim(s1, set);
// 	// Handle NULL result and expected comparison
// 	if (!result && !expected)
// 	{
// 		printf("Test passed: ft_strtrim(\"%s\", \"%s\") = NULL\n",
// 			s1 ? s1 : "NULL", set ? set : "NULL");
// 		return ;
// 	}
// 	if (!result || !expected)
// 	{
// 		printf("Test failed: ft_strtrim(\"%s\", \"%s\") -> Got: %s, Expected:"
// 				"%s\n",
// 				s1 ? s1 : "NULL",
// 				set ? set : "NULL",
// 				result ? result : "NULL",
// 				expected ? expected : "NULL");
// 		return ;
// 	}
// 	// Compare results with the expected output
// 	if (strcmp(result, expected) == 0)
// 	{
// 		printf("Test passed: ft_strtrim(\"%s\", \"%s\") = \"%s\"\n",
// 			s1 ? s1 : "NULL", set ? set : "NULL", result);
// 	}
// 	else
// 	{
// 		printf("Test failed: ft_strtrim(\"%s\", \"%s\") -> Got: \"%s\","
// 				"Expected: \"%s\"\n",
// 				s1 ? s1 : "NULL",
// 				set ? set : "NULL",
// 				result,
// 				expected);
// 	}
// 	free(result); // Free allocated memory to avoid memory leaks
// }

// int	main(void)
// {
// 	// Test cases
// 	test_ft_strtrim("  Hello World  ", " ", "Hello World");
// 	test_ft_strtrim("...Hello...", ".", "Hello");
// 	test_ft_strtrim("abcHelloabc", "abc", "Hello");
// 	test_ft_strtrim("xyz", "xyz", "");
// 	test_ft_strtrim("   ", " ", "");
// 	test_ft_strtrim("", " ", "");
// 	test_ft_strtrim("Hello", "", "Hello");
// 	test_ft_strtrim(NULL, " ", NULL);
// 	test_ft_strtrim("Hello", NULL, "Hello");
// 	test_ft_strtrim("ab", "ab", "");

// 	return (0);
// }