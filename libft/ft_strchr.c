/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:57:32 by oyuhi             #+#    #+#             */
/*   Updated: 2024/10/27 17:44:58 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)(s));
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h> // For the standard strchr

// void	test_ft_strchr(const char *s, int c)
// {
// 	char	*result_std;
// 	char	*result_ft;

// 	result_std = strchr(s, c);
// 	result_ft = ft_strchr(s, c);
// 	printf("String: \"%s\", Char: '%c' (ASCII: %d)\n", s, c, c);
// 	printf("Standard strchr: %s\n", result_std ? result_std : "NULL");
// 	printf("Your ft_strchr:  %s\n", result_ft ? result_ft : "NULL");
// 	printf("-------------------------------\n");
// }

// int	main(void)
// {
// 	// Test with various cases
// 	test_ft_strchr("Hello, World!", 'W');  // Found case
// 	test_ft_strchr("Hello, World!", 'z');  // Not found case
// 	test_ft_strchr("Hello, World!", '\0'); // Null terminator case
// 	test_ft_strchr("", 'H');               // Empty string case
// 	return (0);
// }
