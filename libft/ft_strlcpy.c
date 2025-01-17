/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:37:22 by oyuhi             #+#    #+#             */
/*   Updated: 2024/11/03 17:40:30 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (src[len])
	{
		len++;
	}
	if (size == 0)
		return (len);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

// #include <stdio.h>
// #include <string.h>

// // Prototype for ft_strlcpy
// size_t	ft_strlcpy(char *dst, const char *src, size_t size);

// int	main(void)
// {
// 	// 	// 	////////////////////////////////////////
// // 	//memcpy causes segmantation fault when passed NULL;
// 	size_t	result_std;
// 	char	*s_NULL;
// 	// char *dest_NULL = NULL;
// 	s_NULL = NULL;
// 	result_std = strlcpy(s_NULL, "I", 5);
// // 	// 	/////////////////////////////////////
// 	char	dest[10];
// 	size_t	len;

// 	// Test Case 1: Normal copy with space to spare
// 	len = ft_strlcpy(dest, "Hello", sizeof(dest));
// 	printf("Copied: %s | Length: %zu\n", dest, len); // Expect: "Hello" | 5
// 	// Test Case 2: Exact fit
// 	len = ft_strlcpy(dest, "HelloWorld", sizeof(dest));
// 	printf("Copied: %s | Length: %zu\n", dest, len); // Expect: "HelloWorl" | 10
// 	// Test Case 3: Truncation
// 	len = ft_strlcpy(dest, "1234567890", 5);         // Only 4 characters + '\0'
// 	printf("Copied: %s | Length: %zu\n", dest, len); // Expect: "1234" | 10
// 	// Test Case 4: Empty source string
// 	len = ft_strlcpy(dest, "", sizeof(dest));
// 	printf("Copied: %s | Length: %zu\n", dest, len); // Expect: "" | 0
// 	// Test Case 5: Size 0 (nothing copied)
// 	len = ft_strlcpy(dest, "Hello", 0);
// 	printf("Copied (size 0): %s | Length: %zu\n", dest, len); // Expect: "" | 5
// 	return (0);
// }
