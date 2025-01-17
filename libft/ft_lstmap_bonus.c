/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:34:57 by oyuhi             #+#    #+#             */
/*   Updated: 2024/10/27 19:30:35 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*content;

	if (!f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			del(content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

// #include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

// // Function to double the value
// void	*double_value(void *content)
// {
// 	int	*value;

// 	value = malloc(sizeof(int));
// 	if (!value)
// 		return (NULL);
// 	*value = *(int *)content * 2;
// 	return (value);
// }

// // Function to delete the content
// void	delete_content(void *content)
// {
// 	free(content);
// }

// // Mock function to simulate malloc failure
// void	*mock_function(void *content)
// {
// 	(void)content;
// 	return (NULL); // Simulate failure
// }

// // Function to return NULL for negative values
// void	*null_return_function(void *content)
// {
// 	if (*(int *)content < 0)
// 		return (NULL);
// 	return (double_value(content));
// }

// // Test Case 1: Empty list
// void	test_empty_list(void)
// {
// 	t_list	*empty_list;
// 	t_list	*mapped_empty;

// 	printf("Test Case 1: Empty List\n");
// 	empty_list = NULL;
// 	mapped_empty = ft_lstmap(empty_list, double_value, delete_content);
// 	if (mapped_empty == NULL)
// 		printf("Passed: Empty list handled correctly.\n");
// 	else
// 		printf("Failed: Empty list not handled correctly.\n");
// }

// // Test Case 2: Single element
// void	test_single_element(void)
// {
// 	t_list	*single_list;
// 	t_list	*mapped_single;

// 	printf("\nTest Case 2: Single Element\n");
// 	single_list = ft_lstnew(malloc(sizeof(int)));
// 	*(int *)(single_list->content) = 5;
// 	mapped_single = ft_lstmap(single_list, double_value, delete_content);
// 	if (mapped_single && *(int *)(mapped_single->content) == 10)
// 		printf("Passed: Single element handled correctly.\n");
// 	else
// 		printf("Failed: Single element not handled correctly.\n");
// 	ft_lstclear(&single_list, delete_content);
// 	ft_lstclear(&mapped_single, delete_content);
// }

// // Test Case 3: Memory allocation failure
// void	test_allocation_failure(void)
// {
// 	t_list	*fail_list;
// 	t_list	*mapped_fail;

// 	printf("\nTest Case 3: Memory Allocation Failure\n");
// 	fail_list = ft_lstnew(malloc(sizeof(int)));
// 	*(int *)(fail_list->content) = 1;
// 	mapped_fail = ft_lstmap(fail_list, mock_function, delete_content);
// 	if (mapped_fail == NULL)
// 		printf("Passed: Memory allocation failure handled correctly.\n");
// 	else
// 		printf("Failed: Memory allocation failure not handled correctly.\n");
// 	ft_lstclear(&fail_list, delete_content);
// }

// // Test Case 4: List with mixed values
// void	test_mixed_values(void)
// {
// 	t_list	*mixed_list;
// 	t_list	*mapped_mixed;
// 	t_list	*curr;

// 	printf("\nTest Case 4: Mixed Values\n");
// 	mixed_list = ft_lstnew(malloc(sizeof(int)));
// 	*(int *)(mixed_list->content) = 0;
// 	ft_lstadd_back(&mixed_list, ft_lstnew(malloc(sizeof(int))));
// 	*(int *)(mixed_list->next->content) = -2;
// 	ft_lstadd_back(&mixed_list, ft_lstnew(malloc(sizeof(int))));
// 	*(int *)(mixed_list->next->next->content) = 7;
// 	mapped_mixed = ft_lstmap(mixed_list, double_value, delete_content);
// 	curr = mapped_mixed;
// 	printf("Mapped List: ");
// 	while (curr)
// 	{
// 		printf("%d ", *(int *)(curr->content));
// 		curr = curr->next;
// 	}
// 	printf("\n");
// 	ft_lstclear(&mixed_list, delete_content);
// 	ft_lstclear(&mapped_mixed, delete_content);
// }

// // Test Case 5: NULL return from function
// void	test_null_return(void)
// {
// 	t_list	*neg_list;
// 	t_list	*mapped_neg;

// 	printf("\nTest Case 5: NULL Return Handling\n");
// 	neg_list = ft_lstnew(malloc(sizeof(int)));
// 	*(int *)(neg_list->content) = -1;
// 	ft_lstadd_back(&neg_list, ft_lstnew(malloc(sizeof(int))));
// 	*(int *)(neg_list->next->content) = 3;
// 	mapped_neg = ft_lstmap(neg_list, null_return_function, delete_content);
// 	if (mapped_neg == NULL)
// 		printf("Passed: NULL return (handled correctly.\n");
// 	else
// 		printf("Failed: NULL return (not handled correctly.\n");
// 	ft_lstclear(&neg_list, delete_content);
// }

// int	main(void)
// {
// 	test_empty_list();
// 	test_single_element();
// 	test_allocation_failure();
// 	test_mixed_values();
// 	test_null_return();
// 	return (0);
// }
