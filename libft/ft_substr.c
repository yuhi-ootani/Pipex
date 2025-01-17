/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:06:34 by oyuhi             #+#    #+#             */
/*   Updated: 2024/10/27 17:43:16 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	i;
	char	*sub;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return ((char *)ft_calloc(1, 1));
	if (len > len_s - start)
		len = len_s - start;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

// #include <stdio.h>

// char	*ft_substr(char const *s, unsigned int start, size_t len);

// int	main(void)
// {
// 	char	*str;

// 	str = "Hello, world!";
// 	char *sub1 = ft_substr(str, 0, 5);  // Should return "Hello"
// 	char *sub2 = ft_substr(str, 7, 5);  // Should return "world"
// 	char *sub3 = ft_substr(str, 20, 5); // Out of bounds, should return ""
// 	char *sub4 = ft_substr(str, 3, 50); // Should handle len beyond string end
// 	printf("Sub1: %s\n", sub1);
// 	printf("Sub2: %s\n", sub2);
// 	printf("Sub3: %s\n", sub3);
// 	printf("Sub4: %s\n", sub4);
// 	// Free allocated memory
// 	free(sub1);
// 	free(sub2);
// 	free(sub3);
// 	free(sub4);
// 	return (0);
// }
