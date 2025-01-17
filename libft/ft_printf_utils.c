/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:55:52 by otaniyuhi         #+#    #+#             */
/*   Updated: 2025/01/12 09:38:22 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	numlen_prt(unsigned long long ull, int base)
{
	size_t	len;

	len = 0;
	if (ull == 0)
		return (1);
	while (ull > 0)
	{
		len++;
		ull /= base;
	}
	return (len);
}

char	*itoa_ull_prt(unsigned long long ull, int base, char sign)
{
	const char	lower[16] = "0123456789abcdef";
	const char	upper[16] = "0123456789ABCDEF";
	const char	*symbols;
	size_t		len;
	char		*str;

	len = numlen_prt(ull, base);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (ull == 0)
		str[0] = '0';
	if (sign == 'X')
		symbols = upper;
	else
		symbols = lower;
	while (ull)
	{
		str[--len] = symbols[ull % base];
		ull /= base;
	}
	return (str);
}

int	putnbr_prt(unsigned long long ull, int base, char sign)
{
	int		count;
	size_t	len;
	char	*str;

	count = 0;
	if (sign == '-')
		count += write(1, "-", 1);
	if (count == -1)
		return (-1);
	str = itoa_ull_prt(ull, base, sign);
	if (!str)
		return (-1);
	len = numlen_prt(ull, base);
	if (write(1, str, len) == -1)
	{
		free(str);
		return (-1);
	}
	count += len;
	free(str);
	return (count);
}

int	minus_flag_prt(int n)
{
	char				sign;
	unsigned long long	ull;

	sign = '+';
	if (n < 0)
	{
		sign = '-';
		ull = (unsigned long long)(-(long long)n);
	}
	else
		ull = n;
	return (putnbr_prt(ull, 10, sign));
}

int	handle_ptr_prt(unsigned long long ull)
{
	int	count;

	count = 0;
	if (ull == 0)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	count += write(1, "0x", 2);
	return (putnbr_prt(ull, 16, 'p') + count);
}
