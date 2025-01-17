/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:41:30 by otaniyuhi         #+#    #+#             */
/*   Updated: 2025/01/12 09:38:14 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_prt(int i)
{
	char	c;

	c = (char)i;
	return (write(1, &c, 1));
}

int	ft_putstr_prt(char *str)
{
	int	count;
	int	err;

	count = 0;
	if (!str)
		str = "(null)";
	while (str[count])
	{
		err = write(1, &str[count], 1);
		if (count == INT_MAX || err == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	identify_type(char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar_prt(va_arg(ap, int));
	else if (c == 's')
		count += ft_putstr_prt(va_arg(ap, char *));
	else if (c == 'p')
		count += handle_ptr_prt(va_arg(ap, unsigned long long));
	else if (c == 'd' || c == 'i')
		count += minus_flag_prt(va_arg(ap, int));
	else if (c == 'u')
		count += putnbr_prt(va_arg(ap, unsigned int), 10, '+');
	else if (c == 'x')
		count += putnbr_prt(va_arg(ap, unsigned int), 16, '+');
	else if (c == 'X')
		count += putnbr_prt(va_arg(ap, unsigned int), 16, 'X');
	else if (c == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		tmp;
	int		i;

	count = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		tmp = 0;
		if (format[i] == '%' && format[i + 1])
			tmp += identify_type(format[++i], ap);
		else if (!(format[i] == '%' && format[i + 1] == '\0'))
			tmp += write(1, &format[i], 1);
		if (tmp == -1 || count > INT_MAX - tmp)
		{
			va_end(ap);
			return (-1);
		}
		count += tmp;
		i++;
	}
	va_end(ap);
	return (count);
}

#include <stdio.h>

int	main(void)
{
	char	*null_str;
	int		x;

	int ret_printf, ret_ft_printf;
	//
	// Test 1: Simple string
	printf("Test 1: Simple String\n");
	ret_ft_printf = ft_printf("ft_printf: Test 1: Hello, World!\n");
	ret_printf = printf("printf:    Test 1: Hello, World!\n");
	printf("Return ft_printf: %d\n", ret_ft_printf);
	printf("Return printf:    %d\n\n", ret_printf);
	//
	// Test 2: Characters
	printf("Test 2: Characters\n");
	ret_ft_printf = ft_printf("ft_printf: Test 2: Characters: %c %c %c\n", 'A',
			'b', '3');
	ret_printf = printf("printf:    Test 2: Characters: %c %c %c\n", 'A', 'b',
			'3');
	printf("Return ft_printf: %d\n", ret_ft_printf);
	printf("Return printf:    %d\n\n", ret_printf);
	//
	// Test 3: Strings
	printf("Test 3: Strings\n");
	null_str = NULL;
	ret_ft_printf = ft_printf("ft_printf: Test 3: Strings: %s %s %s\n", "Hello",
			"ft_printf", null_str);
	ret_printf = printf("printf:    Test 3: Strings: %s %s %s\n", "Hello",
			"ft_printf", null_str);
	printf("Return ft_printf: %d\n", ret_ft_printf);
	printf("Return printf:    %d\n\n", ret_printf);
	//
	// Test 4: Pointers
	printf("Test 4: Pointers\n");
	x = 42;
	ret_ft_printf = ft_printf("ft_printf: Test 4: Pointers: %p %p %p\n", &x,
			NULL, (void *)0x12345678);
	ret_printf = printf("printf:    Test 4: Pointers: %p %p %p\n", &x, NULL,
			(void *)0x12345678);
	printf("Return ft_printf: %d\n", ret_ft_printf);
	printf("Return printf:    %d\n\n", ret_printf);
	//
	// Test 5: Integers
	printf("Test 5: Integers\n");
	ret_ft_printf = ft_printf("ft_printf: Test 5: Integers: %d %i %d\n", 0, -42,
			2147483647);
	ret_printf = printf("printf:    Test 5: Integers: %d %i %d\n", 0, -42,
			2147483647);
	printf("Return ft_printf: %d\n", ret_ft_printf);
	printf("Return printf:    %d\n\n", ret_printf);
	//
	// Test 6: Unsigned Integers
	printf("Test 6: Unsigned Integers\n");
	ret_ft_printf = ft_printf("ft_printf: Test 6: Unsigned: %u %u %u\n", 0,
			4294967295U, 123456789);
	ret_printf = printf("printf:    Test 6: Unsigned: %u %u %u\n", 0,
			4294967295U, 123456789);
	printf("Return ft_printf: %d\n", ret_ft_printf);
	printf("Return printf:    %d\n\n", ret_printf);
	//
	// Test 7: Hexadecimal
	printf("Test 7: Hexadecimal\n");
	ret_ft_printf = ft_printf("ft_printf: Test 7: Hexadecimal: %x %X %x\n", 255,
			255, 0);
	ret_printf = printf("printf:    Test 7: Hexadecimal: %x %X %x\n", 255, 255,
			0);
	printf("Return ft_printf: %d\n", ret_ft_printf);
	printf("Return printf:    %d\n\n", ret_printf);
	//
	// Test 8: Percent Sign
	printf("Test 8: Percent Sign\n");
	ret_ft_printf = ft_printf("ft_printf: Test 8: Percent: %% %% %%\n");
	ret_printf = printf("printf:    Test 8: Percent: %% %% %%\n");
	printf("Return ft_printf: %d\n", ret_ft_printf);
	printf("Return printf:    %d\n\n", ret_printf);
	return (0);
}
