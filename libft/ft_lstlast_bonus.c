/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:55:49 by oyuhi             #+#    #+#             */
/*   Updated: 2024/10/27 19:30:32 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

// #include <stdio.h> // For printf
// #include <stdlib.h> // For malloc and free

// // Free the entire linked list
// void	free_list(t_list **lst)
// {
// 	t_list	*temp;

// 	while (*lst)
// 	{
// 		temp = *lst;
// 		*lst = (*lst)->next;
// 		free(temp);
// 	}
// 	*lst = NULL;
// }

// // Helper function to print the content of the last node
// void	print_last_node(t_list *lst, const char *description)
// {
// 	t_list	*last;

// 	last = ft_lstlast(lst);
// 	printf("%s: ", description);
// 	if (last)
// 		printf("%s\n", (char *)last->content);
// 	else
// 		printf("NULL\n");
// }

// int	main(void)
// {
// 	t_list	*list1;

// 	// Test case 1: Empty list
// 	list1 = NULL;
// 	print_last_node(list1, "Test 1 - Last node of empty list");
// 	// Expected: NULL
// 	// Test case 2: List with one node
// 	list1 = ft_lstnew("Only Node");
// 	print_last_node(list1, "Test 2 - Last node of one-node list");
// 	// Expected: Only Node
// 	// Test case 3: List with multiple nodes
// 	ft_lstadd_front(&list1, ft_lstnew("Second"));
// 	ft_lstadd_front(&list1, ft_lstnew("First"));
// 	print_last_node(list1, "Test 3 - Last node of three-node list");
// 	// Expected: Only Node
// 	// Free the list after tests
// 	free_list(&list1);
// 	return (0);
// }
