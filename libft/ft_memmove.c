/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:52:10 by oyuhi             #+#    #+#             */
/*   Updated: 2024/11/03 17:41:11 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// If dest starts after src and overlaps: Copy backwards to avoid overwriting.
// If no overlap or dest before src: Copy forwards (more efficient).
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	d = dest;
	s = src;
	if (d > s && d < s + n)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// NORMAL VERSION////////////////

// // Prototype for ft_memmove
// void *ft_memmove(void *dest, const void *src, size_t n);

// int main() {
//     char buffer1[20] = "Hello, World!";
//     char buffer2[20] = "Hello, World!";

//     // Standard memmove
//     memmove(buffer1 + 6, buffer1, 6);
//     printf("memmove result: %s\n", buffer1);

//     // Your ft_memmove
//     ft_memmove(buffer2 + 6, buffer2, 6);
//     printf("ft_memmove result: %s\n", buffer2);

//     return (0);
// }

// EDGE CASE VERSION ////////////////////////

// #include <stdio.h>
// #include <string.h>

// // Prototype for ft_memmove
// void	*ft_memmove(void *dest, const void *src, size_t n);

// int	main(void)
// {
// 	////////////////////////////////////////
// 	// //memcpy causes segmantation fault when passed NULL;
// 	// void*	result_std;
// 	// char	*s_NULL;
// 	// // char *dest_NULL = NULL;
// 	// s_NULL = NULL;
// 	// result_std = memmove(s_NULL, "HELLO", 5);
// 	// result_std = memmove("HELLO", s_NULL, 5);

// 	/////////////////////////////////////

// 	int	src[10] = {INT_MAX, INT_MAX, 2, 3, 4, 5, 6, 7, 8, 9};

// 	int dest[10] = {0}; // Initialize destination with zeroes
// 	// Print initial state
// 	printf("Before memmove:\n");
// 	printf("src:  ");
// 	for (int i = 0; i < 10; i++)
// 	{
// 		printf("%d ", src[i]);
// 	}
// 	printf("\ndest: ");
// 	for (int i = 0; i < 10; i++)
// 	{
// 		printf("%d ", dest[i]);
// 	}
// 	printf("\n");
// 	// Use your ft_memmove to copy 5 elements from src to dest
// 	ft_memmove(dest, src, 5);
// 	// Print result
// 	printf("\nAfter ft_memmove:\n");
// 	printf("src:  ");
// 	for (int i = 0; i < 10; i++)
// 	{
// 		printf("%d ", src[i]);
// 	}
// 	printf("\ndest: ");
// 	for (int i = 0; i < 10; i++)
// 	{
// 		printf("%d ", dest[i]);
// 	}
// 	printf("\n");
// 	return (0);
// }
