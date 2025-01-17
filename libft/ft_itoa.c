/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:37:48 by oyuhi             #+#    #+#             */
/*   Updated: 2024/10/28 12:55:22 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_digits(int n)
{
	size_t	digits;
	long	ln;

	if (n == 0)
		return (1);
	digits = 0;
	ln = n;
	if (ln < 0)
	{
		ln = -ln;
		digits = 1;
	}
	while (ln > 0)
	{
		digits++;
		ln /= 10;
	}
	return (digits);
}

// Convert integer to string
char	*ft_itoa(int n)
{
	size_t	digits;
	long	ln;
	char	*ans;

	digits = ft_count_digits(n);
	ans = (char *)ft_calloc(digits + 1, 1);
	if (!ans)
		return (NULL);
	ans[digits] = '\0';
	ln = n;
	if (ln < 0)
	{
		ans[0] = '-';
		ln = -ln;
	}
	while (digits-- && ans[digits] != '-')
	{
		ans[digits] = (ln % 10) + '0';
		ln /= 10;
	}
	return (ans);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Helper function to test ft_itoa and print the result
// void	test_ft_itoa(int n, const char *expected)
// {
// 	char	*result;

// 	printf("Testing: ft_itoa(%d)\n", n);
// 	result = ft_itoa(n);
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

// // // Main function to run tests
// int	main(void)
// {
// 	// Test cases
// 	test_ft_itoa(0, "0");
// 	test_ft_itoa(123, "123");
// 	test_ft_itoa(-123, "-123");
// 	test_ft_itoa(2147483647, "2147483647");   // INT_MAX
// 	test_ft_itoa(-2147483648, "-2147483648"); // INT_MIN
// 	test_ft_itoa(42, "42");
// 	test_ft_itoa(-42, "-42");
// 	return (0);
// }
