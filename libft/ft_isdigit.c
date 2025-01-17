/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:49:44 by oyuhi             #+#    #+#             */
/*   Updated: 2024/11/03 17:41:49 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

// #include <stdio.h>

// int		ft_isdigit(int c);

// void	test_ft_isdigit(void)
// {
// 	int			test_cases[] = {'0', '5', '9', 'a', 'Z', '!', -1, 128};
// 	int			expected_results[] = {1, 1, 1, 0, 0, 0, 0, 0};
// 	const char	*labels[] = {"'0'", "'5'", "'9'", "'a'", "'Z'", "'!'", "-1",
// 			"128"};
// 	int			num_tests;
// 	int			passed;
// 	int			result;

// 	// Test cases
// 	num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
// 	passed = 1;
// 	for (int i = 0; i < num_tests; i++)
// 	{
// 		result = ft_isdigit(test_cases[i]);
// 		if (result == expected_results[i])
// 		{
// 			printf("Test %d (%s): Passed\n", i + 1, labels[i]);
// 		}
// 		else
// 		{
// 			printf("Test %d (%s): Failed (Expected %d, got %d)\n", i + 1,
// 				labels[i], expected_results[i], result);
// 			passed = 0;
// 		}
// 	}
// 	if (passed)
// 		printf("All tests passed!\n");
// 	else
// 		printf("Some tests failed.\n");
// }

// int	main(void)
// {
// 	test_ft_isdigit();
// 	return (0);
// }
