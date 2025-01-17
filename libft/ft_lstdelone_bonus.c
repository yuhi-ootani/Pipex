/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:20:48 by oyuhi             #+#    #+#             */
/*   Updated: 2024/10/27 19:30:27 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Function to delete a single node and its content
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// #include <stdio.h> // For printf
// #include <stdlib.h> // For malloc, free

// // Custom delete function to free the content
// void	free_content(void *content)
// {
// 	free(content); // Free dynamically allocated content
// }

// // Print the list with a message
// void	print_list(t_list *lst, const char *message)
// {
// 	printf("%s\n", message);
// 	if (!lst)
// 	{
// 		printf("List is empty.\n");
// 		return ;
// 	}
// 	while (lst)
// 	{
// 		printf("[%s] -> ", (char *)lst->content);
// 		lst = lst->next;
// 	}
// 	printf("NULL\n");
// }

// int	main(void)
// {
// 	// Example 1: Deleting a single node
// 	printf("=== Example 1: Deleting a Single Node ===\n");
// 	char *content1 = malloc(6); // Allocate memory for "Hello"
// 	snprintf(content1, 6, "Hello");
// 	t_list *node1 = ft_lstnew(content1);

// 	print_list(node1, "Before deleting the single node:");
// 	ft_lstdelone(node1, free_content); // Delete the node
// 	print_list(NULL, "After deleting the single node:");

// 	// Example 2: Deleting the first node in a two-node list
// 	printf("\n=== Example 2: Deleting the First Node in a Two-Node List ===\n");
// 	char *content2 = malloc(6);
// 	char *content3 = malloc(7);
// 	snprintf(content2, 6, "Node1");
// 	snprintf(content3, 7, "Node2");

// 	t_list *node2 = ft_lstnew(content2);
// 	t_list *node3 = ft_lstnew(content3);
// 	node2->next = node3; // Link the nodes

// 	print_list(node2, "Before deleting the first node:");
// 	ft_lstdelone(node2, free_content); // Delete the first node
// 	print_list(node3, "After deleting the first node:");

// 	// Clean up the remaining node
// 	ft_lstdelone(node3, free_content);

// 	return (0);
// }