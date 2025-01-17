/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:34:06 by oyuhi             #+#    #+#             */
/*   Updated: 2024/11/03 17:39:10 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	int		i;
	char	*dup;

	len = ft_strlen(s);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// #include <stdio.h> // For printf
// #include <stdlib.h> // For strdup and free
// #include <string.h> // For strcmp

// char	*ft_strdup(const char *src); // Declare your function prototype

// int	main(void)
// {
// 	// 	// 	////////////////////////////////////////
// 		//strdup causes segmantation fault when passed NULL;
// 		void*	result_std;
// 		char	*s_NULL;
// 		// char *dest_NULL = NULL;
// 		s_NULL = NULL;
// 		result_std = strdup(s_NULL);

// // 	// 	/////////////////////////////////////

// 	const char *test_strings[] = {
// 		"Hello, World!",
// 		"",
// 		"42 Tokyo",
// 		"Testing ft_strdup vs strdup",
// 		"A much longer string for more thorough testing",
// 		NULL // Sentinel to mark end of array
// 	};

// 	int i = 0;
// 	while (test_strings[i] != NULL)
// 	{
// 		char *result_real = strdup(test_strings[i]);
// 		char *result_ft = ft_strdup(test_strings[i]);

// 		if (result_real == NULL || result_ft == NULL)
// 		{
// 			printf("Memory allocation failed.\n");
// 			return (1); // Exit with error if memory allocation failed
// 		}

// 		if (strcmp(result_real, result_ft) == 0)
// 		{
// 			printf("Test %d passed: \"%s\"\n", i + 1, result_ft);
// 		}
// 		else
// 		{
// 			printf("Test %d failed!\n", i + 1);
// 			printf("Expected: \"%s\"\n", result_real);
// 			printf("Got:      \"%s\"\n", result_ft);
// 		}

// 		free(result_real); // Free allocated memory
// 		free(result_ft);

// 		i++;
// 	}

// 	printf("All tests completed.\n");
// 	return (0);
// }