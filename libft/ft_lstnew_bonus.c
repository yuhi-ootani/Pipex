/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:55:46 by oyuhi             #+#    #+#             */
/*   Updated: 2024/10/27 19:30:37 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

// #include <stdio.h> // For printf
// #include <stdlib.h> // For malloc and free

// // Prototype of your ft_lstnew function
// t_list	*ft_lstnew(void *content);

// // Function to print the contents of the node (for testing purposes)
// void	print_node(t_list *node)
// {
// 	if (node == NULL)
// 	{
// 		printf("Node is NULL\n");
// 		return ;
// 	}
// 	printf("Node content: %s\n", (char *)node->content);
// 	printf("Node next: %p\n", (void *)node->next);
// }

// int	main(void)
// {
// 	char	*content1;
// 	t_list	*node1;
// 	t_list	*node2;

// 	// Test case 1: Create a node with a string content
// 	content1 = "Hello, world!";
// 	node1 = ft_lstnew(content1);
// 	printf("Test 1: Node with string content\n");
// 	print_node(node1);
// 	// Test case 2: Create a node with NULL content
// 	node2 = ft_lstnew(NULL);
// 	printf("\nTest 2: Node with NULL content\n");
// 	print_node(node2);
// 	// Free allocated memory to prevent memory leaks
// 	free(node1);
// 	free(node2);
// 	return (0);
// }
