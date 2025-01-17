/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:06:33 by oyuhi             #+#    #+#             */
/*   Updated: 2024/10/27 19:30:30 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// #include <stdio.h> // For printf
// #include <stdlib.h> // For malloc, free

// // Apply the function to print each node's content
// void	print_content(void *content)
// {
// 	printf("[%s] ", (char *)content);
// }

// // Free the entire list
// void	free_list(t_list **lst)
// {
// 	t_list	*temp;

// 	while (*lst)
// 	{
// 		temp = *lst;
// 		*lst = (*lst)->next;
// 		free(temp->content); // Free the content
// 		free(temp);          // Free the node
// 	}
// }

// // Print the list
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
// 	// Create a list with three nodes
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

// 	// Print the list before applying ft_lstiter
// 	print_list(list, "Before applying ft_lstiter:");

// 	// Apply ft_lstiter with print_content to print each node's content
// 	printf("Applying ft_lstiter to print each node's content:\n");
// 	ft_lstiter(list, print_content);
// 	printf("\n");

// 	// Free the list after the test
// 	free_list(&list);

// 	return (0);
// }