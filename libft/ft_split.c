/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:58:16 by oyuhi             #+#    #+#             */
/*   Updated: 2024/10/25 17:37:07 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	words;
	int		in_word;

	words = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			words++;
		}
		if (*s == c)
			in_word = 0;
		s++;
	}
	return (words);
}

static char	*ft_strndup(const char *s, size_t len)
{
	size_t	i;
	char	*dup;

	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static void	ft_free(char **arr, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

// Insert words into the result array
static int	ft_insert_word(char **result, const char *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	index;

	i = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			result[index] = ft_strndup(s + start, i - start);
			if (!result[index])
			{
				ft_free(result, index);
				return (0);
			}
			index++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	result = (char **)malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result[words] = NULL;
	if (!ft_insert_word(result, s, c))
		return (NULL);
	return (result);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Helper function to print the result of ft_split
// void	print_split_result(char **result)
// {
// 	if (!result)
// 	{
// 		printf("ft_split returned NULL (allocation failure).\n");
// 		return ;
// 	}
// 	for (int i = 0; result[i]; i++)
// 	{
// 		printf("  [%d]: \"%s\"\n", i, result[i]);
// 	}
// 	// Free the allocated memory
// 	for (int i = 0; result[i]; i++)
// 		free(result[i]);
// 	free(result);
// }

// // Test function for ft_split
// void	test_ft_split(char const *s, char c)
// {
// 	char	**result;

// 	printf("\nTesting: \"%s\" with delimiter '%c'\n", s ? s : "NULL", c);
// 	result = ft_split(s, c);
// 	print_split_result(result);
// }

// int	main(void)
// {
// 	// Test cases
// 	test_ft_split("Hello World", ' ');
// 	test_ft_split("abc:def:ghi", ':');
// 	test_ft_split(" leading space", ' ');
// 	test_ft_split("  only spaces ", ' ');
// 	test_ft_split("abc:def::ghi", ':');
// 	test_ft_split("", ',');
// 	test_ft_split(NULL, ',');
// 	test_ft_split("no_delimiters", ',');
// 	return (0);
// }
