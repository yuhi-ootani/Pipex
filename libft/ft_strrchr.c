/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:03:52 by oyuhi             #+#    #+#             */
/*   Updated: 2024/11/03 17:13:31 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The strchr() function returns a pointer to
// the first occurrence of the character c in the string s.
char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (last);
}

// #include <stdio.h>
// #include <string.h> // For the standard strrchr

// char	*ft_strrchr(const char *s, int c);

// void	test_ft_strrchr(const char *s, int c)
// {
// 	char	*result_std;
// 	char	*result_ft;

// 	result_std = strrchr(s, c);
// 	result_ft = ft_strrchr(s, c);
// 	printf("String: \"%s\", Char: '%c' (ASCII: %d)\n", s, c, c);
// 	printf("Standard strrchr: %s\n", result_std ? result_std : "NULL");
// 	printf("Your ft_strrchr:  %s\n", result_ft ? result_ft : "NULL");
// 	printf("-------------------------------\n");
// }

// int	main(void)
// {

	// 	// 	// 	////////////////////////////////////////
	// 	//strrchr causes segmantation fault when passed NULL;
	// char *result = NULL;
	// char* s_NULL = NULL;
	// result = strrchr(s_NULL,4);
	// // 	// 	/////////////////////////////////////

//	// Test with various cases
// 	test_ft_strrchr("Hello, World!", 'o');  // Multiple occurrences
// 	test_ft_strrchr("Hello, World!", 'z');  // Not found
// 	test_ft_strrchr("Hello, World!", '\0'); // Null terminator case
// 	test_ft_strrchr("", 'H');               // Empty string case
// 	return (0);
// }
