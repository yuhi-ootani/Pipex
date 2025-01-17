/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:28:15 by oyuhi             #+#    #+#             */
/*   Updated: 2024/10/26 19:01:40 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

// #include <stdio.h> // For printf
// #include <stdlib.h> // For malloc, free

// // Custom delete function to free the content
// void	free_content(void *content)
// {
// 	if (content) // Ensure the content is not NULL before freeing
// 		free(content);
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
// 	// Example: Clearing a multi-node list
// 	printf("=== Example: Clearing a Multi-Node List ===\n");

// 	// Create a multi-node list
// 	char *content1 = malloc(6);
// 	char *content2 = malloc(7);
// 	char *content3 = malloc(5);
// 	if (!content1 || !content2 || !content3)
// 	{
// 		printf("Memory allocation failed.\n");
// 		return (1);
// 	}

// 	snprintf(content1, 6, "First");
// 	snprintf(content2, 7, "Second");
// 	snprintf(content3, 5, "Last");

// 	t_list *list = ft_lstnew(content1);
// 	list->next = ft_lstnew(content2);
// 	list->next->next = ft_lstnew(content3);

// 	print_list(list, "Before clearing the list:");

// 	// Clear the list
// 	ft_lstclear(&list, free_content);

// 	// Print the list after clearing
// 	print_list(list, "After clearing the list:");

// 	return (0);
// }