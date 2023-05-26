/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerisen <szerisen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:44:35 by szerisen          #+#    #+#             */
/*   Updated: 2023/03/25 15:54:31 by szerisen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pointer(unsigned long long n, char format)
{
	int	res;
	int	reminder;

	res = 0;
	if (n > 15)
		res += ft_pointer(n / 16, format);
	reminder = n % 16;
	if (reminder >= 0 && reminder <= 9)
		res += ft_putchar(reminder + 48);
	else if (reminder > 9 && reminder < 16)
	{
		if (format == 'X')
			res += ft_putchar (reminder + 'A' - 10);
		else
		res += ft_putchar (reminder + 'a' - 10);
	}	
	return (res);
}

static int	get_var_type_result(char *var, va_list a_lst)
{
	if (*var == 'c')
		return (ft_putchar(va_arg(a_lst, int)));
	if (*var == 's')
		return (ft_putstr(va_arg(a_lst, char *)));
	if (*var == 'p')
	{
		ft_putstr("0x");
		return (ft_pointer(va_arg(a_lst, unsigned long long), (char)*var) + 2);
	}
	if (*var == 'd' || *var == 'i')
		return (ft_putnbr(va_arg(a_lst, int)));
	if (*var == 'u')
		return (ft_putnbr(va_arg(a_lst, unsigned int)));
	if (*var == 'x' || *var == 'X')
		return (ft_pointer(va_arg(a_lst, unsigned int), (char)*var));
	if (*var == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *x, ...)
{
	int		result;
	va_list	a_lst;

	va_start(a_lst, x);
	result = 0;
	while (*x)
	{
		if (*(x) == '%')
		{
			x++;
			result += get_var_type_result((char *)x, a_lst);
		}
		else
			result += ft_putchar(*x);
		x++;
	}
	va_end(a_lst);
	return (result);
}
