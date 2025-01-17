/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:09:12 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/17 12:34:25 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_array_dup(char **array)
{
	int		i;
	char	**new_array;
	int		j;

	if (!array || !array[0])
		return (NULL);
	i = 0;
	while (array[i])
		i++;
	new_array = (char **)malloc(sizeof(char *) * (i + 1));
	if (!new_array)
		return (NULL);
	j = 0;
	while (j < i)
	{
		new_array[j] = ft_strdup(array[j]);
		if (!new_array[j])
		{
			ft_array_free(new_array);
			return (NULL);
		}
		j++;
	}
	new_array[i] = NULL;
	return (new_array);
}
