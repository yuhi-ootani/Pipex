/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:40:07 by oyuhi             #+#    #+#             */
/*   Updated: 2024/10/27 19:30:40 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	num;

	num = 0;
	while (lst)
	{
		num++;
		lst = lst->next;
	}
	return (num);
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
// 		free(temp); // Free each node
// 	}
// 	*lst = NULL;
// }

// int	main(void)
// {
// 	// Test case 1: Empty list
// 	t_list *list1 = NULL;
// 	printf("Test 1: Size of empty list: %d\n", ft_lstsize(list1));
// 	// Expected: 0

// 	// Test case 2: List with one node
// 	list1 = ft_lstnew("First");
// 	printf("Test 2: Size of list with one node: %d\n", ft_lstsize(list1));
// 	// Expected: 1

// 	// Test case 3: List with multiple nodes
// 	ft_lstadd_front(&list1, ft_lstnew("Second"));
// 	ft_lstadd_front(&list1, ft_lstnew("Third"));
// 	printf("Test 3: Size of list with three nodes: %d\n", ft_lstsize(list1));
// 	// Expected: 3

// 	// Free the list after tests
// 	free_list(&list1);

// 	return (0);
// }