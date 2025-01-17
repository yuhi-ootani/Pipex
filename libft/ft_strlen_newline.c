/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_newline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:35:05 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/17 12:34:30 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_newline(char *str)
{
	int	len;

	if (!str)
		return (-1);
	len = 0;
	while (str[len] && str[len] != '\n')
	{
		if (len == INT_MAX)
			return (-1);
		len++;
	}
	return (len);
}
