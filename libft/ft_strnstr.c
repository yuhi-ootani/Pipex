/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:05:04 by oyuhi             #+#    #+#             */
/*   Updated: 2024/11/03 17:39:00 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	i = 0;
	while (big[i] && i + little_len <= len)
	{
		if (big[i] == little[0])
		{
			if (ft_strncmp(&big[i], little, little_len) == 0)
				return ((char *)(&big[i]));
		}
		i++;
	}
	return (NULL);
}

// // undefine about NULL paraments
// #include <stdio.h>
// #include <string.h> // For size_t

// // Prototype for your custom ft_strnstr
// char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

// // Function to test and print the result of ft_strnstr
// void	test_ft_strnstr(const char *haystack, const char *needle, size_t len)
// {
// 	char *result_ft = ft_strnstr(haystack, needle, len); // Custom function
// 	printf("Searching for \"%s\" in \"%s\" (first %zu characters):\n", needle,
// 		haystack, len);
// 	printf("Your ft_strnstr:  %s\n", result_ft ? result_ft : "NULL");
// 	printf("-------------------------------\n");
// }

// int	main(void)
// {
// 	// Test cases for your ft_strnstr function
// 	test_ft_strnstr("Hello, World!", "World", 12); // Found within range
// 	test_ft_strnstr("Hello, World!", "world", 12); // Case-sensitive mismatch
// 	test_ft_strnstr("Hello, World!", "", 12);      // Empty needle
// 	test_ft_strnstr("Hello, World!", "World", 5);  // Out of range
// 	test_ft_strnstr("", "", 1);                    // Both empty strings
// 	test_ft_strnstr("Helloo", "lo", 5);            // Found at end
// 	test_ft_strnstr("Hello", "lo", 3);             // Out of range
// 	test_ft_strnstr("abcdef", "def", 6);           // Substring at end
// 	test_ft_strnstr("abc\0def", "def", 7);         // Null byte in middle
// 	return (0);
// }

// // Test suite to verify the correctness of ft_strnstr
// int	main(void)
// {
// 	printf("%s\n", ft_strnstr("Hello, World!", "World", 12));
// 	// Expected: "World!"
// 	printf("%s\n", ft_strnstr("Hello, World!", "world", 12));
// 	// Expected: (null)
// 	printf("%s\n", ft_strnstr("Hello, World!", "", 12));
// 	// Expected: "Hello, World!"
// 	printf("%s\n", ft_strnstr("Hello, World!", "World", 5));
// 	// Expected: (null)
// 	printf("%s\n", ft_strnstr("", "", 1));        // Expected: ""
// 	printf("%s\n", ft_strnstr("Hello", "lo", 5)); // Expected: "lo"
// 	printf("%s\n", ft_strnstr("Hello", "lo", 3));

// 	return (0);
// }