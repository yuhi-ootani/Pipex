/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:28:40 by oyuhi             #+#    #+#             */
/*   Updated: 2024/11/03 17:36:47 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcpy(char *dest, const char *str)
{
	while (*str)
		*dest++ = *str++;
	*dest = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*result;

	len_s1 = 0;
	len_s2 = 0;
	if (s1)
		len_s1 = ft_strlen(s1);
	if (s2)
		len_s2 = ft_strlen(s2);
	result = (char *)malloc(len_s1 + len_s2 + 1);
	if (!result)
		return (NULL);
	if (s1)
		ft_strcpy(result, s1);
	if (s2)
		ft_strcpy(result + len_s1, s2);
	result[len_s1 + len_s2] = '\0';
	return (result);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Declare ft_strjoin prototype for testing.
// char		*ft_strjoin(char const *s1, char const *s2);

// // Test function to verify ft_strjoin behavior.
// void	test_ft_strjoin(char const *s1, char const *s2, const char *expected)
// {
// 	char	*result;

// 	result = ft_strjoin(s1, s2);
// 	if (result == NULL)
// 	{
// 		printf("Test failed: Memory allocation returned NULL.\n");
// 		return ;
// 	}
// 	if (strcmp(result, expected) == 0)
// 	{
// 		printf("Test passed: \"%s\" + \"%s\" = \"%s\"\n", s1, s2, result);
// 	}
// 	else
// 	{
// 		printf("Test failed: \"%s\" + \"%s\" -> Got: \"%s\",Expected: \"%s\"\n",
// 			s1, s2, result, expected);
// 	}
// 	free(result); // Don't forget to free the allocated memory.
// }

// int	main(void)
// {
// 	// Run a few test cases to validate the function.
// 	test_ft_strjoin("Hello", "World", "HelloWorld");
// 	test_ft_strjoin("", "World", "World");
// 	test_ft_strjoin("Hello", "", "Hello");
// 	test_ft_strjoin("", "", "");
// 	test_ft_strjoin(NULL, "World", "World");
// 	test_ft_strjoin("Hello", NULL, "Hello");
// 	test_ft_strjoin(NULL, NULL, "");
// 	return (0);
// }
