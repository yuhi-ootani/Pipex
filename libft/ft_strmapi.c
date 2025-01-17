/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:59:27 by oyuhi             #+#    #+#             */
/*   Updated: 2024/10/29 16:37:41 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*ans;
	size_t	i;

	if (!f || !s)
		return (NULL);
	len = ft_strlen(s);
	ans = (char *)malloc(len + 1);
	if (!ans)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ans[i] = f(i, s[i]);
		i++;
	}
	ans[i] = '\0';
	return (ans);
}

// #include <ctype.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Prototype of your ft_strmapi function
// char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// // Example function to be applied by ft_strmapi (converts to uppercase)
// char	to_uppercase(unsigned int i, char c)
// {
// 	(void)i; // Suppress unused parameter warning
// 	if (islower(c))
// 		return (c - 32);
// 	return (c);
// }

// // Example function (shifts each character by index value)
// char	shift_by_index(unsigned int i, char c)
// {
// 	return (c + i);
// }

// // Helper function to test ft_strmapi and print the result
// void	test_ft_strmapi(const char *s, char (*f)(unsigned int, char),
// 		const char *expected)
// {
// 	char	*result;

// 	printf("Testing: \"%s\"\n", s ? s : "NULL");
// 	result = ft_strmapi(s, f);
// 	if (!result)
// 	{
// 		printf("  Result: NULL (allocation failed)\n\n");
// 		return ;
// 	}
// 	if (expected && strcmp(result, expected) == 0)
// 	{
// 		printf("  Result: \"%s\" (PASS)\n", result);
// 	}
// 	else
// 	{
// 		printf("  Result: \"%s\" (FAIL)\n", result);
// 		printf("  Expected: \"%s\"\n", expected);
// 	}
// 	free(result); // Free the allocated memory to avoid leaks
// 	printf("\n");
// }

// int	main(void)
// {
// 	// Test cases
// 	test_ft_strmapi("hello", to_uppercase, "HELLO");
// 	test_ft_strmapi("42tokyo", to_uppercase, "42TOKYO");
// 	test_ft_strmapi("abc", shift_by_index, "ace");
// 	test_ft_strmapi("ABC", shift_by_index, "ACE");
// 	test_ft_strmapi("", to_uppercase, "");     // Edge case: empty string
// 	test_ft_strmapi(NULL, to_uppercase, NULL); // Edge case: NULL input
// 	return (0);
// }
