/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:55:34 by oyuhi             #+#    #+#             */
/*   Updated: 2024/11/04 17:35:39 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

static int	ft_isnumber(char c)
{
	return (c >= '0' && c <= '9');
}

static long long	ft_sign(char c)
{
	if (c == '-')
	{
		return (-1);
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	long long	result;
	long long	sign;

	result = 0;
	while (ft_isspace(*nptr))
	{
		nptr++;
	}
	sign = ft_sign(*nptr);
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	while (ft_isnumber(*nptr))
	{
		if ((result > (LONG_MAX - (*nptr - '0')) / 10))
		{
			if (sign == 1)
				return ((int)LONG_MAX);
			return ((int)LONG_MIN);
		}
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return ((int)(result * sign));
}
//// if (result > LONG_MAX / 10 || (result == LONG_MAX / 10 && *nptr
//// 				- '0' > LONG_MAX % 10))

// // don't need to return 0 if NULL is passed.
// // atoi function also caused segfault.
// #include <limits.h> // For INT_MIN and INT_MAX
// #include <stdio.h>

// void	test_ft_atoi(const char *str)
// {
// 	int	result_ft;
// 	int	result;

// 	result_ft = ft_atoi(str);
// 	result = atoi(str);
// 	printf("ft_atoi(\"%s\") = %d (answer:%d)\n", str, result_ft, result);
// 	// printf("ft_atoi(\"%s\") = %d \n", str, result_ft);
// }

// int	main(void)
// {
// 	// Basic valid conversions
// 	test_ft_atoi("42");     // Expected: 42
// 	test_ft_atoi("   123"); // Expected: 123
// 	test_ft_atoi("-456");   // Expected: -456
// 	test_ft_atoi("+789");   // Expected: 789
// 	// With leading whitespaces
// 	test_ft_atoi("\t\n  214");   // Expected: 214
// 	test_ft_atoi(" \f\v\r-214"); // Expected: -214
// 	// With non-numeric characters after the number
// 	test_ft_atoi("123abc"); // Expected: 123 (stops at 'a')
// 	test_ft_atoi("-98.76"); // Expected: -98 (stops at '.')
// 	// Strings without valid numbers
// 	test_ft_atoi("abc");  // Expected: 0 (no numeric part)
// 	test_ft_atoi("--42"); // Expected: 0 (invalid format: multiple signs)
// 	test_ft_atoi("");     // Expected: 0 (empty string)
// 	// Large numbers to test overflow and edge cases
// 	test_ft_atoi("2147483647");
// 	// Expected: 2147483647 (INT_MAX)
// 	test_ft_atoi("-2147483648");
// 	// Expected: -2147483648 (INT_MIN)
// 	test_ft_atoi("2147483648");
// 	// Expected: 2147483647 (overflow -> INT_MAX)
// 	test_ft_atoi("-2147483649");
// 	// Expected: -2147483648 (overflow -> INT_MIN)
// 	// Extremely large numbers beyond `long long` range
// 	// 9,223,372,036,854,775,807
// 	test_ft_atoi("9223372036854775806");
// 	test_ft_atoi("9223372036854775807");
// 	test_ft_atoi("9223372036854775808");
// 	test_ft_atoi("9223372036854775810");
// 	// Expected: 2147483647 (overflow-> INT_MAX)
// 	//-9,223,372,036,854,775,807 - 1
// 	test_ft_atoi("-9223372036854775807");
// 	test_ft_atoi("-9223372036854775808");
// 	test_ft_atoi("-9223372036854775809");
// 	test_ft_atoi("-9223372036854775810");
// 	// Expected: -2147483648 (overflow-> INT_MIN)
// 	// Large unsigned number that doesn't fit in signed int/long long
// 	// 18,446,744,073,709,551,615
// 	test_ft_atoi("18446744073709551614");
// 	test_ft_atoi("18446744073709551615");
// 	test_ft_atoi("18446744073709551616");
// 	test_ft_atoi("18446744073709551625");
// 	// Expected: 2147483647 (overflow-> INT_MAX)
// 	return (0);
// }

///////////////////////////////////////////////////////////////
// if (sign == 1 && result > INT_MAX)
// 	return (INT_MAX);
// if (sign == -1 && result > (unsigned long long)INT_MAX + 1)
// 	return (INT_MIN);

// if	((sign == 1 && (result > LONG_MAX / 10 || (result == LONG_MAX / 10
// 					&& *nptr
// 					- '0' > LONG_MAX % 10))))
// 	return ((int)LONG_MAX);
// if	((sign == -1 && (result < LONG_MIN / 10 || (result == -(LONG_MIN / 10)
// 					&& *nptr - '0' > -(LONG_MIN % 10)))))
// 	return ((int)LONG_MIN);
//////////////////////////////////////////////////