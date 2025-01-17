/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:41:39 by oyuhi             #+#    #+#             */
/*   Updated: 2024/10/23 13:54:08 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	return (c);
}

// #include <ctype.h> // For the standard toupper
// #include <stdio.h>

// void	test_ft_toupper(int c)
// {
// 	printf("Input: '%c' (ASCII: %d)\n", c, c);
// 	printf("Standard toupper: '%c' (ASCII: %d)\n", toupper(c), toupper(c));
// 	printf("Your ft_toupper: '%c' (ASCII: %d)\n", ft_toupper(c), ft_toupper(c));
// 	printf("-------------------------------\n");
// }

// int	main(void)
// {
// 	// Test with lowercase, uppercase, non-alphabetic, and EOF
// 	test_ft_toupper('a'); // Lowercase
// 	test_ft_toupper('z'); // Lowercase
// 	test_ft_toupper('A'); // Uppercase
// 	test_ft_toupper('1'); // Non-alphabetic
// 	test_ft_toupper('@'); // Special character
// 	test_ft_toupper(EOF); // EOF
// 	return (0);
// }
