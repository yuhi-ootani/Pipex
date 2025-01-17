/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:37:06 by oyuhi             #+#    #+#             */
/*   Updated: 2024/10/26 11:53:55 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Pass the address of each character
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	len;
	size_t	i;

	if (!f || !s)
		return ;
	len = ft_strlen(s);
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
// #include <stdio.h>

// // Prototype of your ft_striteri function
// void	ft_striteri(char *s, void (*f)(unsigned int, char *));

// // Example function: Converts even-indexed characters to uppercase
// void	to_upper_if_even(unsigned int i, char *c)
// {
// 	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
// 	{
// 		*c -= 32; // Convert to uppercase if the index is even
// 	}
// }

// // Example function: Shifts each character by its index value
// void	shift_by_index(unsigned int i, char *c)
// {
// 	*c += i; // Shift the character by the index value
// }

// // Helper function to test ft_striteri and print the result
// void	test_ft_striteri(char *s, void (*f)(unsigned int, char *))
// {
// 	if (s)
// 	{
// 		printf("Before: \"%s\"\n", s);
// 		ft_striteri(s, f);
// 		printf("After:  \"%s\"\n\n", s);
// 	}
// 	else
// 	{
// 		printf("Input string is NULL\n\n");
// 	}
// }

// int	main(void)
// {
// 	char	str1[] = "hello";
// 	char	str2[] = "42tokyo";
// 	char	str3[] = "abc";

// 	// Test cases
// 	char str4[] = ""; // Edge case: empty string
// 	printf("Test 1: Convert even-indexed characters to uppercase\n");
// 	test_ft_striteri(str1, to_upper_if_even);
// 	printf("Test 2: Shift characters by their index\n");
// 	test_ft_striteri(str2, shift_by_index);
// 	printf("Test 3: Shift characters by their index\n");
// 	test_ft_striteri(str3, shift_by_index);
// 	printf("Test 4: Handle empty string\n");
// 	test_ft_striteri(str4, to_upper_if_even);
// 	return (0);
// }
