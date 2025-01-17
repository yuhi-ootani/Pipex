/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:24:58 by oyuhi             #+#    #+#             */
/*   Updated: 2024/11/03 17:40:39 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while (dst_len + i < size - 1 && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// #include <stdio.h>
// #include <string.h> // For comparison with the real strlcat

// void	test_ft_strlcat(const char *initial_dst, const char *src, size_t size)
// {
// 	size_t	result;

// 	char dst[10];             // Buffer for testing
// 	strcpy(dst, initial_dst); // Initialize destination
// 	result = ft_strlcat(dst, src, size);
// 	printf("Initial: \"%s\", Src: \"%s\", Size: %zu\n", initial_dst, src, size);
// 	printf("Result: \"%s\", Return: %zu\n", dst, result);
// 	printf("-------------------------------\n");
// }

// int	main(void)
// {

// 	// 	// 	////////////////////////////////////////
// // 	//strlcat causes segmantation fault when passed NULL;
// 	size_t	result_std;
// 	char	*s_NULL;
// 	// char *dest_NULL = NULL;
// 	s_NULL = NULL;
// 	result_std = ft_strlcat(s_NULL, "I", 5);
// 	result_std = ft_strlcat("s_NULL", s_NULL, 5);
// // 	// 	/////////////////////////////////////
// 	// Test various cases
// 	test_ft_strlcat("Hello", " 012345678901234567890123456789", 10);
// 	// Normal case
// 	test_ft_strlcat("Hello", " World", 10);
// 	// Truncation
// 	test_ft_strlcat("", "Test", 5);
// 	// Empty destination
// 	test_ft_strlcat("Hi", "", 5);
// 	// Empty source
// 	test_ft_strlcat("LongString", "123", 10);
// 	// Partial append
// 	return (0);
// }
