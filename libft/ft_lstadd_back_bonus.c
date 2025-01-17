/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:03:16 by oyuhi             #+#    #+#             */
/*   Updated: 2024/10/26 17:20:35 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

// #include <stdio.h> // For printf
// #include <stdlib.h> // For malloc and free

// // Function prototypes
// t_list	*ft_lstnew(void *content);
// void	ft_lstadd_back(t_list **lst, t_list *new);
// void	free_list(t_list **lst);
// void	print_list(t_list *lst);

// // Create a new node
// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*new_node;

// 	new_node = (t_list *)malloc(sizeof(t_list));
// 	if (!new_node)
// 		return (NULL);
// 	new_node->content = content;
// 	new_node->next = NULL;
// 	return (new_node);
// }

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
// 		free(temp);
// 	}
// 	*lst = NULL;
// }

// int	main(void)
// {
// 	t_list	*list1;

// 	// Test case 1: Adding to an empty list
// 	list1 = NULL;
// 	ft_lstadd_back(&list1, ft_lstnew("First"));
// 	print_list(list1); // Expected: First -> NULL
// 	// Test case 2: Adding to a non-empty list
// 	ft_lstadd_back(&list1, ft_lstnew("Second"));
// 	ft_lstadd_back(&list1, ft_lstnew("Third"));
// 	print_list(list1); // Expected: First -> Second -> Third -> NULL
// 	// Test case 3: Adding NULL node (should not change the list)
// 	ft_lstadd_back(&list1, NULL);
// 	print_list(list1); // Expected: First -> Second -> Third -> NULL
// 	// Free the list after tests
// 	free_list(&list1);
// 	return (0);
// }
