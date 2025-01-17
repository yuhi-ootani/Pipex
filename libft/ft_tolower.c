/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:54:39 by oyuhi             #+#    #+#             */
/*   Updated: 2024/11/03 17:35:11 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	return (c);
}

// #include <ctype.h> // For the standard tolower
// #include <stdio.h>

// int		ft_tolower(int c);

// void	test_ft_tolower(int c)
// {
// 	printf("Input: '%c' (ASCII: %d)\n", c, c);
// 	printf("Standard tolower: '%c' (ASCII: %d)\n", tolower(c), tolower(c));
// 	printf("Your ft_tolower: '%c' (ASCII: %d)\n", ft_tolower(c), ft_tolower(c));
// 	printf("-------------------------------\n");
// }

// int	main(void)
// {
// 	// Test with uppercase, lowercase, non-alphabetic, and EOF
// 	test_ft_tolower('A'); // Uppercase
// 	test_ft_tolower(577); // Uppercase
// 	test_ft_tolower('a'); // Lowercase
// 	test_ft_tolower('1'); // Non-alphabetic
// 	test_ft_tolower('@'); // Special character
// 	test_ft_tolower(EOF); // EOF
// 	return (0);
// }
