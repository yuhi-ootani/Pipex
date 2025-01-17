/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:26:02 by oyuhi             #+#    #+#             */
/*   Updated: 2024/10/26 16:52:14 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h> // For printf
// #include <stdlib.h> // For malloc and free

// // Print the contents of the list
// void	print_list(t_list *lst)
// {
// 	printf("List content:\n");
// 	while (lst)
// 	{
// 		printf("%s -> ", (char *)lst->content);
// 		lst = lst->next;
// 	}
// 	printf("NULL\n");
// }

// // Free the entire linked list
// void	free_list(t_list **lst)
// {
// 	t_list	*temp;

// 	while (*lst)
// 	{
// 		temp = *lst;
// 		*lst = (*lst)->next;
// 		free(temp); // Free each node
// 	}
// 	*lst = NULL;
// }

// int	main(void)
// {
// 	printf("Test 1: Adding to a non-empty list\n");
// 	// Create a list with one node: "World"
// 	t_list *node1 = ft_lstnew("World");
// 	// Add "Hello" to the front
// 	t_list *node2 = ft_lstnew("Hello");
// 	ft_lstadd_front(&node1, node2);
// 	print_list(node1); // Expected: "Hello -> World -> NULL"
// 	free_list(&node1); // Free the list

// 	printf("\nTest 2: Adding multiple nodes to the front\n");
// 	t_list *list = NULL;
// 	ft_lstadd_front(&list, ft_lstnew("Three"));
// 	ft_lstadd_front(&list, ft_lstnew("Two"));
// 	ft_lstadd_front(&list, ft_lstnew("One"));
// 	print_list(list); // Expected: "One -> Two -> Three -> NULL"
// 	free_list(&list);

// 	printf("\nTest 3: Adding a node to an empty list\n");
// 	t_list *empty_list = NULL;
// 	ft_lstadd_front(&empty_list, ft_lstnew("First"));
// 	print_list(empty_list); // Expected: "First -> NULL"
// 	free_list(&empty_list);

// 	printf("\nTest 4: Handling NULL inputs\n");
// 	t_list *null_list = NULL;
// 	ft_lstadd_front(&null_list, NULL); // Should do nothing
// 	print_list(null_list);             // Expected: "NULL"
// 	free_list(&null_list);

// 	return (0);
// }